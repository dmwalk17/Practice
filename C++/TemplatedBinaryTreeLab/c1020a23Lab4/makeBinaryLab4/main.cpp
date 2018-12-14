/* File: main.cpp *
 * Author: Donna Walker
 * Description: Defines and implements a fitness tracker. Stores participants 
 * in a binary file and reads them into a binary tree. Allows the user to add 
 * and delete participants, add activities to existing users, calculate the total 
 * number of miles all participants have gone, print the participants
 * in a specified order, and save the participants back to a binary file when done. 
 * 
 */

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "activity.h"
#include "participant.h"
#include "node.h"
#include "binaryTree.h"
#include "position.h"
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::cerr;
using std::vector;
using std::ios;
using std::ofstream;
using std::setprecision;
using std:: fixed;
using std::left;
using std::right;
using std::setfill;
using std::setw;

//prototypes
void printMenu();
void deleteParticipant(BinaryTree<Participant>& b);
void addParticipant(BinaryTree<Participant>& b);
void addActivity(BinaryTree<Participant>& b);
void formatName(char []);
void makeBinaryFile();//commented out, original code to write the binary file, not for normal program use

int main(int argc, char **argv){
    //makeBinaryFile(); //original read
    
    BinaryTree<Participant> b;
    Participant p;
    ifstream input;
    ofstream output;
    string userInput;
    
    input.open( "fitnesstracker.bin", ios::binary);

    while(input.read((char*)&p, sizeof(Participant))){
        
        b.insert(p);
    }
    input.close(); 
    cout << "Welcome to FitnessTracker 2.0!" << endl;    
    
    do{
        printMenu();
        cin >> userInput;
    
        if(userInput == "1"){//deleting participant
            deleteParticipant(b);
        
        }
        else if(userInput == "2"){//adding participant
            addParticipant(b);
        }
        else if(userInput == "3"){//adding activity
            addActivity(b);
        }
        else if(userInput == "4"){//calculating group's total miles through recursive function
            double groupTotalMiles= 0; 
            b.inorderTraverseAndAdd(b.root(), groupTotalMiles);
            cout << "Total miles walked by *everyone* = " << fixed 
                 << setprecision(2)<< groupTotalMiles << "!" << endl << endl;
            
        }
        else if(userInput == "5"){//preorder print participants
            if(!b.empty()){//prints headers if there are node(s)
                cout << setw(22) << left << "First Name" << setw(22) << left << "Last Name" << setw(12) << right << "Total Miles" << endl;
                cout << setfill('-') << setw(58) <<'-' << setfill(' ') << endl;
            }
            b.traverseAndPrint(b.root(), PREORDER);
            cout << endl;
        }
        else if(userInput != "6"){//some error handling, made userInput a string to make this more robust
            cout << "Invalid entry. Please enter a valid option." << endl << endl;
        }
    
    }while(userInput != "6");
    
        output.open("fitnesstracker.bin", ios::binary); //binary file of Participants
        b.preorderTraverseAndWrite(output, b.root());
        output.close();
        cout << endl << "Thank you for using Fitness Tracker! 2.0, updates will be out soon!" << endl; //close message
    
    return 0;
}

/* printMenu: prints the main menu of the program to get the user's choices
 * Parameters: none
 * Returns: none
 */ 
void printMenu(){
    cout << "1 Remove participant" << endl
         << "2 Add participant"    << endl
         << "3 Add activity"       << endl
         << "4 Calculate total miles walked" << endl
         << "5 Pre-order print"    << endl
         << "6 Exit and save"      << endl
         <<"Option>";
}

/* deleteParticipant: Removes a participant from the data. 
 *   Called by menu choice 1.
 * Parameter: b - binary tree called by reference
 * Precondition: a binary tree of Participants must be instantiated
 * Return: none, updated tree by reference
 */ 
void deleteParticipant(BinaryTree<Participant>& b){
    char tempLast[21];
    Participant p;
    tempLast[0] = '\0';
    cout << "Last Name: ";
    cin >> tempLast;
    formatName(tempLast);
    p = Participant(tempLast);
    Position<Participant> found = b.find(p);

    if(found.getItem() == p){
        cout << "Participant " << found.getItem().getFirstName() << " " 
             << found.getItem().getLastName() << ", " << setprecision(2) 
             << found.getItem().getTotalMiles() << " total miles walked removed." << endl << endl;
        b.erase(found);
    }
    else{
        cout << "Participant Not found" << endl;
    }
}

/* addParticipant: adds a participant to the data
 *      called by Menu choice 2
 *  Parameter: b - binary tree of Participants called by reference
 *  Precondition: a binary tree of Participants should be instantiated
 *  Returns: none, tree updated by reference
 */ 
void addParticipant(BinaryTree<Participant>& b){
    char tempLast[21];
    tempLast[0] = '\0';
    char tempFirst[21];
    tempFirst[0] = '\0';
    double tempHeight = 0;
    Participant p;
    
    cout << "Last name: ";
    cin >>tempLast;
    formatName(tempLast);
    p = Participant(tempLast);
    Position<Participant> found = b.find(p);
    if (found.getItem() == p){
        cout << found.getItem().getLastName() << " is already a Participant" << endl << endl;
    }
    else{
        cout << "First Name: "; 
        cin >> tempFirst;
        formatName(tempFirst);
        cout << "Height in inches: ";
        cin >> tempHeight;
        p.clear();
        p.setLastName(tempLast);
        p.setFirstName(tempFirst);
        p.setHeight(tempHeight);
        p.setNumActivities(0);
        b.insert(p);

    }
}

/* addActivity: adds an activity to an existing participant
 *   has error handling if the participant does not exist.
 *   Called by menu option 3.
 * Parameter: b - binary tree of Participant data by reference
 * Precondition: a binary tree of Participant data is instantiated.
 * Returns: none, updated tree by reference
 */ 
void addActivity(BinaryTree<Participant>& b){
    char tempLast[21];
    tempLast[0] = '\0';
    Participant p;
    int tempAC, tempMins;                
    Activity act;
    
    cout << "Last name: ";
    cin >>tempLast;
    formatName(tempLast);

    p = Participant(tempLast);
    Position<Participant> found = b.find(p); 
    if(found.getItem() == p){
        cout << "Activity: ";
        cin >> tempAC;
        cout << "Minutes: ";
        cin >> tempMins;

        p.clear(); //clears the phony participant used to find node
        p = found.getItem(); //assigns data from found node to participant
        b.erase(found); //maybe not most efficient way to do this, but 
        act.setActivityCode(tempAC);
        act.setMinsDone(tempMins);
        act.setMilesEquivalent(p.getHeight());
        p.setDailyActivity(act);
        b.insert(p);
        cout << "Added " << p.getFirstName() << " " << p.getLastName() 
             << ", " << ACTIVITIES[act.getActivityCode()] << ", " 
             << act.getMinsDone() << " minutes = " << fixed << setprecision(4) << act.getMilesEquivalent()
             << " miles" << endl << endl;
    }
    else {
        cout << "Participant Not found" << endl;
                 
    }
}
/* formatName: Utility function that places names by reference into proper
 *  format of: "Cllllll" 
 * Parameter: tempName - the name that needs to be formatted
 * Return: none, formatted name variable by reference
 */ 
void formatName(char tempName[]){
    tempName[0] = toupper(tempName[0]);
    int sz = strlen(tempName);
    for(int i = 1; i < sz; i++){
        tempName[i] = tolower(tempName[i]);
    }        
}
/* makeBinaryFile: Function that reads a given text file of info into 
 *  a Participant variable and writes the Participants into a binary file
 * Parameter: none
 * Precondition: Needs file 'FitnessTracking.txt' in the debugger file with 
 *   Participant object data in it.
 * Postcondition: "fitnesstracker.bin" data must be read in by individual Participants 
 * using ifstream as ios::binary
 * Returns: none
 */ 
void makeBinaryFile(){
    
    string line;
    vector<string> words;
    vector<string>::iterator itr;
    ifstream input;
    ofstream output;
    string delimiter = ",";
    size_t pos = 0;
    string token;
    int i = 0; 

    Participant p;
    Activity a;
    int count = 0;
    int tempAC = 0, tempMins = 0, numActives = 0;
    
    input.open("FitnessTracking.txt");
    output.open("fitnesstracker.bin", ios::binary);
    if(!input){
    cerr << "Unable to open file FitnessTracking.txt" << endl;
    exit(1);
}

    while(getline(input,line)){
        //cout << line << endl;
        line += ",";
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            words.push_back(token);
            cout << "token: " <<token << endl;
            line.erase(0, pos + delimiter.length());
        }
        i=0;
        int sz = words.size();
        p.setFirstName(const_cast<char*>(words[i].c_str())); i++;
        printf("fn %s\n", p.getFirstName());
        p.setLastName(const_cast<char*>(words[i].c_str())); i++;
        printf("ls %s\n",p.getLastName());
        p.setHeight(stod(words[i])); i++;
        cout << "height: " << p.getHeight() << endl;
        p.setNumActivities(numActives);
        //Start here processing activities, using i and the size of the vector to limit 
        //idea, use iterator starting on begin+3 and going to end alternating adding to activity code and time until iterator stops
        for(int idx = 0, i=3;i < sz; i++, idx++){
            cout << "words[i] start activity: " << words[i]; 
            tempAC = stoi(words[i]);i++;
            cout << "AC: " << tempAC << endl;
            a.setActivityCode(tempAC);
            cout << "Activity: " << a.getActivityCode() << endl;
            tempMins = stoi(words[i]);
            cout << "mins done" << tempMins << endl;
            a.setMinsDone(tempMins);
            cout << "Mins Done: " << a.getMinsDone() << endl;
            a.setMilesEquivalent(p.getHeight());
            cout << "miles equivalent: " << a.getMilesEquivalent() << endl;
            p.setDailyActivity(a);
            cout << "numActivities in class: " << p.getNumActivities() << endl;
            a.clear();
        }
        cout << "Participant:" << p << endl;
        cout << "Total Miles" << p.getTotalMiles() << endl;
        if(output.is_open()){
            output.write((char*)&p, sizeof(Participant));
        
        } 
        count++; 
        words.clear();
        p.clear();
   
    }
    cout << "count: " << count << endl;
    input.close();
    output.close();

}
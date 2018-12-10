
#include <string>
#include <iostream>
#include <fstream>
#include "activity.h"
#include "participant.h"
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::fstream;
using std::cerr;
using std::vector;
using std::ios;


int main(int argc, char **argv){

string line;
vector<string> words;
vector<string>::iterator itr;

ifstream input;
fstream output;
output.open("fitnesstracker.bin", ios::out | ios::out | ios::binary);
string delimiter = ",";
size_t pos = 0;
string token;
int i = 0;
string userInput;
vector<Participant> us;
Participant p;
Activity a;
int numActives;
int tempAC, tempMins;
input.open("FitnessTracking.txt");
if(!input){
    cerr << "Unable to open file FitnessTracking.txt" << endl;
    exit(1);
}

while(getline(input,line)){
    cout << line << endl;
line += ",";
while ((pos = line.find(delimiter)) != std::string::npos) {
    token = line.substr(0, pos);
    words.push_back(token);
    cout << "token: " <<token << endl;
    line.erase(0, pos + delimiter.length());
}
i=0;
numActives = 0;
int sz = words.size();
p.setFirstName(const_cast<char*>(words[i].c_str())); i++;
printf("fn %s\n", p.getFirstName());
p.setLastName(const_cast<char*>(words[i].c_str())); i++;
printf("ls %s\n",p.getLastName());
p.setHeight(stoi(words[i])); i++;
cout << "height: " << p.getHeight() << endl;
p.setNumActivities(numActives);
//Start here processing activities, figure out how to control iterator for varying number of activities
//idea, use iterator starting on begin+3 and going to end alternating adding to activity code and time until iterator stops
for(;i < sz; i++){
    tempAC = stoi(words[i]);
    cout << "AC: " << tempAC << endl;

    a.setActivityCode(tempAC);i++;
    cout << "Activity: " << a.getActivityCode() << endl;
    tempMins = stoi(words[i]);
    cout << "second val " << tempMins << endl;
    a.setMinsDone(tempMins);
    cout << "Mins Done: " << a.getMinsDone() << endl;
    a.setMilesEquivalent(p.getHeight());
    cout << "miles equivalent: " << a.getMilesEquivalent() << endl;
    p.setDailyActivity(a);
    cout << "numActives: " << numActives;
    numActives +=1;
    p.setNumActivities(numActives);
}
    
    p.getTotalMiles();
    cout << "Num Actives" << p.getNumActivities() << endl;
    if(output.is_open()){
        output.write((char*)&p, sizeof(Participant));
        us.push_back(p);
        p.printParticipant();
    } 
   words.clear();
   p.clear();
   numActives = 0;
}
input.close();
output.close();

input.open( "fitnesstracker.bin", ios::binary);
for( int i = 0; i  < 5 ; i++ ) {
    //read p
     input.read((char*)&p, sizeof(Participant));
    
    cout << p << endl;
}

exit(0);
}
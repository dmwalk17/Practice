/* File: main.cpp *
 * Author: Donna Walker
 * Description: This application is a system that tallies race data from computer 
 * generated sensors. (CSV file data) It  displays the results and detects the possibility of 
 * cheating from racers who miss a sensor, do not complete the race,  have a mph
 * speed greater than 14 mph between two sensors or ending mileage doesn't match race mileage.
 */
#include "TimeDateStamp.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include "Race.h"
#include "Racer.h"
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;
using std::ifstream;
using std::stringstream;
using std::left;

bool getData(Race &race);
bool emptyFile(ifstream& in);
void printHeader();
void printResults(Race &race);

int main(int argc, char **argv)
{
    //Both getData and results need access to Race to use Racer array data
    Race race;
    bool racing;
    racing = getData(race); //read in file results
    if(racing){
        //prints results
        printHeader();
        printResults(race);
        
    }
    else{//no data
        cout << "Please put a file with valid race data in the debug folder of the application." << endl;
    }
	return 0;
}
/* getData: reads the Race's racers from a file and instantiates them 
 * Parameters: race - A Race is sent by reference
 * Precondition: Race has been instantiated
 * Return: none
 */
bool getData(Race &race){
    //variable declaration for processing file data
    Racer currentRacer;
    Sensor s;
    vector<string> tokens;
    vector<string>::iterator it;
    string temp, tokenString;
    int numSensors; 
    string userInput; //"racedata.txt" "bm2016.txt";used to ensure could get results of Boston Marathon data
    bool firstRun = true;//used to collect race data

    cout << "Enter your race text file: ";
    cin >> userInput;
    //reads in data from file
    ifstream in (userInput);
    
    if(in.is_open()){
        if(emptyFile(in)){
            cout << "The input file is empty." << endl;
            exit(1);
        }
        while(getline(in,temp)){
            temp += ";";//adds ';' to tend of incoming line of data to help get last time
            stringstream tokenizer(temp); //using stringstream for second tokenization by ':'
            //tokenizes by semicolons storing tokens in vector
            while(getline(tokenizer, tokenString,';')){
                tokens.push_back(tokenString);                
            }
            //during first line that contains race data
            if(firstRun){
                string timeRace = tokens[0];
                TimeDateStamp raceTime = TimeDateStamp(timeRace);
                int raceSensors = stoi(tokens[1]);
                double distance = stod(tokens[2]);
                race.setStartTime(raceTime);
                race.setRaceSensors(raceSensors);
                race.setRaceDistance(distance);
                tokens.clear();
                firstRun = false;//ensures the rest of the data goes into racers
            }
            else{
                //loads racer data
                Racer currentRacer;
                int i = 0;
                stringstream tokenizer(temp);
                //tokenizes by ';' into sensor data
                while(!tokenizer.eof()){
                    getline(tokenizer,tokenString,';');
                    tokens.push_back(tokenString);
                    i++;
                }
                currentRacer.setName(tokens[0]);
                currentRacer.setRacerNum(stoi(tokens[1]));
                //assesses individual number of sensors
                numSensors = (tokens.size() - 2)/6;
                //uses itr to load data into appropriate number of sensors, and i to progress thru data
                i= 2;
                for(int itr = 0; itr < numSensors; itr++){
                    s.setSensorNum(stoi(tokens[i])); i++; 
                    s.setMileMarker(stod(tokens[i])); i++; 
                    TimeDateStamp t = TimeDateStamp(tokens[i]); i++; 
                    s.setTime(t);
                    currentRacer.setRaceData(s);
                    s = Sensor();//clears sensor after loading sensor into racer's data
                }
                //calculates total time
                //TimeDateStamp total = currentRacer.getTotalTime(); 
                currentRacer.setTotalTime();
                
                //determines if runner possibly cheated
                currentRacer.setCheater(race.getRaceDistance());
                //clears tokenizer for next run
                tokens.clear();
                race.setRacer(currentRacer);
                currentRacer = Racer();// clears racer for next runner
               
            }
            
        }
        return true;
    }
    
    return false;
}
/* isEmpty: checks to see if the file has content in it
 * Parameter: input stream by reference 
 * Returns: bool indicating true if file is empty
 */
bool emptyFile(ifstream& in){
    return in.peek() == ifstream::traits_type::eof();
}    

/* print header: prints formatted header for results table 
 * Parameters: none
 * Return: none
 */
void printHeader(){
    cout << setfill(' ') << setw(35) << left << "Name" << setw(8) << "Number" << setw(7) << " " << setw(9) << left << "Time" << endl;
    cout << setfill('-') << setw(62) << "-" << endl;
}

/* printResults: prints racer data sorted in descending order 
 * Parameters: race - Race is sent by reference to access runners
 * Precondition: Race has been instantiated and << overwritten for Racer
 *   and operator< is overwritten to implement sort
 * Return: none
 */
void printResults(Race &race){
    vector<Racer> results = race.getRacers();
    sort(results.begin(), results.end());
    int sz = results.size();
    for(int i = 0; i < sz; i++){
        cout << results[i];
    }
    
}

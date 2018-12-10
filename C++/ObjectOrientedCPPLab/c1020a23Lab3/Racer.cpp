/* File: Racer.cpp *
 * Author: Donna Walker
 * Description: Defines Racer class. Formal function headers are in the header file
 */
#include <iostream>
#include <vector>
#include <iomanip>
#include "Racer.h"
#include "Sensor.h"
#include "TimeDateStamp.h"
using std::vector;
using std::ostream;
using std::setw;
using std::fixed;
using std::setfill;
using std::left;
using std::right;
using std::endl;
using std::cout;

/* No-argument constructor: fills in private fields with default data
 */ 
Racer::Racer()
{
    name = "";
    racerNum = 0;
    vector<Sensor> raceData;
    totalTime = TimeDateStamp(0,0,0,0); 
    cheater = false;
}
/* total time accessor
 *  NOTE: setTotalTime must used first to dynamically create total time
 */ 
 TimeDateStamp Racer::getTotalTime(){
    return totalTime;
}

 /*mutator for total time
  *NOTE: Parameters: None (Dynamically set based on data)
  */ 
void Racer::setTotalTime(){
    TimeDateStamp firstTime = raceData.front().getTime();
    TimeDateStamp lastTime = raceData.back().getTime();
    TimeDateStamp t = lastTime - firstTime;
    totalTime = t;
}
// Except total time, variable accessor methods are done inline in header

// mutator for name
void Racer::setName(string name){
        this->name = name;
}

// Sets racer number
void Racer::setRacerNum(int num){
    racerNum = num;
}

// adds a sensor to vector of sensors
void Racer::setRaceData(Sensor const &s){
 raceData.push_back(s);
}
    
// Overloaded setter of take in entire vector of sensors
void Racer::setRaceData(vector<Sensor> const & d){
    raceData = d;
}

// overloaded operator < to assist with sorting runners finish time (fastest first)
bool operator<(const Racer& r1, const Racer& r2){
    return r1.totalTime < r2.totalTime;
}

// Checks to determine if runner is suspected of cheating or not finishing the race
void Racer::setCheater(double raceDistance){
    if(this->skippedSensor() || this->wasSpeeding() || this->raceData.back().getMileMarker() != raceDistance){
        cheater = true;
    }
    else{
        cheater = false;
    }
}

/*checks to ensure all sensors are contiguous
 * Does not verify if racer completed the last sensor of the race
 */ 
bool Racer::skippedSensor(){
    vector<Sensor>::iterator it, it_next;
    for(it = raceData.begin(), it_next = ++raceData.begin();  it_next != raceData.end(); it++, it_next++){
            if ((*it).getSensorNum() + 1 != (*it_next).getSensorNum()){
                return true;
            }
        
    }
    return false;
}

//verifies if a racer had any leg of the race with an average speed > 14 mph
bool Racer::wasSpeeding(){
    vector<Sensor>::iterator it, it_next;
    for(it = raceData.begin(), it_next = ++raceData.begin();  it_next != raceData.end(); it++, it_next++){
            double tempHours = convertToMills((*it_next).getTime() - (*it).getTime())/3600000.0;
            double curMiles = (*it_next).getMileMarker() - (*it).getMileMarker(); 
            if ((curMiles/tempHours) > 14){
                return true;
            }
        
    }
    return false;
}

// operator<< overloaded for Racer object, adds * on front if suspected of cheating
ostream& operator<<( ostream& outStream, const Racer& r ) {
   outStream << fixed << setfill(' ') << setw(1);
    if(r.cheater){
        outStream << setw(1)  << "*"  << setw(31) << left << r.name;
    }
    else{
        outStream << setw(32) << left << r.name;
        }
    outStream << setw(8) << right << r.racerNum 
        << setw(10) << setfill(' ') << " "<< setw(12) << r.totalTime << endl; 
    return outStream;
}


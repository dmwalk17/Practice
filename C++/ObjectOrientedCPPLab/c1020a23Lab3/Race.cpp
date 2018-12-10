/* File: Race.cpp *
 * Author: Donna Walker
 * Description: Implements Race class. Detailed comment headers are in header file 
 */
#include "Race.h"

/* No argument constructor */
Race::Race()
{
    startTime = TimeDateStamp();
    raceSensors = 0;
    raceDistance = 0;
}
// 3-arg constructor that takes in all data except racers
Race::Race(TimeDateStamp t, int s, double d){
    startTime = t;
    raceSensors = s;
    raceDistance = d;
}

//copy constructor that loads all variables of race
Race::Race(Race const &r){
    startTime = r.startTime;
    raceSensors = r.raceSensors;
    raceDistance = r.raceDistance;
    racers = r.racers;
}

//mutator method for start time
void Race::setStartTime(TimeDateStamp const & st){
    startTime = st;
}

//overloaded mutator for start time
void Race::setStartTime(int h,int min,int s,int mils){
    startTime.setHours(h);
    startTime.setMins(min);
    startTime.setSecs(s);
    startTime.setMillis(mils);
}

//mutator for race sensors
void Race::setRaceSensors(int s){
    raceSensors = s;
}

//mutator for race distance
void Race::setRaceDistance(double d){
    raceDistance = d;
}

//mutator that adds a racer to the race
void Race::setRacer(Racer r){
    racers.push_back(r);
}
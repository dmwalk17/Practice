/* File: Race.h *
 * Author: Donna Walker
 * Description: Defines Race class including start time, number of sensors expected, 
 * raceDistance, and a vector of race's racers.
 */ 

#ifndef RACE_H
#define RACE_H
#include "TimeDateStamp.h"
#include "Racer.h"
class Race
{
public:
    /*No argument constructor
     */ 
    Race(); 
    /*3-argument constructor
     * Parameters:
     *  t- start time of race
     *  s - number of sensors in race
     *  d - distance of the race (used to validate runner completed race)
     * Precondition: hours, mins, secs, and millis has been converted to timedatestamp
     */ 
    Race(TimeDateStamp t, int s, double d); //CHECK THE VECTOR OF racers and how instantiated !!!!!!!!!
    
    /*copy constructor
     * Parameter: r - a race to copy
     */ 
    Race(Race const &r); 
    
    /*inline destructor
     */ 
    ~Race() { } 
    
    //getters and setters for private variables
    
    /*getStartTime: startTime accessor method
     * Parameter: none
     * Returns: Start Time as a time date stamp
     */ 
    TimeDateStamp getStartTime() const { return startTime; }
    
    /*setStartTime: mutator for startTime (overloaded)
     * Parameter: timedate stamp with race start time
     * Returns: none
     */ 
    void setStartTime(TimeDateStamp const &);
 
    /*setStartTime: overloaded mutator for startTime
     * Parameters: h-hours, min-mins, s-secs, mil-millis
     * Return: none
     */ 
    void setStartTime(int,int,int,int);
    
    /*getRaceSensors: accessor method for raceSensors
     * Parameter: none
     * Return: int - number of sensors in race 
     * (Could be used for further validation of racers)
     */ 
    int getRaceSensors() const { return raceSensors; }
    
    /*setRaceSensors: mutator method for race sensors
     * Parameter: s - number of sensors in race
     * Return: none
     */ 
    void setRaceSensors(int);
    
    /*getRaceDistance: accessor method for race distance
     *Parameter: none
     *Return: double that is distance of race
     */ 
    double getRaceDistance() const { return raceDistance; }
    
    /*setRaceDistance: set method for race distance
     * Parameter - d distance of race
     * Return: none
     */ 
    void setRaceDistance(double);
    
    /*setRacer: added a single racer to racers 
     * Parameter: r - a racer
     * Return: none
     */ 
    void setRacer(Racer r);
    
    /*getRacers: accesses all of the racers in the race 
     *Parameter: none
     *Returns a vector with all the racers in the race
     */ 
    vector<Racer> getRacers() const { return racers; } 
    
    /*getRacer: separate accessor method to return one racer by index
     * Parameter: i - the index of the racer wanted
     * Returns: one racer
     */ 
    Racer getRacer(int i) const { return racers[i]; }//gets a designated racer by index

private:
    TimeDateStamp startTime;
    int raceSensors;
    double raceDistance;
    vector<Racer> racers;
};

#endif // 

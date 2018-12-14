/* File: Racer.h *
 * Author: Donna Walker
 * Description: Defines Racer class. Private data accessors are implemented inline. 
 */   
#ifndef RACER_H
#define RACER_H
#include <string>
#include <vector>
#include "Sensor.h"
#include "TimeDateStamp.h"
using std::string;
using std::vector;
class Racer
{
public:
    Racer();//no argument constructor
    ~Racer() {} //destructor
    //getters and setters for private variables
    /*getName: accessor method for name variable
     * Parameter: none
     * Returns: name variable
     */ 
    string getName() const { return name; }
    
    /* setName: sets name of racer
    * Parameter name - name of runner
    * return: none
    */ 
    void setName(string );
    
    /*getRacerNum: accessor method for racerNum
     * Parameter: none
     * Returns: int for racerNum
     */ 
    int getRacerNum() const {return racerNum; }
    
    /* setRacerNum: sets racer number
     * Parameter: num - racer's number
     * Return: none
    */ 
    void setRacerNum(int );
    
    /* getRaceData: overloaded method to get a vector of runner's sensors
     * Parameter: None
     * Return: Vector of racerData Sensors
     */ 
    vector<Sensor> getRaceData() const { return raceData; } //getter for all sensors of racer's data
    
    /* setRaceData: mutator method for adding a single sensor to raceData vector
     * Parameter: Sensor of data
     * Returns: None
     */ 
    void setRaceData(Sensor const &); //adds a sensor to racer data
    
    /* setRaceData: overloaded method to allow entire vector of sensors to be added at once
     * Parameter: a vector of sensors
     * Returns: None
     */ 
    void setRaceData(vector<Sensor> const &); //allows for group of sensors to be copied
    
    /* getRaceData: overloaded method to access one particular sensor based on index
     * Parameter: i - index of sensor to access
     * Returns: a sensor of data
     */ 
    Sensor getRaceData(int i){return raceData[i];} //allows to get a specific sensor based on index
    

    /*setTotalTime: sets total race time for this racer
     * Parameters: None (Dynamically set based on data)
     * Precondition: raceData sensors must be loaded prior to running
     * return: none
     */ 
    void setTotalTime(); //stores total time
    
    /* getTotalTime: calculates runner's time to complete the race
     * Precondition: operator - (for TDS) has been overloaded to subtract TimeDateStamps
     *  Also, setTotalTime must used first to dynamically create total time
     * Returns: total race time for racer
     */
    TimeDateStamp getTotalTime(); //calculates total time
   
    /* getCheater - accesses the runner's possible cheater status
     * Parameter: None
     * Return: bool that returns true if possible cheater
     */ 
    bool getCheater() const { return cheater; }

    /*setCheater - runs utility methods that calculate if runner is possible cheater
     * Parameter: double that represents the stored distance of race from Race class
     * Precondition: Requires skippedSensor and wasSpeeding utility methods to work.
     *  Also, requires that Race has a valid distance to ensure runner finished.
     * Return: None
     */ 
    void setCheater(double); 
     
     /*operator<: Used to sort racers based on TotalTime in ascending order
      * Parameters: r1 - a racer
      *             r1 - another racer
      * Returns: returns true if first racer's time is less than second racer
      */ 
    friend bool operator<(const Racer&, const Racer&); //used to sort racers based on totalTime
    
    /*operator<<: used to print out a racer in format for result report
     * Parameters: 
     *   outStream -the output stream
     *    r - the Racer 
     * Return: the output stream by reference
     */
    friend std::ostream& operator<<( std::ostream& , const Racer&  ); //does formatted print of Racer for result report

private:
    string name;
    int racerNum;
    vector<Sensor> raceData;
    TimeDateStamp totalTime;
    bool cheater;
    
    /*skippedSensor - utility method checks to ensure all sensors are contiguous
     * Parameter: none
     * Postcondition: Does not verify if racer completed the last sensor of the race
     * Returns: bool that is true if sensors are not contiguous 
     */ 
    bool skippedSensor(); //utility method used by setCheater
    
    /*wasSpeeding: utility method used by setCheater to determine if
     *  chater was >14 mph during any leg of the race
     * Parameter: none
     * Returns: bool that is true if racer was going too fast
     */ 
    bool wasSpeeding(); // utility method used by setCheater
};

#endif 

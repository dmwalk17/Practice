/* File: Sensor.h *
 * Author: Donna Walker
 * Description: Defines Sensor class. Stores data for each sensor the runner passes. Includes the sensor number, 
 * mile marker of the sensor and the runner's time.
 */

#ifndef SENSOR_H
#define SENSOR_H
#include "TimeDateStamp.h"
class Sensor
{
public:
    /*No argument constructor
     */ 
    Sensor(); 
    
    /*6-arg constructor
     * Parameters: sn - sensor number 
     * mm - mile marker
     *  h, min,sec, mil - #s to create TDS for sensor
     * Precondition: uses overloaded 4-arg TDS constructor
     */ 
    Sensor(int,double,int,int,int,int); 
    
    /*3-arg constructor
     * Parameters: sn - sensor number
     * mm - milemarker
     * t - a timedatestamp (runner's time)
     */ 
    Sensor(int,double,TimeDateStamp); 
    
    /*copy constructor
     * Parameter: s - a sensor
     */ 
    Sensor(Sensor const &s); 
    
    /*Destructor
     */ 
    ~Sensor() {} 
    
    //getters and setters for private variables
    /*getSensorNum: accessor for sensor number
     * Parameter: none
     * Return: a sensor number
     */ 
    int getSensorNum() const { return sensorNum; }
    /*getSensorNum: accessor for sensor number
     * Parameter: none
     * Return: num - a sensor number
     */ 
    void setSensorNum(int);
    
    /*getMileMarker: accessor for mile marker
     * Parameter: none
     * Return: mile marker
     */ 
    double getMileMarker() const { return mileMarker; }
    
    /*setMileMarker: mutator for milemarker
     * Parameter: mm - distance of sensor
     * Return: none
     */ 
    void setMileMarker(double);
    
    /*getTime: accessor for runner's time of sensor
     *Parameter: none
     *Return: a TDS with sensor's time of runner
     */ 
    TimeDateStamp getTime() const { return time; }
    
    /*setTime: overloaded method taking 4 args
     * Parameters: h, min, s, mil (parts of TDS)
     * Precondition: Requires 4-arg TDS constructor
     * Return: none
     */ 
    void setTime(int, int, int, int);

    /*setTime: overloaded method that takes a TDS to set time
     * Parameter: TDS with sensor's time
     * Return: none
     */ 
    void setTime(TimeDateStamp);
    
    /*setTime: overloaded method that takes a string of TDS
     * Parameter: t - takes string with '##:##:##:##' format
     * Precondition: Requires TDS constructor with string parameter
     * Return: none
     */ 
    void setTime(string);
                        
private:
int sensorNum;
double mileMarker;
TimeDateStamp time;    

};

#endif 

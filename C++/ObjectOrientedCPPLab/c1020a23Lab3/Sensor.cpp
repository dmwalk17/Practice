/* File: Sensor.cpp *
 * Author: Donna Walker
 * Description: Implements Sensor class. Stores data for each sensor 
 * the runner passes. Includes the sensor number, 
 * mile marker of the sensor and the runner's time.
 * Formal comment headers are in the sensor.h file. 
 */
#include "Sensor.h"

Sensor::Sensor()//no arg constructor
{
    sensorNum = 0;
    mileMarker = 0;
    time = TimeDateStamp(0,0,0,0);
}

//6-arg constructor
Sensor::Sensor(int sn,double mm,int h,int min,int sec,int mil){
    sensorNum = sn;
    mileMarker = mm;
    time = TimeDateStamp(h,min,sec,mil);
}

//3-arg constructor
Sensor::Sensor(int sn,double mm,TimeDateStamp t){
    sensorNum = sn;
    mileMarker = mm;
    time = t;        
}

//copy constructor
Sensor::Sensor(Sensor const &s){
    sensorNum = s.sensorNum;
    mileMarker = s.mileMarker;
    time = s.time;
}

//getters and setters for private variables
//getters are done inline in the h file

void Sensor::setSensorNum(int num){//mutator for sensor number
    sensorNum = num;
}

void Sensor::setMileMarker(double mm){//mutator for milemarker
    mileMarker = mm;
}

void Sensor::setTime(string t){//mutator for sensor time
    time = TimeDateStamp(t);
}

void Sensor::setTime(int h, int min, int sec, int mil){//overloaded mutator for time
    time = TimeDateStamp(h,min,sec,mil);
}

void Sensor::setTime(TimeDateStamp t){//overloaded mutator for time
    time = t;
}

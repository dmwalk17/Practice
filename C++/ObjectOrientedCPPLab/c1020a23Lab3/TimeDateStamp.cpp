/* File: TimeDateStamp.cpp *
 * Author: Donna Walker
 * Description:  Implements TimeDateStamp class, comment headers are in TimeDateStamp.h
 * TimeDateStamp(TDS)
 */
#include "TimeDateStamp.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using std::stringstream;
using std::string;
using std::vector;
using std::setfill;
using std::setw;

TimeDateStamp::TimeDateStamp() //no-arg constructor
{
    millis = 0;
    secs = 0;
    mins = 0;
    hours = 0;
}

TimeDateStamp::TimeDateStamp(int h, int min, int sec, int mil){ //4-arg constructor
    millis = mil;
    secs = sec;
    mins = min;
    hours = h; 
}

//Overloaded constructor that takes string and converts to TDS
TimeDateStamp::TimeDateStamp(string timeStamp){ 
    vector<string> tokens;
    string temp, tokenString;
    stringstream tokenizer(timeStamp);
            while(getline(tokenizer, tokenString,':')){
                tokens.push_back(tokenString);                
            }
           hours = stoi(tokens[0]); 
           mins = stoi(tokens[1]); 
           secs = stoi(tokens[2]); 
           millis = stoi(tokens[3]);
}


TimeDateStamp::TimeDateStamp(TimeDateStamp const &t){//copy constructor
    millis = t.millis;
    secs = t.secs;
    mins = t.mins;
    hours = t.hours;
}

//getters were done inline in header

void TimeDateStamp::setHours( int h ){//hours mutator
    hours = h;
}

void TimeDateStamp::setMins( int m){//mins mutator
    mins = m;
}

void TimeDateStamp::setSecs( int s){//secs mutator
    secs = s;
}
    
void TimeDateStamp::setMillis(int m){//millis mutator
    millis = m;
}

//Overloaded operator<<
std::ostream& operator<<( std::ostream& outStream, const TimeDateStamp& t ) { 
   outStream << std::fixed <<setfill('0')<<std::setw(2)
            << t.hours << ":" << setw(2) << t.mins << ":"<< setw(2) << t.secs
            << ":" << std::setw(3) << t.millis << setfill(' ');
    return outStream;
}

/*Overloaded operator- to assist with getting total time for each runner
 * REMINDER for me:
 *Could use this to do more validation of data, but we were assured that data
 * would be same day and valid data, so I didn't check for -1's
 */ 
TimeDateStamp operator-(TimeDateStamp const &d1, TimeDateStamp const &d2){
    TimeDateStamp diffTime;
    TimeDateStamp tempTime(d1);
    //Does "borrowing where needed upfront in each column
    //If millis needs a borrow
    if((d1.millis - d2.millis) < 0){//if can, borrows from secs
        if(d1.secs - d2.secs > 0){
            tempTime.millis +=1000;
            tempTime.secs -= 1;
        }    
        else if((d1.mins - d2.mins) > 0){//if not, then tries borrow from mins
             tempTime.mins -= 1;
             tempTime.secs += 59;
             tempTime.millis += 1000;
        } 
        else if((d1.hours - d2.hours) > 0){//if not, tries borrow from hours
            tempTime.hours -= 1;
            tempTime.mins += 59;
            tempTime.secs += 59;
            tempTime.millis += 1000;
        }
        else {
            diffTime.millis = -1; //could not borrow, second number is greater than first, error
            return diffTime;
        }
    }
    //then checks if secs needs a borrow
    if((tempTime.secs - d2.secs) < 0){
            if((tempTime.mins - d2.mins) > 0){//attempts to borrow from mins
                tempTime.mins -= 1;
                tempTime.secs += 60;
            } 
            else if((tempTime.hours - d2.hours) > 0){//if can't, attemps to borrow from hours
                tempTime.hours -= 1;
                tempTime.mins += 59;
                tempTime.secs += 60;
            }    
            else {
                diffTime.millis = -1;//could not successfully borrow, 2nd is larger, so error
                return diffTime;
            }
    }
    //then checks if mins needs a borrow
    if((tempTime.mins - d2.mins) < 0){
        if((tempTime.hours - d2.hours) > 0){//attempts to borrow from hours
            tempTime.hours -= 1;
            tempTime.mins += 60;
        }
        else {
            diffTime.millis = -1;//could not successfully borrow, 2nd is larger, error
            return diffTime;
        }
    }
    //then checks hours and returns -1 because number 2 is larger and time is error
    if((tempTime.hours - d2.hours) < 0){
        diffTime.millis = -1;
        return diffTime;
    } 
      
     //borrowing was successful, so does subtraction of parts to return difference   
    diffTime.hours = tempTime.hours - d2.hours;
    diffTime.mins = tempTime.mins - d2.mins;
    diffTime.secs = tempTime.secs - d2.secs;
    diffTime.millis = tempTime.millis - d2.millis; 
    
    return diffTime;
}

//converts TDS to milliseconds
int convertToMills(const TimeDateStamp& t){
    int millisInTime = (t.hours * 3600000 ) + (t.mins * 60000 ) + (t.secs * 1000 ) + t.millis;
    return millisInTime;
}

//converts milliseconds to TDS
TimeDateStamp TimeDateStamp::convertToTime(int millisTotal){
    TimeDateStamp newTime = TimeDateStamp();
    newTime.hours = millisTotal / 3600000;
    millisTotal %= 3600000;
    newTime.mins = millisTotal / 60000;
    millisTotal %= 60000;
    newTime.secs = millisTotal / 1000;
    millisTotal %= 1000;
    newTime.millis = millisTotal;
    return newTime;
}

//Overloaded operator< that compares 2 TDSs and returns true if t1 mills is < t2 mills
bool operator<(const TimeDateStamp& t1, const  TimeDateStamp& t2){
    int td1 = convertToMills(t1);  
    int td2 = convertToMills(t2);
    return td1 < td2;
}
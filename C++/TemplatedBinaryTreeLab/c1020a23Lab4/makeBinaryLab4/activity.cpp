/* File: Activity.cpp  *
 * Author: Donna Walker
 * Description: Implements Activity class. An activity has an activity code, 
 *  minutes done, miles equivalent, activity name and activity steps. Block comments 
 * are in the header file. 
 */

#include <iostream>
#include "activity.h"
#include <iomanip>
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
//Default Constructor
Activity::Activity(){ //no arg constructor
    activityCode = 0;//0 with 0 mins is unassigned
    minsDone = 0;
    milesEquivalent = 0;
}
Activity::Activity(int code, int mins){ //two arg constructor
    activityCode = code;
    minsDone = mins;
    
}

Activity::Activity(const Activity& a){ //copy constructor
    activityCode = a.activityCode;
    minsDone = a.minsDone;
    milesEquivalent = a.milesEquivalent;
}

void Activity::clear(){ //convenience to recycle an activity during processing
    activityCode = 0;
    minsDone = 0;
    milesEquivalent = 0;
}

void Activity::setActivityCode(int ac ){ //activity code setter (getter done inline)
    if(ac >= 0 && ac <=26){
        activityCode = ac;
    }
}

void Activity::setMinsDone(int mins){ //minutes done setter (getter done inline)
    if(0 <= mins && mins <= 500){
        minsDone = mins;
    }
    else {
        cout << "Activity minutes must be greater than or equal to 0 and less than or equal to 500." << endl;
    }
}
//formula for step length in feet (f) provided in lab description 
void Activity::setMilesEquivalent(double h){ //sets the miles equivalents and takes height as a paramete
    double f = (h * 0.413)/12.0;
    milesEquivalent = ((STEPS[activityCode] * minsDone) * f)/5280.0; //feet converted to miles
    
 }
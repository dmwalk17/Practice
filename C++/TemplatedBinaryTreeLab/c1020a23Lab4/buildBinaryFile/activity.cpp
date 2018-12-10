#include <iostream>
#include "activity.h"

using std::cout;
using std::endl;
//Default Constructor
Activity::Activity(){
    activityCode = 0;//0 with 0 mins is unassigned
    minsDone = 0;
}
Activity::Activity(int code, int mins){
    activityCode = code;
    minsDone = mins;
}


void Activity::setActivityCode(int ac ){
    if(ac >= 0 && ac <=26){
        activityCode = ac;
    }
}

void Activity::setMinsDone(int mins){
    if(0 < mins && mins < 350){
        minsDone = mins;
    }
    else {
        cout << "Activity minutes must be greater than 0 and less than 350." << endl;
    }
}

void Activity::setMilesEquivalent(double h){
     milesEquivalent = ((STEPS[activityCode] * minsDone) * (h*.413/12))/5280;
 }
 
ostream& operator<<(ostream& out,const Activity& a){
    out << a.activityCode << " " << a.minsDone << " " << a.milesEquivalent << endl;
    return out;
}
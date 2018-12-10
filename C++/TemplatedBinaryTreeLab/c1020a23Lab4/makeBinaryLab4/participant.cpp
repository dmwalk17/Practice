/* File: participant.cpp *
 * Author: Donna Walker
 * Description: Implements Participant class. Participants have a first and last name, a height, and 365 activities. 
 * Activities with 0 activity code and 0 minutes are considered blank. Block comments are in the header file.
 */

#include <fstream>
#include <algorithm>
#include <iomanip>
#include "participant.h"
#include "activity.h"

using std::setw;
using std::right;
using std::left;
using std::fixed;
using std::setprecision;

Participant::Participant(){//no arg constructor
    lastName[0] = '\0';
    firstName[0] = '\0';
    height = 0;
    numActivities = 0;
    for(int i = 0; i < 365; i++){
        dailyActivity[i].setActivityCode(0);
        dailyActivity[i].setMinsDone(0);
    }
        
}
Participant::Participant(char ln[],char fn[],double h){//3-argument constructor
    strncpy(lastName, ln, sizeof(lastName));
    strncpy(firstName, fn, sizeof(firstName));
    height = h;
    numActivities = 0;
}

Participant::Participant(char ln[]){//create participant based on last name
    strncpy(lastName, ln, sizeof(lastName));
    firstName[0] = '\0';
    height = 0;
    numActivities = 0;

}
Participant::Participant(const Participant& p){ //copy constructor
    strncpy(lastName, p.lastName, sizeof(lastName));
    strncpy(firstName, p.firstName, sizeof(firstName));
    height = p.height;
    for(int i = 0; i < 365; i++){
        dailyActivity[i] = p.dailyActivity[i];
    }
    numActivities = p.numActivities;
}
void Participant::setLastName(char ln[]){
    strncpy(lastName, ln, sizeof(lastName));   
}

void Participant::setFirstName(char fn[]){
    strncpy(firstName, fn, sizeof(firstName));
}

void Participant::setHeight(double h){
    if(h > 0 && h < 108)
        height = h;
    else{
        height = 69; // average height for a person in the world according to google
    }    
}

void Participant::setDailyActivity(Activity &a){
        if(numActivities < 365){
            dailyActivity[numActivities] = a;
            numActivities++;
        }
}


void Participant::setNumActivities(int num){
    numActivities = num;
}

//no set total miles because it is a calculated field and should not be overwritten
double Participant::getTotalMiles()const{
    double totalMiles = 0;
    double currentMiles = 0;
    for(int i = 0; i < numActivities; i++){
        currentMiles = dailyActivity[i].getMilesEquivalent();
        totalMiles += currentMiles;
    }
    return totalMiles;
}

ostream& operator<<(ostream& out,const Participant& p){
    
    out << setw(22) << left <<  string(p.firstName) << setw(22) << left 
        << string(p.lastName) << setw(12) << right << fixed << setprecision(2) 
        << p.getTotalMiles();

    return out;
}


void Participant::clear(){//for recycling a temporary Participant during processing
    lastName[0] = '\0';
    firstName[0] = '\0';
    height = 0;
    numActivities = 0;
}
bool operator<(const Participant& p1, const Participant& p2){ //comparison based on last name
    if(strcmp(p1.lastName,p2.lastName) < 0){
        return true;
    }
    return false;
}
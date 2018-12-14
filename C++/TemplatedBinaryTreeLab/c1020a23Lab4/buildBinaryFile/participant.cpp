#include <fstream>
#include "participant.h"

Participant::Participant(){
    lastName[0] = '\0';
    firstName[0] = '\0';
    height = 0;
    numActivities = 0;
        
}
Participant::Participant(char ln[],char fn[],double h){//3-argument constructor
    strncpy(lastName, ln, sizeof(lastName));
    strncpy(firstName, fn, sizeof(firstName));
    height = h;
    numActivities = 0;
}

Participant::Participant(const Participant& p){ //copy constructor
    strncpy(lastName, p.lastName, sizeof(lastName));
    strncpy(firstName, p.firstName, sizeof(firstName));
    height = p.height;
    dailyActivity = p.dailyActivity;
    numActivities = p.numActivities;
}
void Participant::setLastName(char ln[]){
    strncpy(lastName, ln, sizeof(lastName));   
}

void Participant::setFirstName(char fn[]){
    strncpy(firstName, fn, sizeof(firstName));
}

void Participant::setHeight(double h){
    height = h;
}

void Participant::setDailyActivity(Activity &a){
        if(numActivities < 365){
            dailyActivity[numActivities] = a;
            cout << dailyActivity[numActivities] ;
            numActivities++;
        }
}

// doesn't make sense to let someone change numActivities, so
void Participant::setNumActivities(int num){
    numActivities = num;
}

double Participant::getTotalMiles()const{
    vector<Activity>::const_iterator it;
    double totalMiles = 0;
    double currentMiles = 0;
    for(it=dailyActivity.begin(); it != dailyActivity.end();it++){
        currentMiles = it->getMilesEquivalent();
        totalMiles += currentMiles;
    }
    return totalMiles;
}

void Participant::printParticipant() const{
    printf("%-20s%-20s  %4.1lf\n", firstName, lastName, height);
}

void Participant::clear(){
    lastName[0] = '\0';
    firstName[0] = '\0';
    height = 0;
    numActivities = 0;
}
bool operator<(const Participant& p1, const Participant& p2){
    if(strcmp(p1.lastName,p2.lastName) < 0){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& out,const Participant& p){
    
    out << string(p.firstName) << " " << string(p.lastName) << " " << p.height << " "<< "got here "<< p.numActivities <<  "got here2" <<endl;
    for(int i = 0; i < p.numActivities; i++ ){
        out << p.dailyActivity[i].getActivityCode() << " " << p.dailyActivity[i].getMinsDone() << endl;
    }
    return out;
}
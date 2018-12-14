#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <string>
#include <vector>

#define ASSEMBLY_LINE 0
#define BASKETBALL_SHOOTING 1
#define BASKETBALL_GAME 2
#define BICYCLING_UNDER_10MPH 3
#define BICYCLING 4
#define COOKING 5
#define DANCE 6 //add
#define FOOTBALL 7 //add
#define HIKING 8
#define HOUSE_CLEANING 9
#define GARDENING 10
#define MINIATURE_GOLF 11
#define RACQUETBALL 12
#define ROWING 13
#define RUNNING_6MPH 14
#define RUNNING_7MPH 15
#define RUNNING_8MPH 16
#define SHOPPING 17
#define SOCCER 18
#define SOFTBALL 19//Add
#define STAIRS 20//Add
#define SWIMMING_LAPS 21
#define TENNIS 22
#define WALKING_3MPH 23
#define WALKING_4MPH 24
#define WEIGHT_LIFTING 25
#define YOGA 26

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ostream;

const vector<string> ACTIVITIES = {"assembly line", "basketball", "basketball game", "bicycling < 10mph", "bicycling", "cooking", "dance", "football", 
        "hiking", "house cleaning", "gardening", "mini golf", "racquetball", "rowing", "running 6mph", "running 7mph", "running 8mph", "shopping", "soccer", 
        "softball", "stairs", "swimmming", "tennis", "walking 3mph", "walking 4mph", "weigh lifting", "yoga"};
const vector<int> STEPS = {85,136,242,121,242,61,167,242,182,91,99,91,212,212,303,348,409,70,212,152,273,212,212,100,152,121,76};

class Activity{
public:
    Activity();
    Activity(int, int);
    
    void setActivities();
    void setActivityCode(int );
    int getActivityCode()const{ return activityCode; }
    void setMinsDone(int);

    int getMinsDone()const{ return minsDone; }
    void setMilesEquivalent(double);
    /* Precondition: must for call setMilesEquivalent with height parameter first
     */ 
    double getMilesEquivalent()const { return milesEquivalent; }
    void clear();

    friend ostream& operator<<(ostream& out, const Activity& a);
    friend class Participant;
    
private:

    int activityCode;
    int minsDone;
    double milesEquivalent;
    
        
};




#endif
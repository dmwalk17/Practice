/* File: Activity.h *
 * Author: Donna Walker
 * Description: Defines Activity class. An activity has an activity code, minutes done, miles equivalent
    activity name and activity steps. Code block comments are in this file.
 */
#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <string>
#include <vector>

//index of each activity
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
using std::ostream;

//activity names and designated steps for each
const vector<string> ACTIVITIES = {"assembly line", "basketball", "basketball game", "bicycling < 10mph", "bicycling", "cooking", "dance", "football", 
        "hiking", "house cleaning", "gardening", "mini golf", "racquetball", "rowing", "running 6mph", "running 7mph", "running 8mph", "shopping", "soccer", 
        "softball", "stairs", "swimmming", "tennis", "walking 3mph", "walking 4mph", "weigh lifting", "yoga"};
const vector<int> STEPS = {85,136,242,121,242,61,167,242,182,91,99,91,212,212,303,348,409,70,212,152,273,212,212,100,152,121,76};

class Activity{
public:
    /* no arg constructor
     */ 
    Activity(); 
    
    /* Two argument constructor
     *  Takes activity code and minutes done
     *  Postcondition: needs setMilesEquivalent called by the Participant
     *    after using this constructor to dynamically calculate this field
     *     based on participant's height.
     */ 
    Activity(int, int); //constructor that takes an activity code and minutes done
    
    /* copy constructor
     */ 
    Activity(const Activity& a); //copy constructor
    
    /* setActivityCode: changes the activity code for an activity
     * Parameter: ac - the activity code to be set
     * Returns: none
     */ 
    void setActivityCode(int );
    
    /* getActivityCode: accesses activity code of the activity
     * Parameter: none
     * Returns: int - the activity code of this activity
     */ 
    int getActivityCode()const{ return activityCode; }
    
    /* setMinsDate: sets the minutes of activity done
     * Parameter: mins - # of minutes of activity done (int)
     * Returns: none
     */ 
    void setMinsDone(int);

    /* getMinsDone: accesses minutes of activity
     * Parameter: none
     * Returns: int - the minutes of activity done
     */ 
    int getMinsDone()const{ return minsDone; }
    
    /* setMilesEquivalent: dynamically sets equivalent miles based on height 
     * Parameter: h - the Participant's height
     * Returns: none
     */ 
    void setMilesEquivalent(double);
    
    /* getMilesEquivalent: gets the miles equivalent off the activity
     * Parameter: none
     * Precondition: must call setMilesEquivalent with Participant height 
     *      parameter before using
     * Return: miles equivalent for activity
     */ 
    double getMilesEquivalent()const { return milesEquivalent; }
    
    /* clear: sets all the values in the Activity to 0
     *   Written to help with processing multiple activities
     *  Parameter: none
     *  Return: none
     */ 
    void clear();

    /* overloaded operator<<: formats the print of an activity
     *  method used to verify participant activity adds during development
     * Parameters: out - the output stream by reference
     *             a - the activity you want to print
     * Precondition: a valid stream was instantiated prior to method
     * Return: ostream by reference
     */ 
    friend ostream& operator<<(ostream& out, const Activity& a);
    friend class Participant;
    
private:
    //class variables
    int activityCode;
    int minsDone;
    double milesEquivalent;
};




#endif
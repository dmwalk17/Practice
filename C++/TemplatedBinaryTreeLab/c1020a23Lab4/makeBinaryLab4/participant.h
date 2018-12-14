/* File: participant.h *
 * Author: Donna Walker
 * Description: Defines Participant class. Block comments are in this file, not participant.cpp.
 */

#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <cstring>
#include <array>
#include <iostream>
#include "activity.h"
using std::array;
using std::ostream;
                        
class Participant{
public:
    /* No argument constructor
     */
    Participant();
    
    /* 3 argument constructor
     * Parameters: ln - last name
     *             fn - first name
     *              h - height
     */
    Participant(char[],char[],double);
    
    /* Dummy constructor for find in binary tree
     * Parameters: ln - last name
     * Postcondition: fake Participant that must be populated
     *   with actual data if Participant is not in tree
     */
    Participant(char[]);//create participant based on last name
    
    /* copy constructor
     */ 
    Participant(const Participant&); //copy constructor
    
    /* destructor for Participant
     */
    virtual ~Participant() { }  
    
    /* getLastName: get last name of participant
     * Parameter: none
     * Returns: lastName of Participant
     */ 
    const char * getLastName() const { return lastName; }
    
    /* setLastName: sets last name of participant
     * Parameter: ln - last name
     * returns: none
     */ 
    void setLastName(char[]);
    
    /* getFirstName: get first name of participant
     * Parameter: none
     * Returns: firstName of Participant
     */ 
    const char * getFirstName() const { return firstName; }
    
    /* setFirstName: sets first name of participant
     * Parameter: fn - first name
     * returns: none
     */     
    void setFirstName(char[]);
    
    /* getHeight: get height of participant
     * Parameter: none
     * Returns: height of Participant
     */     
    double getHeight() const { return height; }
    
    /* setHeight: sets height of participant
     * Parameter: h - height
     * returns: none
     */  
    void setHeight(double);
    
    /* getDailyActivity: returns an activity based on the index number provided
     * Parameter: i - index of the activity you want
     * Returns: an activity
     */ 
    Activity getDailyActivity(int i) const { return dailyActivity[i]; }
    
    /* setDailyActivity: sets an activity in the last nonblank index of the array provided the array 
     *   isn't already full. if more time I would have had it reset to overwrite the first activity and
     *    keep going in a circular fashion like a queue. adds to numActivities to use this number as 
     *    index for next activity to add.
     *  Parameter: a - an activity to add
     *  Postcondition: no need to reset numactivities, this method does that as well, so no set numactivities needed
     *  Returns: none;
     */ 
    void setDailyActivity(Activity &);
    
    /* getNumActivities: accessor for number of activities
     * Parameters: none
     * Returns: number of participant's activities
     */ 
    int getNumActivities() const { return numActivities; }
    
    // setNumActivities: doesn't make sense to let someone change numActivities, so tempted to 
    // leave this one off, dynamically adds to numActivities when an activity is added and this
    // would  mess up the array index of daily activity if done
    void setNumActivities(int);

    /* getTotalMiles: returns total miles of the participants mile equivalents
     * Parameter: none
     * returns: total miles for the participant as calculated
     */ 
    double getTotalMiles()const;

    /* clear: clears the participant for reuse of a temporary variable during processing
     * Parameter: none
     * Postcondition: the participants values are reset to 0
     * Returns: none
     */ 
    void clear();
    
    /* overloaded operator==: Needed for methods of binary tree. Defines that if two participants have the 
     * same last name, they are the same participant. 
     * Parameter: p1, p2 Two participants to compare
     * Returns: true if the participants have the same last name
     */ 
    friend bool operator==(const Participant& p1, const Participant& p2) { return strcmp(p1.lastName, p2.lastName) == 0;}
    
    /* operator< overloaded: needed to be able to compare/sort nodes in the
     * binary tree
     * Parameters: p1, p2 two participants to compare 
     * returns true if p1.lastName is less than p.2 lastName using strcmp
     */
    friend bool operator<(const Participant&, const Participant&);
    /* overloads << to define and implement the printing of a Participant as
     *   first name, last name and total miles of the participant
     * Parameters: out - the output stream by reference 
     *             p - the participant to print
     * Precondition: a stream has been properly instantiated
     * Returns: ostream by reference
     */ 
    friend ostream& operator<<(ostream& out, const Participant& p);
    
    
private:
    char lastName[21];
    char firstName[21];
    double height;
    Activity dailyActivity [365];
    int numActivities;
};
#endif
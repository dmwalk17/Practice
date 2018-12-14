#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <cstring>
#include <vector>
#include "activity.h"
using std::vector;

class Participant{
public:
    Participant();//no argument constructor
    Participant(char[],char[],double);//3-argument constructor
    Participant(const Participant&); //copy constructor
     virtual ~Participant() { }  
    const char * getLastName() const { return lastName; }
    void setLastName(char[]);
    const char * getFirstName() const { return firstName; }
    void setFirstName(char[]);
    double getHeight() const { return height; }
    void setHeight(double);
    vector<Activity>& getDailyActivity() { return dailyActivity; };
    Activity getDailyActivity(int i) const { return dailyActivity[i]; }
    void setDailyActivity(Activity &);
    int getNumActivities() const { return numActivities; }
    // doesn't make sense to let someone change numActivities, so dynamically calculates when set
    void setNumActivities(int);
    double getTotalMiles()const;
    void printParticipant() const;
    void clear();
    friend ostream& operator<<(ostream& out,const Participant& p);
    friend bool operator<(const Participant&, const Participant&);
private:
    char lastName[20];
    char firstName[20];
    double height;
    vector<Activity> dailyActivity = vector<Activity>(365);
    int numActivities;
};
#endif
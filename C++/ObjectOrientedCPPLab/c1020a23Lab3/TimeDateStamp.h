/* File: TimeDateStamp.h *
 * Author: Donna Walker
 * Description: Defines TimeDateStamp class. 
 */

#ifndef TIMEDATESTAMP_H
#define TIMEDATESTAMP_H
#include <iostream>
#include <string>
using std::string;
class TimeDateStamp
{
public:
    /*No argument constructor
     */ 
    TimeDateStamp();

    /*4-arg constructor
     * Parameters: h-hours,min-mins,s-secs,mils-millis
     */ 
    TimeDateStamp(int, int, int, int);
 
    /*Overloaded Constructor that tokenizes string into TimeDateStamp
     */
    TimeDateStamp(string); 

    /*Copy constructor
     */ 
    TimeDateStamp(TimeDateStamp const &); //copy constructor
    
    /*Destructor
     */ 
    ~TimeDateStamp() { } 
    
    // TimeDateStamp (TDS) 
    //getters and setters for private variables
    /*getHours: accessor method for hours of TDS
     * Parameters: none
     * Return: hours, an int
     */ 
    int getHours() const { return hours; }
    
    /*setHours: mutator for hours of TDS
     * Parameter: h - hours
     * Return: none
     */ 
    void setHours( int );
    
    /*getMins: accessor for minutes of TDS
     * Parameter: none
     * Returns: int - minutes
     */ 
    int getMins() const { return mins; }
    
    /*setMins: mutator for minutes of TDS
     * Parameter: min - minutes
     * Return: none
     */ 
    void setMins( int );
    
    /*getSecs: accessor for seconds of TDS
     * Parameter: none
     * Returns: int - seconds of TDS
     */ 
    int getSecs() const { return secs; }
    
    /*setSecs: mutator for seconds of TDS
     * Parameter: s - seconds of TDS
     * Return: none
     */ 
    void setSecs( int );
    
    /*getMillis: accessor for milliseconds of TDS
     * Parameter: none
     * Return: int - milliseconds of TDS
     */ 
    int getMillis() const { return millis; }
    
    /*setMillis: mutator for milliseconds of TDS
     * Parameter: mils - milliseconds of TDS
     * Return: none
     */ 
    void setMillis(int );
    
    /*convertToMills: converts TDS to milliseconds
     *  used in calculating MPH
     *  (chose to do as friend so I could assign returning milliseconds to variable)
     * Parameter: t - the TDS to convert
     * Return: int - millisecond equivalent to TDS 
     */ 
    friend int convertToMills(const TimeDateStamp&);

    /*convertToTime: converts milliseconds to TDS
     * Parameter: millisTotal - milliseconds to convert
     * Return: TDS - TDS equivalent to millis
     */ 
    TimeDateStamp convertToTime(int );

    /*operator< overwritten operator to help sort TDSs
     *      (uses convertToMills to compare TDS's in millis equivalent)
     * Parameters: t1 - first TDS to compare
     *             t2 - second TDS to compare
     * Return: true if 1st TDS is fewer millis than 2nd TDS
     */
    friend bool operator<(const TimeDateStamp&, const TimeDateStamp&); 
    
    /* operator<< overloaded for TimeDateStamp object
     * Parameters:
     *    outStream the output stream
     *    t the TimeDateObject
     * Returns the output stream
     */
    friend std::ostream& operator<<( std::ostream& , const TimeDateStamp&  ); 
    
    /*operator- overloaded to allow 2 TDSs to be subtracted without conversion
     * Parameters: d1 - the minuend TDS
     *             d2 - the subtrahend TDS (lol, yeah, I looked those up)
     * Return: TDS that is the difference between the other variables
     */ 
    friend TimeDateStamp operator-(const TimeDateStamp&, const TimeDateStamp& ); //overwritten operator - (subtracts 2 timedatestamps)
    
private:
    int hours;
    int mins;
    int secs;
    int millis;

};

#endif 

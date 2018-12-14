/*
 * Player class: defines and implements the player object class.
    Utilizes a Comparable interface to sort
 */
package ExtraCredit;
/**
 *
 * @author Donna
 */
public class Player implements Comparable<Player> {
    
    String name;
    int number;
    double battingAverage;
    
    String DEFAULT_NAME = "";
    int DEFAULT_NUMBER = 1;
    double DEFAULT_BATTING_AVERAGE = 0.0;

    final int MIN_NUMBER = 1;
    final int MAX_NUMBER = 99;
    final double MIN_BATTING_AVERAGE = 0.0;
    final double MAX_BATTING_AVERAGE = 1.0;
    
    public Player(){
        name = DEFAULT_NAME;
        number = DEFAULT_NUMBER;
        battingAverage = DEFAULT_BATTING_AVERAGE;
    }
    
    public Player(String newName){
        this.name = newName;
        this.number = DEFAULT_NUMBER;
        this.battingAverage = DEFAULT_BATTING_AVERAGE;
        
    }
    
    public Player(String newName, int newNumber){
        this.name = newName;
        this.number = newNumber;
        this.battingAverage = DEFAULT_BATTING_AVERAGE;
    }
    
    public Player(String newName, int newNumber, double newBattingAverage){
        this.name = newName;
        number = newNumber;
        battingAverage = newBattingAverage;
    }
    
    public void setName(String setName){
        this.name = setName;
    }
    
    public String getName(){
        return this.name;
    }
    
       public void setNumber(int newNumber){
        this.number = newNumber;
    }
    
    public int getNumber(){
        return this.number;
    }
    
    public void setBattingAverage(double newBattingAverage){
        this.battingAverage = newBattingAverage;
    }
    
    public double getBattingAverage(){
        return this.battingAverage;
    }
    
    @Override
    public int compareTo(Player comparePlayer){
        
            int compareNumber = ((Player)comparePlayer).getNumber();
                
        return this.number - compareNumber;
    }
    
    
    @Override
    public String toString(){
        String output = "Player's Name: " + this.name + "\n" + 
                        "Player's Number: " + this.number + "\n" +
                        "Player's Batting Avg: " + this.battingAverage + "\n";
                         
        return output;
    }
}

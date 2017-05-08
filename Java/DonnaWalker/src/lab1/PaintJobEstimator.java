/*
 * File: PaintJobEstimator.java
 * Author: Donna Walker
 * Date: 1/23/2014
 * Description: Estimates the cost of painting one or more rooms. Takes user 
 * provided values to tabulate: the number of gallons of paint required, 
 * the hours of labor required, the cost of the paint, the labor charges, 
 * and the total cost of the paint job. Required constants: hourly labor rate 
 * is $18; 115 square feet of wall takes 8 hours and a gallon of paint complete. 
 * Prescribed methods: getRooms(), getSqureFeet(int rooms), getPricePerGallon(), 
 * and getTotal(double squareFeet), getPainCost(double sqFeet, double galPrice), 
 * getGallons(double sqFeet), getHours(double sqFeet), and getLabor(double hours). 
 * The output includes: gallons of paint required, hours of labor required, 
 * cost of the paint, labor charges and the total cost of the paint job.
 */

package lab1;
import java.text.DecimalFormat;
import java.util.Scanner;
public class PaintJobEstimator {
    
  //Initializes scanner  
  static Scanner input = new Scanner(System.in);   
 
  public static void main(String[] args){
      
    //Declares constants and main method variables 
    final double HR_LABOR_RATE = 18.00;
    final int WALL_UNIT_SF = 115;
    final int HOURS_PER_UNIT = 8;
    double sqFeet, totalCost;
    
    //Invokes getRooms method to prompt user for number of room to be painted
    int rooms = getRooms();   
    
    //Invokes getSquareFeet method to receive, by room,  and total square feet to be painted
    sqFeet = getSquareFeet(rooms);
    
    //Invokes getTotal method to tabulate and display the paint job estimate.  
    totalCost = getTotal(sqFeet, WALL_UNIT_SF, HOURS_PER_UNIT, HR_LABOR_RATE);
          
  }
    //Receives user input for the number of rooms to be painted
    public static int getRooms(){
        
      System.out.println("How many rooms do you want painted?");
      String roomString = input.next();
      Boolean verify = VerificationMethods.isInt(roomString);
      for (;!verify;){
        System.out.print("Please enter a positive integer: ");
        roomString = input.next();
        verify = VerificationMethods.isInt(roomString);
      }
      
      int rooms = Integer.parseInt(roomString);
                 
      return rooms;
    }
    
    //Receives user input, validates that inputted square footage is a positive number 
    //greater than zero, and totals square footage of entire job.
    public static double getSquareFeet(int rooms){
      double[] room = new double[rooms];
      double sqFeet = 0;
      //Receives and verifies inputted squareFeet
      for (int i = 0; i<rooms; i++){
        System.out.println("What is the square footage of Room " + (i+1) + "?");
        String temp = input.next();
        
        Boolean verify = VerificationMethods.isIntOrDouble(temp);
        for(;!verify;){
          System.out.print("Invalid. Please enter a positive number: ");
          temp = input.next();
          verify = VerificationMethods.isIntOrDouble(temp);
        }
        
        room[i] = Double.parseDouble(temp);
        sqFeet = sqFeet + room[i];         
      }
      return sqFeet;        
    }
          
    /* Invokes methods: getPricePerGallon, getGallons, getPainCost, getHours, 
     * getLabor, and displayResults. Calls these methods to calculate and  
     * display estimate of total cost for painting project.
     */
    public static double getTotal(double sqFeet, int WALL_UNIT_SF,int HOURS_PER_UNIT, double HOUR_LABOR_RATE){
      //Initializes local variable
      double totalCost;
      
      //Invokes methods to tabulate paint requirements and costs.
      double galPrice = getPricePerGallon();
      int numberGallons = getGallons(WALL_UNIT_SF, sqFeet);
      double paintCost = getPaintCost (galPrice, numberGallons);
      
      //Verifies that the cost of paint is 0 or higher. I provided '0' as an 
      //option to provide flexibility, in case the consumer provided their own paint.
      if (paintCost<0){
        System.out.print("Paint cost cannot be a negative number");
        paintCost = getPaintCost (galPrice, numberGallons);
      }  
      
      //Invokes methods to analyze labor requirements and costs.
      double hours = getHours(sqFeet, WALL_UNIT_SF, HOURS_PER_UNIT);
      double laborCost = getLabor(hours, HOUR_LABOR_RATE);
      
      //Combines paint and labor costs into total costs
      totalCost = paintCost + laborCost;
      
      //Displays estimate of costs
      displayResults(numberGallons, paintCost, hours, laborCost, totalCost);
      return totalCost;
    }
    
    //Requests cost per gallon of paint and returns value to totalCost method
    public static double getPricePerGallon(){
      String temp;
      double galPrice;
      Boolean verify;
      System.out.println("How much does you paint cost per gallon?");
      System.out.print("Enter zero if you are providing your own paint. ");
      temp = input.next();
      verify = VerificationMethods.isIntOrDouble(temp);
      for (;!verify;){
        System.out.print("Please enter a valid price per gallon: ");
        temp = input.next();
        verify = VerificationMethods.isIntOrDouble(temp);  
          
      }
      galPrice = Double.parseDouble(temp);
      return galPrice;
    }
    
    //Tabulates number of gallons necessary based to program constants. Rounds
    //up to the next gallon since it is difficult to buy a partial gallon.
    public static int getGallons(int WALL_UNIT_SF, double sqFeet){
      int numberGallons = (int)(Math.ceil(sqFeet/WALL_UNIT_SF));
      return numberGallons;
    }
    
    //Tabulates the cost of paint for the project
    public static double getPaintCost(double galPrice, int numberGallons){
      double paintCost = galPrice * numberGallons;
      return paintCost;
    }
    
    //Evaluates the number of hours to complete the job
    public static double getHours(double sqFeet, int WALL_UNIT_SF, int HOURS_PER_UNIT){
      double hours = ((sqFeet/WALL_UNIT_SF)) * HOURS_PER_UNIT;    
      return hours;
    }
    
    //Tabulates the labor cost based on hours needed and labor rate constant provided  
    public static double getLabor(double hours, double HOUR_LABOR_RATE){
      double laborCost = hours * HOUR_LABOR_RATE;     
      return laborCost;
    }
    
    //Displays the required fields in proper format to show estimated costs of 
    //the painting project
    public static void displayResults(int numberGallons, double paintCost, double hours, double laborCost, double totalCost){
       DecimalFormat formatting = new DecimalFormat("$#0.00");
       DecimalFormat formatted = new DecimalFormat("#0.00");
       System.out.println("\nThe number of gallons needed is: " + numberGallons);
       System.out.println("This job will require: " + formatted.format(hours) + " hours to complete.");  
       System.out.println("The paint for this job will cost: " + formatting.format(paintCost));
       System.out.println("The labor for this job will cost: " + formatting.format(laborCost));
       System.out.println("Your total cost is: " + formatting.format(totalCost));
    }
}
    
    
    
  


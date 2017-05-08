package lab1;
import java.text.DecimalFormat;

/*
 * File: RetailItem.java
 * Author: Donna Walker
 * Date: 2/3/2015
 * Each RetailItem object holds data about an item in a retail store. The class 
 * is required to have instance variables: description (String); 
 * unitsOnHand(int); and price(double). Each data field is required to have a
 * getter and setter method. A toString method is also required for formatted 
 * output from the test class.
 */


public class RetailItem {
 
  //Declares object variables and a static numberOfObjects field to keep count 
  //of the objects generated for use when outputting a list of the objects.
  private String description = "Shirt";//Holds a brief descrition of the item
  private int unitsOnHand = 20;//Holds the number of units currently in inventory
  private double price = 24.95;//Holds the item's retail price
  private static int numberOfObjects = 0;
  
  //Default constructor for RetailItem that uses default values.
  public RetailItem(){
    this.description = description;
    this.unitsOnHand = unitsOnHand;
    this.price = price;
    numberOfObjects++;
  } 
  
  //Constructor for use when all variables are provided as arguments.
  public RetailItem(String description, int unitsOnHand, double price){
    this.description = description;
    this.unitsOnHand = unitsOnHand;
    this.price = price;
    numberOfObjects++;
  }
  
  //Sets a new value into the description field
  public void setDescription(String newDescription){
    this.description = newDescription;
  }
  
  //Returns the value of the designated object's description field
  public String getDescription(){
     return this.description;
  }
  
  //Changes the amount of unitsOnHand
  public void setUnitsOnHand (int newUnitsOnHand){
      this.unitsOnHand = newUnitsOnHand;
  }
  
  //Returns the amount of unitsOnHand
  public int getUnitsOnHand(){
      return this.unitsOnHand;
  }
  
  //Changes the value in the price variable
  public void setPrice(double newPrice){
    this.price = newPrice;
  }
  
  //Displays the value in the price variable
  public double getPrice(){
    return this.price;
  }
  
  /* Utilizes Overridden toString with an if statement and result variable to 
   * return output of objects generated into a table format. (Allows for some 
   * flexibility for a longer description field.) Uses a DecimalFormat object 
   * for currency output on the price variable field.
  */  
  @Override
  public String toString(){
        
    DecimalFormat resulting = new DecimalFormat("$#0.00");
    String result;
    if (this.description.length() > 8){
      result = "\n ";
      result += "Item # " + numberOfObjects + "\t\t"  + this.getDescription() + "\t\t"; 
      result += this.getUnitsOnHand() + "\t\t"; 
      result += resulting.format(this.getPrice())+ "\n";
    }
    else{
      result = "\n ";
      result += "Item # " + numberOfObjects + "\t\t" + this.description + "\t\t\t";
      result += this.unitsOnHand + "\t\t";
      result += resulting.format(this.price)+ "\n";
  }
    
    return result;
  }

}


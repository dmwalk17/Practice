/*
 * File: RetailItemTest.java
 * Author: Donna Walker
 * Date: 2/3/2015
 * Tests class RetailItem by creating and displaying: 1) an user defined instance, 
 * 2) an instance with variables provided in an argument, and 
 * 3) an daufault instance of the RetailItem class.
 * 
 * 
 */

package lab1;
import java.util.Scanner;

public class RetailItemTest {

  public static void main (String[] args){
      
    // Creates a Scanner to accept input
    Scanner input = new Scanner(System.in);
    
    System.out.println("In order to create your RetailItem object: ");
    
    // Prompts for description of object.
    System.out.print("Enter an item description. (Example: Jacket): ");
    String description = input.nextLine();
    
    // Ensures that user input will fit in table display.
    description = VerificationMethods.checkLength(description, 15);
      
    // User enters number of items on hand and checkLength() verifies it will fit table.
    System.out.print("Enter the number of items on hand. (Example: 12): ");
    int unitsOnHand = input.nextInt();
    unitsOnHand = VerificationMethods.checkLength(unitsOnHand, 5);
    // Prompts for object price and checkLength() verifies it will fit table.
    System.out.print("Enter the price of the item. (Example:  59.95): ");
    double price =  input.nextDouble();
    price = VerificationMethods.checkLength(price, 8);

    // Creates RetailItem object from user input.
    RetailItem item1 = new RetailItem (description, unitsOnHand, price);
 
    //Displays header for table.
    System.out.print("\t\t\tDescription\tUnits on Hand\t\tPrice");
  
    //Displays user defined object.
    System.out.print(item1);
   
    //Creates and displays an argument-based object. 
    RetailItem item2 = new RetailItem ("Designer Jeans", 40, 34.95);
    System.out.print(item2);
  
    //Creates and displays a default object.
    RetailItem item3 = new RetailItem ();
    System.out.print(item3);

  }    
}

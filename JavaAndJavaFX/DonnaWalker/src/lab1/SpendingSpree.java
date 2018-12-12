/*
 * File: SpendingSpree.java
 * Author: Donna Walker
 * Date: 1/20/2015
 * Description: Tracks the user's account balance remaining and number of items 
 * purchased during a $200 gift certificate spending spree. Confirms the amount 
 * of each purchase is within the spending limit and monitors to ensure that the 
 * three item purchase limit is not exceeded. Displays of how many items
 * have been purchased, how much money is remaining, and when the spree is over.
 * 
 */

package lab1;
import java.util.Scanner;
import java.text.DecimalFormat;
public class SpendingSpree {
  public static void main(String[] args) { 
  
    //Initializes constant variables and arrays for store display of items   
    final int ITEM_LIMIT = 3;
    final double ACCOUNT_BALANCE = 200.00;
    String[] retailItem = {"Black Jacket", "Black Dress", "Dress Pants", "Novelty Hat", "Designer Shoes", "Wonder Widget"};
    double[] price = {149.99, 64.99, 39.99, 14.99, 99.99, 0.01}; 
 
    //Displays store brand, spending limit, and rules to the user
    System.out.println("Welcome to Lady Diva boutique. You have won a $200.00 shopping spree!"); 
    System.out.println( "You can purchase up to three items, provided your spending limit is not exceeded.");
    System.out.println("We are low on stock since it is end of season. These are our items available today:\n");    
 
    //Invokes shop method to track purchases
    shop(ITEM_LIMIT, ACCOUNT_BALANCE, retailItem, price);
  
    //Informs user that the spree is complete
    System.out.print("\nCongratulations on your win! We hope you enjoy your purchases!");
  }
  
  // Allows the user to purchase items until the spending limit is reached or 
  // three items have been purchased.
  public static void shop(int ITEM_LIMIT, double ACCOUNT_BALANCE, String[]retailItem, double[]price){
    
    //Initializes scanner and number formatting  
    Scanner input = new Scanner(System.in);
    DecimalFormat formatting = new DecimalFormat("$#0.00");
    
    //Declares local variables for tracking spending rules
    int items;
    double amountSpent = 0;
    
    //Displays store items available 
    displayItems(retailItem, price); 
    
    //Utilizes for loop to continue shoping until limits are reached
    for(items=0;items < ITEM_LIMIT;){
      System.out.println("\nIt's time to shop! How much is your item? (Example: 22.22)");
      
      //Receives input as string to allow for verification for proper number format
      //and amount.
      String inputPurchase = input.next();
      
      //Invokes isIntOrDouble method to catch negative, character or letter input
      Boolean verify = VerificationMethods.isIntOrDouble(inputPurchase);
          
      //Displays retail items an error message if a false or inaccurate value is entered.
      if (!verify){
        displayItems(retailItem, price);  
        System.out.println("\nInvalid input. Please enter one of the prices on the list.\n");
        continue;
      }
      
      //Invokes StringMethods.matchArray to ensure the price is one on the list 
      //and displays store display items, amount left and error message if invalid.
      else{
         Boolean verify2 = VerificationMethods.matchArray(inputPurchase, price);
         if (!verify2){
           displayItems(retailItem, price);  
           System.out.println("\nYour purchase must match a price on the list." +
                   "Your have " + formatting.format(ACCOUNT_BALANCE - amountSpent) + " left to spend.");
           continue;
         } 
      }
            
      //Invokes makeDouble to convert string to double
      double purchase = VerificationMethods.makeDouble(inputPurchase);
      
      //If request exceeds limit, displays store items, error message, and amount to spend.
      if ((purchase+amountSpent)>ACCOUNT_BALANCE){
        displayItems(retailItem, price);  
        System.out.println("\nYour purchase exceeds your limit! You have " + (formatting.format(ACCOUNT_BALANCE-amountSpent)) + " left to spend. Please choose a different item.");
        continue;
      }
      
      //Confirms the user's purchase choice before finalizing sale
      else{
        System.out.print("Are you sure you want to purchase this item? (Y/N)");
      }
      
      //Accepts user input to confirm sale.
      String confirm = input.next();
        
      //Voids amount unless a 'Y' or 'y' is entered. If confirmed, adds item and 
      //amount of purchase to totals. 
      if (confirm.charAt(0) == 'Y' || confirm.charAt(0) == 'y' ){
        amountSpent = amountSpent + purchase;
        items++;
      }  
      //Displays updated status of shopping spree after purchase
      displayItems(retailItem, price); 
      System.out.println("\nYou have purchased " + items + " items. You have " + 
      (ITEM_LIMIT - items) + " items to buy. You have " + formatting.format(ACCOUNT_BALANCE - amountSpent)+ 
          " left to spend.");   
        
    }
  }
  //Displays a formatted output of the retail items available in the store. 
  public static void displayItems(String[]retailItem, double[] price){
    System.out.println("\t\tDescription\t\tPrice\t\t\tDescription\t\tPrice");
    DecimalFormat formatting = new DecimalFormat("$#0.00");
   
    for (int i=0; i<retailItem.length; i=i+2){
      System.out.println("  Item " + (i +1) + "\t" + retailItem[i]+ "\t\t" + formatting.format(price[i])+
        "\t\t" + "Item " + (i+2) + "\t" + retailItem[i+1] + "\t\t" + formatting.format(price[i+1]));  
    }
  }
}
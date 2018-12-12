/*
 * Name: Donna Walker
 * Class: 1520 - Java
 * Description: Library of String Methods 
 *
 */
package lab1;
import java.lang.*;
import java.util.*;

public class VerificationMethods {
  //Assesses a string to determine if it contains an integer or double
  public static Boolean isIntOrDouble(String s){
    for(int i=0;i<s.length();i++){  
      if (Character.isDigit(s.charAt(i)) || s.charAt(i)=='.'){
          
      }   
      else{
        return false;
      }    
    }  
    return true;
  }
  //Assesses a string to determine if it is an integer.  
  public static Boolean isInt(String s){
    for(int i=0;i<s.length();i++){  
      if (Character.isDigit(s.charAt(i))){
          
      }   
      else{
        return false;
      }    
    }  
    return true;
  }
  //Parses an string into a double.  
  public static double makeDouble(String s){
    double result;
    result = Double.parseDouble(s);
    return result;
    
  }  
  //Parses a string into an integer.
  public static int makeInt(String s){
    int result;
    result = Integer.parseInt(s);
    return result;
  }
  //Compares a string value to the values in a double array. 
  public static Boolean matchArray(String s, double[]value){
    double temp = makeDouble(s);
    for (int i=0;i<value.length;i++){
      if (temp==value[i]){
        return true;
      }  
                
    }  
    return false;    
  }
   // For use with table data.
   // Ensures that user inputted string will fit in table display based on given limit.
  public static String checkLength(String s, int limit){    
    Scanner input = new Scanner(System.in);
    String description = s; 
    int lengthLimit = limit;
     for (;description.length()>lengthLimit;){
       System.out.println("This field cannot be more than " + lengthLimit +" characters.");
       System.out.print("Enter an item description. (Example: Jacket): ");
       description = input.nextLine();  
     }
     return description;
     }
     
      
  // For use with table data. Ensures that user inputted double will fit in table display.
  public static double checkLength(double numDouble, int limit){   
    Scanner input = new Scanner(System.in);  
    String doubleNumber = String.valueOf(numDouble);
    int lengthLimit = limit;
       
    if (doubleNumber.length()> lengthLimit){
      System.out.println("This field cannot be more than 8 characters.");
      System.out.print("Enter a number 8 characters or less. (Example: 33433.33): ");
      numDouble = input.nextDouble();  
    }
    return numDouble;
}
  // For use with table data. Ensures that user inputted integer will fit in table display.
  public static int checkLength(int numInt, int limit){
    Scanner input = new Scanner(System.in);
    String stringInt; 
    stringInt = String.valueOf(numInt);
    System.out.println(numInt);
    if (stringInt.length()>5){
      System.out.println("Field cannot be more than a 5 digit integer.");
      System.out.print("Enter an item description. (Example: 33333): ");
      numInt = input.nextInt();  
    }
    return numInt;
}
   //Check a string to determine all the values are letters.  
   public static boolean verifyNumber(String s){
     for(int i=0;i<s.length();i++)  
      if (Character.isLetter(s.charAt(i))){
        //errorMessage();  
        return false;
     
      }    
     return true;
   }
}


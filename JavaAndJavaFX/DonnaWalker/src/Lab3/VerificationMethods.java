/*
 * Name: Donna Walker
 * Class: 1520 - Java
 * Description: Library of Verification Methods 
 *
 */

package Lab3;


import java.lang.*;
import java.util.*;
import java.text.DecimalFormat;

public class VerificationMethods {
  Scanner input = new Scanner(System.in);  
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
  
  //Assesses a string to determine if it contains an integer or double
  public static Boolean isDouble(String s){
    int dotCount=0;
      for(int i=0;i<s.length();i++){  
      if (Character.isDigit(s.charAt(i)) || s.charAt(i)=='.'){
        if(s.charAt(i)=='.'){
          dotCount++;
        }  
        if(dotCount>1){
          return false;  
        }  
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
      if (!Character.isDigit(s.charAt(i))){
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
  
  public static boolean verifyEmpNumber(String s){
    Scanner input = new Scanner(System.in);
    
    try{  
      if (Character.isDigit(s.charAt(0)) && Character.isDigit(s.charAt(1)) && Character.isDigit(s.charAt(2)) 
        && s.charAt(3)=='-' && (s.charAt(4)>='A' && s.charAt(4)<='M' && s.length()==5)){  
        return true;
      }  
      else{
        return false;
      }    
    }
    catch(StringIndexOutOfBoundsException ex){
      System.out.println("Try again. Correct Format ###-L (L: Capital A-M)  ");
      return false;
    }
  
    
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

   
    //Provides input string for the object attribute of driverName. 
  
  public static StringBuilder setIdentity(){
    String tempFirst="", tempMiddle="", tempLast=""; 
    return verifyIdentity(tempFirst, tempMiddle, tempLast);
  }
  
  //Gets and verifies user input for identity for each object
  public static StringBuilder verifyIdentity(String tempFirst, String tempMiddle, String tempLast){
    Scanner input = new Scanner(System.in);  
    boolean verify = false;
    StringBuilder tempName=null;
    
    while (verify==false || tempFirst==null || tempLast==null){
      System.out.println("Your name must include only letters with no spaces, and only one letter for middle initial.");
      System.out.println("Example: Your O Name");
      System.out.print("Please enter your first name: ");
      tempFirst = input.next();
      System.out.println("Please enter your middle initial: ");
      tempMiddle = input.next();
      System.out.println("Please enter your last name: ");
      tempLast = input.next();
      verify = nameDoubleCheck(tempFirst, tempMiddle, tempLast);
                   
       
          
    }
    
    return tempName;
  }
  //
  public static boolean nameDoubleCheck(String tempFirst, String tempMiddle, String tempLast){
    
    Scanner input = new Scanner(System.in);
    String verName;
    StringBuilder tempName = new StringBuilder();
    boolean verify = false;
    System.out.print("Is your name: " + tempFirst + " " + tempMiddle + " " + tempLast + "? (Yes or No)");
    verName = input.next();
     
    if (verName.charAt(0)=='y' || verName.charAt(0)=='Y'){
      //Calls testIdentity to test the validity of the confirmed user input  
      tempName = ArrayTestMethods.formatIdentity(tempFirst, tempMiddle, tempLast);
      verify = ArrayTestMethods.testValid(tempName);
      if (verify){
        return verify;      
      }
      }
    else{
      setIdentity();  
    }
    return verify;
  }
  //Verifies a valid date for employment.  
  public static String verifyDate(String tempDate){
    Scanner input = new Scanner(System.in); 
    //Commented out so I can work on later. Not needed for this program.
    //int day = (Character.getNumericValue((tempDate.charAt(0)*10))) + (Character.getNumericValue(tempDate.charAt(1)));
    //int month = (Character.getNumericValue((tempDate.charAt(3)*10)) + (Character.getNumericValue(tempDate.charAt(4))));
    //int year = (Character.getNumericValue((tempDate.charAt(6)*10))) + (Character.getNumericValue(tempDate.charAt(7)));
    //System.out.print(day +"/" + month + "/" + year);
    boolean verify = false;
    //boolean validate = false;
    while (!verify){
      if (Character.isDigit(tempDate.charAt(0)) && Character.isDigit(tempDate.charAt(1)) && tempDate.charAt(2)=='/' &&
            Character.isDigit(tempDate.charAt(3)) && Character.isDigit(tempDate.charAt(4)) && tempDate.charAt(5)=='/' &&
            Character.isDigit(tempDate.charAt(6)) && Character.isDigit(tempDate.charAt(7))){
            verify = true;
      }
     // if (((day>=0) && (day<=31)) && ((month>0) && (month<=12)) && ((year > 1970) && (year <= 2015))){
     //   validate= true;
      if (!verify){
        System.out.println("The hire date must be a valid hire date in the following format: 04/22/15");
        //System.out.println("The date must be within mandatory retirement guidelines and no later than this year.");
        //System.out.println("Note: Future hires for 2016 or later are not allowed to be entered at this time.");
        System.out.println("Please enter a valid hire date: ");
        tempDate = input.next(); 
        
        //validate=false;
      }
         
    }
    return tempDate;
        
  }
 
}


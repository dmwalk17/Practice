 /*
 * File: Employee.java
 * Author: Donna Walker
 * Date: 3/20/2015
 * Class: CSIT 1520
 * Description: Defines Employee super class. Extended by ProductionWorker and 
 * TeamLeader. Also extended by ShiftSupervisor. Provides employeeName, hireDate,
 * and employeeNumber for the subclasses.
 */
package Lab3;

import java.util.*;
import java.text.SimpleDateFormat;
import java.text.DecimalFormat;

public class Employee {
  //Initializes variables as private  
  Scanner input = new Scanner(System.in);  
  private StringBuilder employeeName = new StringBuilder();
  private StringBuilder tempName = new StringBuilder();
  private StringBuilder employeeNumber = new StringBuilder();
  private String hireDate;
  private Date d = new Date();
  private SimpleDateFormat formatter = new SimpleDateFormat("MM/dd/yy");
    
  //Contains protected no-argument constructor for Employee. Defaults new hire date to current date.
  protected Employee(){
    this.hireDate= formatter.format(d);
  }
  //

  //Provides verification methods for changing the data in private field employeeName.
  public void setName(String first, String mInt, String lName){
    this.employeeName=nameDoubleCheck(first, mInt, lName);  
      
  }
  
  //Allows access to private data field Employee Name.
  public String getName(){
    return this.employeeName.toString();
  }
  
  //Allows for manipulation and verification of private field Employee Number 
  public void setEmployeeNumber(String empNumber){
    boolean verified = false;
    while (!verified){
      verified = VerificationMethods.verifyEmpNumber(empNumber);
      if (!verified){
        System.out.println("Invalid entry. A valid employee number is ###-L. # signifies a "
          + "number and L should be a capital letter between A and M. Ex: 999-B. Please "
          + "try again: ");
        empNumber = input.next();  
      }
      if (employeeNumber != null){
      employeeNumber.setLength(0);
      employeeNumber.append(empNumber);
      
      }  
      else{
        System.out.print(empNumber +" "+employeeNumber);
        employeeNumber.append(empNumber);  
      }
    }
  }
  //Allows access to data in private field employeeNumber
  public String getEmployeeNumber(){
    return this.employeeNumber.toString();
  }
  
  //Allows access to manipulate data w/ verification in private field hireDate.
  public void setHireDate(String hdate){
    this.hireDate = VerificationMethods.verifyDate(hdate);  
  }
  
  //Allows access to private field hireDate.
  public String getHireDate(){
    return this.hireDate.toString();
  }
  
  //Overrides object class toString method to format display of Employee object
  //data fields.
  public static StringBuilder setIdentity(){
    String tempFirst="", tempMiddle="", tempLast=""; 
    return verifyIdentity(tempFirst, tempMiddle, tempLast);
  }
  
  //Gets user input for name identity and invokes verification procedure.
  public static StringBuilder verifyIdentity(String tempFirst, String tempMiddle, String tempLast){
    Scanner input = new Scanner(System.in);  
    boolean verify = false;
    StringBuilder tempName=null;
    
    while (!verify || tempFirst==null || tempLast==null){
        
      System.out.println("Your name must include only letters with no spaces, and only one letter for middle initial.");
      System.out.println("Example: Your O Name");
      System.out.print("Please enter your first name: ");
      tempFirst = input.next();
      System.out.println("Please enter your middle initial: ");
      tempMiddle = input.next();
      System.out.println("Please enter your last name: ");
      tempLast = input.next();
      tempName = nameDoubleCheck(tempFirst, tempMiddle, tempLast);
      return tempName;
   }
    return tempName;
  }
  //Verifies user input of name and sends to validation and formatting methods.
  public static StringBuilder nameDoubleCheck(String tempFirst, String tempMiddle, String tempLast){
    
    Scanner input = new Scanner(System.in);
    String verName;
    StringBuilder tempName = new StringBuilder();
    boolean verified = false;
    System.out.print("Is your name: " + tempFirst + " " + tempMiddle + " " + tempLast + "? (Yes or No)");
    verName = input.next();
    while (!verified){ 
      if (verName.charAt(0)=='y' || verName.charAt(0)=='Y'){
      //Calls testIdentity to test the validity of the confirmed user input 
        tempName = ArrayTestMethods.formatIdentity(tempFirst, tempMiddle, tempLast);
        verified = ArrayTestMethods.testValid(tempName);
      
        if (!verified){
          tempName=setIdentity();
          break;
        }
        else{
          verified=true;  
          return tempName;
        }
      }
      else{
        tempName=setIdentity();
        break;
      }    
    }
    return tempName;
  }
  
  //Overrides object toString to format and display Employee class data fields
  //and test accessor methods for the data fields of this class.
  @Override
  public String toString(){
    String result = "Employee Name: " + getName() + "\n"
    + "Employee Number: " + getEmployeeNumber() + "\n" + "Hire Date: " + getHireDate() + "\n";
    
    return result;
   }
}

  




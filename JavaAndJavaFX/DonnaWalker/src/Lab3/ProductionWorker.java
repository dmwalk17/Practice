/*
 * File: ProductionWorker.java
 * Author: Donna Walker
 * Date: 3/20/2015
 * Class: CSIT 1520
 * Description: Defines the ProductionWorker class of objects and extends the 
 * Employee class.
 */
package Lab3;

import java.util.*;
import java.text.DecimalFormat;

public class ProductionWorker extends Employee{
  //Initializes scanner and private default variables  
  Scanner input = new Scanner(System.in);  
  private int shift = 0;
  private double hourlyPayRate = 0.02;

  //Provides no argument constructor  
  protected ProductionWorker(){
     
  }
  //Provides verification of manipulation of data to private field of shift. 
  public void setShift(String shift){
    boolean verify = false;
    while (!verify){        
      if ((shift.charAt(0)=='1'|| shift.charAt(0)=='2') && shift.length()==1){
        this.shift = Integer.parseInt(shift);
        break;
      }
      else {
        System.out.print("Please enter a '1' for day shift or '2' for night shift");
        shift = input.next();
      }
    }
  }
  //Accessor method for private data field of Shift.
  public int getShift(){
    return this.shift;
  }
  
  //Verifies and mutates hourlyPayRate.  
  public void setHourlyPayRate(String payRate){
    boolean verify = false;
    while (!verify){
      verify = VerificationMethods.isDouble(payRate);  
      if (verify){
        this.hourlyPayRate = VerificationMethods.makeDouble(payRate);
        break;
      }
      else{ 
        System.out.println("Please enter a valid pay rate for currency. Example: 23.22");
        payRate = input.next();
      }
    } 
  }
    
  
  //Accesses private field hourlyPayRate.
  public double getHourlyPayRate(){
    return this.hourlyPayRate;
  }
  //Uses overriden toString method to show general Employee information,
  //as well as specific ProductionWorker fields of data.
  @Override
  public String toString(){
    DecimalFormat formatted = new DecimalFormat("#0.00");
    String result = super.toString() + 
          "Shift: " + getShift() + "\n" 
          + "Hourly Pay Rate: $" + formatted.format(getHourlyPayRate());
    return result;
  }
  
}

    

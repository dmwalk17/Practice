/*
 * File: TeamLead.java
 * Author: Donna Walker
 * Date: 3/20/2015
 * Description: Defines the TeamLead class that inherits from the class ProductionWorker
 * that is subclass of the Employee class. 
 */
package Lab3;
import java.text.DecimalFormat;
public class TeamLead extends ProductionWorker{
  
  //Initializes private variables of this class.  
  private double monthlyBonusAmount = 200.00;
  private int requiredTrainingHours = 20;
  private int actualTrainingHours = 0;
  
  //Uses no-argument constructor and defaults the values of monthlyBonus,requiredTrainingHours,
  //andactualTrainingHours unless mutator method is used to change it.
  protected TeamLead(){
    this.monthlyBonusAmount = monthlyBonusAmount;
    this.requiredTrainingHours = requiredTrainingHours;
    this.actualTrainingHours=actualTrainingHours;
  }
  //Mutates data with verification for monthlyBonusAmount.
  public void setMonthlyBonusAmount(String bonusAmount){
    boolean verified = false;
    while (!verified){
      verified = VerificationMethods.isDouble(bonusAmount);
      if (!verified){
        System.out.println("Please enter a currency amount. Ex: 200.00 ");
        bonusAmount = input.next();
      }
    }
    this.monthlyBonusAmount = VerificationMethods.makeDouble(bonusAmount); 
  }  

  //Accesses the private monthlyBonusAmount field.
  public double getMonthlyBonusAmount(){
    return this.monthlyBonusAmount;  
  }
  
  //Allows for change of requredTrainingHours with verification of data.
  public void setRequiredTrainingHours(String requiredHours){
    boolean verified = false;
    while (!verified){
      verified = VerificationMethods.isInt(requiredHours);
      if (!verified){
        System.out.println("Please enter an integer for required training hours. Ex: 2 : ");
        requiredHours = input.next();
      }
    }  
    this.requiredTrainingHours=VerificationMethods.makeInt(requiredHours);
    
    
  }

  //Accesses requiredTrainingHours.
  public int getRequiredTrainingHours(){
    return this.requiredTrainingHours;
  }
  
  //Enables mutation of the private data field: actualTrainingHours
  public void setActualTrainingHours(String hours){
    boolean verified = false;
    while (!verified){
      verified = VerificationMethods.isInt(hours);
      if (!verified){
        System.out.println("Please enter an integer for actual training hours. Ex: 2 : ");
        hours = input.next();
      }  
    }
    this.actualTrainingHours = VerificationMethods.makeInt(hours);
  }
  //Accesses data from private field: actualTrainingHours 
  public int getActualTrainingHours(){
    return this.actualTrainingHours;
   } 

  //Utilizes an overridden toString to display the Employee class, ProductionWorker
  //and TeamLead attributes for this type of object. Demonstrates function of accessor methods.
  @Override
  public String toString(){
    DecimalFormat formatted = new DecimalFormat("#0.00");   
    String result = super.toString() + "\n"          
      + "Monthly Bonus Amount : $" + formatted.format(getMonthlyBonusAmount()) +"\n"
      + "Required Training Hours: " + getRequiredTrainingHours() +"\n"
      + "Actual Training Hours: " + getActualTrainingHours() + "\n";
     
     return result;
             
}
}
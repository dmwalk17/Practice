/*
 * File: ShiftSupervisor.java
 * Author: Donna Walker
 * Date: 3/20/2015
 * Class: Java 1520
 * Description: Defines ShiftSupervisor class, a subclass of the Employee class.
 */
package Lab3;
import java.text.DecimalFormat;
public class ShiftSupervisor extends Employee{
    
  //Initializes private data fields.  
  private double annualSalary = 45000.00;
  private double annualProductionBonus = 0.00;
  
  //Utilizes no argument constructor.
  protected ShiftSupervisor(){
    
      
  }
  //Mutates annualSalary, a private data field. Provides data verification.
  public void setAnnualSalary(String salary){
    boolean verified = false;
    double annualSalary;
    while (!verified){
      verified = VerificationMethods.isDouble(salary);
      if (!verified){
        System.out.println("Please enter a currency amount. Ex-45200.00: ");
        salary = input.next();
      }
    }
    annualSalary=VerificationMethods.makeDouble(salary);
    this.annualSalary=annualSalary;
  }  

  //Accesses private data field: annualSalary
  public double getAnnualSalary(){
    return this.annualSalary;
  }
  
  //Verifies and changes private field, annualProductionBonus.
  public void setAnnualProductionBonus(String productionBonus){
    boolean verified = false;
    double annualPBonus;
    while (!verified){
      verified = VerificationMethods.isDouble(productionBonus);
      if (!verified){
        System.out.println("Please enter a currency amount. Ex-5200.00: ");
        productionBonus = input.next();
      }
    }
    annualPBonus=VerificationMethods.makeDouble(productionBonus);
    this.annualProductionBonus = annualPBonus;
  }  

  //Provides access to annualProductionBonus data field.
  public double getAnnualProductionBonus(){
    return this.annualProductionBonus;
  }
  
  //Utilizes an overriden toString to display the Employee and Shift Supervisor
  //attributes of this object.
  @Override
  public String toString(){
    DecimalFormat formatted = new DecimalFormat("#0.00");  
    String result = super.toString() + "Annual Salary: $" + formatted.format(getAnnualSalary()) + "\n"
                   + "Annual Production Bonus: $" + formatted.format(getAnnualProductionBonus());
    return result;
  }
}
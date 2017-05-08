/*
 * File: TestInheritanceClasses.java
 * Author: Donna Walker
 * Date: 3/20/15
 * Class: Java 1520
 * Description: Tests all the classes that have inheritance from the Employee class.
 */
package Lab3;
import java.util.*;

public class TestEmployees{
  Scanner input = new Scanner(System.in);
  public static void main(String[] args){ 
    //Initializes variables and displays user interface explaining the program's purpose.   
    Scanner input = new Scanner(System.in);        
    System.out.println("Welcome to Acme Production Human Resource System.");
    System.out.println("Please ensure that you verify new employee information before entering.");
    
    //Invokes newEmployee and assignWorker to identify the type of object being 
    //created, initialize the object and invoke a method to use the setter methods for validation.
    int workerType = newEmployee();
    assignWorker(workerType);
    
  }
  
  //Allows the HR employee to identify the type of new employee.
  public static int newEmployee(){
    boolean verified = false;
    int workerType=0;
    Scanner input = new Scanner(System.in); 
    System.out.println("\nFirst, confirm the TYPE of employee you are adding: ");
    System.out.println("\n1. Production Worker");
    System.out.println("2. Team Lead");
    System.out.println("3. Shift Supervisor");
    System.out.println("Please enter 1,2, or 3 to correspond to the menu above: ");

    //Verifies input validity catches error and processes in applicable.
    do{
      try{
        workerType = input.nextInt();
               
        if (workerType==1 || workerType==2 || workerType==3)
          verified=true;
        else{
          System.out.println("Please enter a 1,2, or 3: ");
          
        }
      }  
      catch(InputMismatchException e){
        System.out.println("Must be an integer.");
          input.nextLine();      
      }
    }while(!verified);
    return workerType;

  }
  
  //Initializes an Employee object based on the worker type identified.
  //Calls getEmpInfo to initialize the non-default data for the object.
  public static Object assignWorker(int workerType){
    boolean verified = false;
    Employee x = new Employee();
    while (!verified){   
      if (workerType==1){
        ProductionWorker object1 = new ProductionWorker();
        verified = true;
        getEmpInfo(object1, workerType);
        break;
      }
      else if (workerType==2){
        TeamLead object2 = new TeamLead();
        verified = true;
        getEmpInfo(object2, workerType);
        break;
      }
      else if (workerType==3){
        ShiftSupervisor object3 = new ShiftSupervisor();
        verified = true;
        getEmpInfo(object3, workerType);
        break;
      }
      else{
        getEmpInfo(x, workerType);
      }
    }
    return x;  
  }
     
  //Utilizes polymorphism, instanceof and casting to assign the appropriate
  //values to the various types of employees.
  public static void getEmpInfo(Employee o, int workerType){
    Scanner input = new Scanner(System.in);  
    System.out.print("Please enter the employee's first name: ");
    String fname = input.next();
    System.out.print("Please enter the employee's middle initial: ");
    String mInt = input.next();
    System.out.print("Please enter the employee's last name: " );
    String lName = input.next();
    o.setName(fname, mInt, lName);
    System.out.println("Please enter the Employee number: This should be three numbers,"
            + "followed by a dash and a captial letter between A and M. Ex - 333-B : ");
    String empNumber = input.next();
    o.setEmployeeNumber(empNumber);
         
  
    //Uses set methods to validate data as assigned to each class.
    //Initializes values specific to the ProductionWorker class.
    if (o instanceof TeamLead){
      TeamLead tl = (TeamLead)o; 
      System.out.print("Please enter the Team Lead's bonus amount. ex- 200.00 : "); 
      String bonusAmount = input.next();
      tl.setMonthlyBonusAmount(bonusAmount);
      
      //NOTE:Enters bad data in default fields hireDate, required training hours and actual training hours to show
      //validation would work if values were entered. These are defaulted fields in the regular program.
      tl.setHireDate("01/15/dd");     
      tl.setRequiredTrainingHours("d5");
      tl.setActualTrainingHours("d");
    }
      if (o instanceof ProductionWorker){
      ProductionWorker pw =(ProductionWorker)o;  
      System.out.print("Please enter the employees shift. 1 for Day or 2 for Night: ");
      String shift = input.next();
      pw.setShift(shift);
      System.out.print("Please enter the hourly payrate, ex- 8.75 : ");
      String hourlyPayRate = input.next();
      pw.setHourlyPayRate(hourlyPayRate);
      System.out.print(pw);
    }  
    //Initializes values specific to ShiftSupervisor classes
    if (o instanceof ShiftSupervisor){
      ShiftSupervisor ss = (ShiftSupervisor)o;  
      System.out.println("Please enter the Shift Supervisor's annual salary. Ex- 54000.00 : ");
      String annualSalary = input.next();
      ss.setAnnualSalary(annualSalary);
      System.out.println("Please enter the Shift Supervisor's annual production bonus. For a "
              + "new hire, this figure should be '0.00'. Ex- 2250.00");
      String productionBonus = input.next();
      ss.setAnnualProductionBonus(productionBonus);
      System.out.print(ss);
    }
  }
}
  
  
 
    
    
   

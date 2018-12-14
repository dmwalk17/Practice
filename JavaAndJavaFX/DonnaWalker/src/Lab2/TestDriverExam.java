/*
 * File: TestDriverExam.java
 * Author: Donna Walker  
 * Date: 2/22/2015
 * Class: Java 1520
 * Description:  Tests the DriverExam class to demonstrate the creation of 
 * DriverExam object, validation of data, acceptance of valid answers, performs  
 * grading functions, and displays total correct, total incorrect, questions missed,
 * and an overridden toString output.   
 */
package Lab2;
import java.util.Scanner;

public class TestDriverExam {
    
  public static void main(String[] args){ 
      
    //Initializes scanner  
    Scanner input = new Scanner(System.in);  
    String start;
    
    //Asks if the user is ready to input their answers.
    System.out.print("Have you completed your exam? (Y/N): "); 
    start = input.next(); 
    
    //Creates an object if it is time to validate and grade the exam.
    //Calls createObject to initiate DriverExam methods. Displays overridden toString format of object data.
    if (start.charAt(0)== 'y' || start.charAt(0)== 'Y'){
         DriverExam a = new DriverExam();
         a.createObject();
         System.out.print(a);
    }
    
    //Informs the user they must be ready to grade their exam to continue.
    else{
      System.out.println("Come back when you are ready to grade your exam.");
    }
  }
}


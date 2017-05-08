/*
 * File: DriverExam.java
 * Author: Donna Walker
 * Date: 2/22/2015
 * Class: Java 1520
 * Description: Defines a DriverExam class that identifies the individual, reads
 * in the exam answers and grades them based on the key. Also provides feedback
 * for wrong answers including: status of passed, totalCorrect, totalIncorrect,
 * and questionsMissed with feedback. Displays object content in an overridden toString.
 */
 
package Lab2;
import static Lab2.ArrayTestMethods.testValid;
import java.text.DecimalFormat;
import java.util.*;

public class DriverExam {
  static Scanner input = new Scanner(System.in);  
  private final char[] KEY = {'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D', 'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A'}; 
  private StringBuilder driverName = new StringBuilder();
  private StringBuilder tempDriverName = new StringBuilder();
  private StringBuilder finalAnswers;
  private int numberRight;
  private int numberWrong;
  private boolean driverLicense;
  private int driverLicenseIndex = 54000000;
  private static int numberOfObjects = 0;
  private int driverLicenseNumber;
  private String dateOfExam; 
  private static final int NUMBER_OF_QUESTIONS = 20;
  private static final int NUMBER_WRONG = 5;
  
  //Default constructor for DriverExam
  public DriverExam(){  
    this.driverName = driverName.append(setIdentity());
    this.finalAnswers = getAnswers();
    this.dateOfExam = new java.util.Date().toString();      
  }
   
  //Provides input string for the object attribute of driverName. 
  public StringBuilder setIdentity(){
    String tempFirst="", tempMiddle="", tempLast=""; 
    return verifyIdentity(tempFirst, tempMiddle, tempLast);
  }
  
  //Gets and verifies user input for test taker's identity for each object
  public StringBuilder verifyIdentity(String tempFirst, String tempMiddle, String tempLast){
    boolean verify = false;
    String verName;
    while (verify==false || tempFirst==null || tempLast==null){
      System.out.println("Your name must include only letters with no spaces, and only one letter for middle initial.");
      System.out.println("Example: Your O Name");
      System.out.print("Please enter your first name: ");
      tempFirst = input.next();
      System.out.println("Please enter your middle initial: ");
      tempMiddle = input.next();
      System.out.println("Please enter your last name: ");
      tempLast = input.next();
      System.out.print("Is your name: " + tempFirst + " " + tempMiddle + " " + tempLast + "? (Yes or No)");
      verName = input.next();
      if (verName.charAt(0)=='y' || verName.charAt(0)=='Y'){
        //Calls testIdentity to test the validity of the confirmed user input  
        tempDriverName = ArrayTestMethods.formatIdentity(tempFirst, tempMiddle, tempLast);
        verify = testValid(tempDriverName);
      }
    }
    
    return tempDriverName;
  }
  
  //Takes answers for all 20 questions of the exam. Tests input validity and 
  //gives error if input is not valid
  public StringBuilder getAnswers(){
    StringBuilder finalAnswers = new StringBuilder();
    for(int num=0;num<20;){
      System.out.println("Please enter your answer to Question "+ (num+1) + ":");
      String answer = input.next();
      
      //Changes all letters to uppercase to simply validity check.
      answer = answer.toUpperCase();
      
      //Tests to ensure the letters are in the domain of validity. Repeats question if invalid data given.
      if (answer.length()>1 || answer.charAt(0) < 'A'|| answer.charAt(0)>'D'){
        System.out.println("Invalid input. Please enter one character of: A,B,C,or D");
      }
      else{
        finalAnswers.append(answer);
        num++;
      }
    }
    return finalAnswers;
  }
  
  //Compares user answers to the key. Adds question numbers with wrong answers to an array.
  public ArrayList gradeAnswers(char[] KEY, StringBuilder finalAnswers){
    ArrayList<Integer>wrong = new ArrayList<>();
    for (int i =0; i<20; i++){
      if (KEY[i]!= finalAnswers.charAt(i)){
        wrong.add(i); 
          
        //Simulates advice on correct answers like a real exam, if the answer is wrong
        OutputMethods.wrongAnswers(i, KEY, finalAnswers);
      }
    }
    return wrong;
  }
  
  //Tabulates the number of correct answers by subtracting number wrong from total questions. 
  public int totalCorrect(ArrayList wrong){
    numberRight = NUMBER_OF_QUESTIONS - wrong.size();
    return numberRight;
  }
  
  //Uses the length of arrayList wrong to tabulate the number of wrong answers.
  public int totalIncorrect(ArrayList wrong){
    numberWrong = wrong.size();
    return numberWrong;
  }        
  
  //Compares the number of actual wrong answer to the number of allowed wrong answers to 
  //determine if the person passed. 
  public boolean passed(ArrayList wrong){
    boolean passed; 
    if (numberWrong>NUMBER_WRONG){
      System.out.println("You did not pass.");
      passed = false;
    }
    else{
      System.out.println("You passed!! Time to take your road test!");
      numberOfObjects++;
      this.driverLicenseNumber = driverLicenseIndex + numberOfObjects;
      System.out.println("If you pass your road test, your license number will be: "+ this.driverLicenseNumber);
      passed = true;
    } 
    System.out.println("You got " + numberRight + " right, and " + numberWrong + " wrong.");
    listWrong(wrong);
    return passed;
  }
 
  
  //Displays a list of the questions that were answered wrong, if any exist.
  public void listWrong(ArrayList<Integer> wrong){
    if (wrong.isEmpty())
      System.out.println(" ");
    else{
      System.out.print("You got the following questions wrong: ");
      for (int i=0; i<wrong.size(); i++){
        System.out.print((wrong.get(i) + 1) +", ");
      }
      System.out.print("\n");
    }      
  }
  
  //Calls methods to grade the given answers, tabulate total correct and incorrect,
  // and track if the person passed the test.
  public boolean createObject(){
       
    ArrayList<Integer> wrong = gradeAnswers(KEY, finalAnswers);
    int totalCorrect = totalCorrect(wrong);
    int totalIncorrect = totalIncorrect(wrong);
    this.driverLicense = passed(wrong);
    return this.driverLicense;
  }
  
  //Displays a formatted version of the attributes of the object for lookup
  @Override
  public String toString(){
    String result;  
    if (driverLicense){  
      result = "\nDriver's name is "+ this.driverName+"\n";
      result += "Driver's exam date is: " + this.dateOfExam+"\n";
      result += "Exam passed? " + this.driverLicense+"\n";
      result += "When road test passed, driver's license number will be: " + this.driverLicenseNumber+"\n";
    }
    else{
      result = "\nDriver's name is "+ this.driverName + "\n";
      result += "Driver's exam date is: " + this.dateOfExam + "\n";
      result += "Exam passed? " + this.driverLicense + "\n";  
    }
      
    return result;
       
  }
} 
 
 
 
/*
 * File: OutputMethods.java
 * Author: Donna Walker
 * Class: Java 1520
 * Description: Method library for methods dealing with output.
 * 
 */
package Lab2;


public class OutputMethods {

  //Takes an int value and prints the number (1-10) in a word output. If more 
  //than 10, prints number value.  
  public static void numberWord(int i){
    switch (i){
      case 0: System.out.print("no "); break;
      case 1: System.out.print("one "); break;
      case 2: System.out.print("two "); break;
      case 3: System.out.print("three "); break;
      case 4: System.out.print("four "); break;
      case 5: System.out.print("five "); break;
      case 6: System.out.print("six "); break;
      case 7: System.out.print("seven "); break;
      case 8: System.out.print("eight "); break;
      case 9: System.out.print("nine "); break;
      case 10: System.out.print("ten "); break;
      default: System.out.print(i+ " ");    
    }  
  }
  
  //Mimics quiz output for wrong answers on a driving test for up to 20 answers.
  public static void wrongAnswers(int index, char[] KEY, StringBuilder answer ){
             
    System.out.println("Your answer of " + answer.charAt(index) + " on question " + ((index)+1) +
        " was incorrect. The correct answer was " + KEY[index] + ". Please note:");
       
    switch (index){
      case 0: System.out.println("Because you wanted a better view of the wreck is *not* a reason to stay in the lane nearest to a traffic stop.\n"); break;  
      case 1: System.out.println("It is never appropriate to drive with your lights off at night."); break;
      case 2: System.out.println("You cannot run red lights, even if you are running late for work"); break;
      case 3: System.out.println("Driving a BMW does not give you ultimate right-of-way."); break;
      case 4: System.out.println("You must stop at a stop sign. A California rolling stop is not good enough."); break;
      case 5: System.out.println("You *can* get a ticket for putting on makeup while you are driving."); break;
      case 6: System.out.println("While really dark-tinted windows are cool. Legally, it is an equipment violation."); break;
      case 7: System.out.println("Even if you have no malicious intent, driving the wrong way on a one-way street is still a moving violation."); break;
      case 8: System.out.println("You should never drive yourself to the hospital when you are bleeding severly! This is why they have ambulances."); break;
      case 9: System.out.println("Texting and driving is not ok just because your mother says it is."); break;
      case 10: System.out.println("It is not ok to put emergency lights on your own car to get ahead of the rush hour traffic."); break;
      case 11: System.out.println("Yes. Your mother may have told you that your special, but you can't park in a handicapped space without an government-issued placard."); break;
      case 12: System.out.println("No. Standing on your head is not an approriate driving position. We were looking for hands at 10 and 2."); break;
      case 13: System.out.println("The 'D' on your car's dash display stands for Drive, not Drunk."); break;
      case 14: System.out.println("New Year's Eve is not a holiday from DUI laws."); break;
      case 15: System.out.println("A broken fingernail does not constitute an 911 emergency."); break;
      case 16: System.out.println("Declaring yourself a Sovereign Citizen does not exempt you from paying your vehicle registration."); break;             
      case 17: System.out.println("Driving 50 mph in a 20 mph school zone is wreckless driving, not making good time."); break;
      case 18: System.out.println("If your license plate is expired, you should pay your vehicle registration, not switch tags with someone else."); break;
      case 19: System.out.println("If pulled over, you should remain in the car and act in a polite manner, not speed-dial your attorney and pull out your gun."); break;
      default: System.out.println("If you have received this answer, there is something really, really wrong with this program!");    
             
    }
  }
}
    


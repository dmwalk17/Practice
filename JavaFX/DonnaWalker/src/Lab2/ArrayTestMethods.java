/*
 * File: ArrayTestMethods.java
 * Author: Donna Waker
 * Date: 2/22/15
 * Class: Java 1520
 * Description: Library of various array methods for use with other programs. 
 */
package Lab2;
import java.util.*;

public class ArrayTestMethods {

  //Accepts a line of text from the keyboard and converts the input into a char array.
  public static char[] getStringToCharInput(){
    Scanner input = new Scanner(System.in);
    System.out.println("Enter a line of text. The program will count the letter usage. Ex - one 'a,' etc.: ");
    char[] textLine = input.nextLine().toCharArray();
    return textLine;
  }  
  
  //Initializes an integer array to hold the count for each letter of the 
  //alphabet used a char array. Ignores non-letters.
  public static int[] countLetters(char[] textLine){
    int[]counts = new int[26];
    for (int i = 0;i<textLine.length; i++){
      if (Character.isLetter(textLine[i]))  
      counts[textLine[i] - 'a']++;
    }  
    return counts;
  }   

  //Uses an int array to hold the location of non-letters within a char array
  public static int[] verifyLettersWithIndex(char[] text){
    int[] nonLetterIndex = new int[text.length];  
    for (int i = 0; i<text.length;i++){
      if (!Character.isLetter(text[i])) {
          nonLetterIndex[i]=1;
      }
    }
    return nonLetterIndex;
  }
    
  // Takes in name as three strings. Ensures proper capitalization and feeds into a 
  // single StringBuilder with spaces as a delimiter. Tests validity and returns formatted full name. 
  public static StringBuilder formatIdentity(String fName, String mInitial, String lName){
    StringBuilder fullName = new StringBuilder();
    StringBuilder tFirst = new StringBuilder(fName);
    char tMiddle = mInitial.charAt(0);
    StringBuilder tLast = new StringBuilder(lName);
    tFirst = lowCaseFormat(tFirst);
    tLast = lowCaseFormat(tLast);
    tFirst.setCharAt(0, Character.toUpperCase(tFirst.charAt(0)));
    tMiddle = Character.toUpperCase(tMiddle);
    tLast.setCharAt(0, Character.toUpperCase(tLast.charAt(0)));
    fullName.append(tFirst + " ");
    fullName.append(tMiddle + " ");
    fullName.append(tLast);
    return fullName;
      
}
  //Takes and returns a StringBuilder setting all letters to lower case.
  public static StringBuilder lowCaseFormat(StringBuilder name){
    StringBuilder tempString = new StringBuilder(name.length());
    for (int i = 0; i<name.length();i++){
      tempString.append(Character.toLowerCase(name.charAt(i)));
    }
    return tempString;  
  }
  
  //Tests a StringBuilder to ensure it only has letters and spaces in it, and returns a boolean value.
  public static boolean testValid(StringBuilder temp){
    for (int i=0; i<temp.length(); i++){
      if (((Character.isLetter(temp.charAt(i))) || (Character.isSpaceChar(temp.charAt(i))))){
        //This conditional is the one where NetBeans would not accept a '!' not operator. 
      }       
      else{
        return false;
      }   
  
    }
    return true;  
  }
  
  public static boolean testNameValid(String temp){
    for (int i=0; i<temp.length(); i++){
      if (Character.isLetter(temp.charAt(i))){
        //This conditional is the one where NetBeans would not accept a '!' not operator. 
      }       
      else{
        return false;
      }   
  
    }
    return true;  
  }
}
/*
 * File: AlphabetCount.java
 * Author: Donna Walker
 * Date: 2/23/2014
 * Class: Java 1520
 * Description: Reads a line of text from the keyboard and prints indicating the  
 * number of occurences of each letter of the alphabet in the text.
 */
package Lab2;

public class AlphabetCount {
  public static void main(String[] args){  
    
    //Calls method to get user-inputted line of data.  
    char[] textLine = ArrayTestMethods.getStringToCharInput();
    
    //Converts the characters to lower case to simplify counting
    for (int i=0; i<textLine.length;i++){
      textLine[i]=Character.toLowerCase(textLine[i]);
    }  
    
    //Initializes array to hold letter counts and calls method to count and return them.
    int [] counts = ArrayTestMethods.countLetters(textLine);
    
    //Initializes variable for letter display according to given format in the lab assignment. 
    char alpha = 'a';
    System.out.print("Contains ");
    
    //Utilizes a loop to display all the letters and their counts.
    for (int i=0;i<26;i++){
      
      //Uses an output method to write out words of ten or less.  
      OutputMethods.numberWord(counts[i]);
      
      //Varies the display to pluralize for counts over one.
      if (counts[i]==1){
        System.out.print("\""+alpha + ",\" ");
      }  
      else{
        System.out.print("\""+alpha + "\'s,\" ");
      }  
      if (i%5==0&&i>0)
        System.out.println();
      alpha++;
    }
  }
}
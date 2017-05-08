/*
 * File: WalkerD_lab3
 * Author: Donna Walker  Java_1520
 * Description: Creates file MyFile.txt, if it doesn't already exist. Writes 100 
 * randomly generated integers into the file, separating the numbers with spaces. 
 * Reads data results back from the file and displays the numbers after sorting.
 */
package Lab3;
import java.io.*;
import java.util.*;
public class WalkerD_lab3 {
  public static void main(String[] args) throws Exception{
    //Declares integer array and file for processing.  
    int[] myInts = new int[100];  
    File file = new File("MyFile.txt");
    
    //Tests to see if file has been previously produced.
    if (file.exists()){
      System.out.println("File already exists");
      System.exit(0);
    }
    //Calls methods to write to file, read from file and sort numbers for display.
    writeFile(file);
    myInts = readFile(file);
    sortInts(myInts);  
    }
    
  //Writes 100 randomly generated integers seperated by spaces into MyFile.txt. 
  public static void writeFile(File file) throws FileNotFoundException {
    
    //  
    try(
      PrintWriter output = new PrintWriter(file)){
      for (int i=0;i<100;i++){
        output.print(((int)(Math.random()*100))+ " ");
      }
      
    }
    catch (FileNotFoundException ex) {
      System.out.println(ex);
    }
    
  }
  //Reads 100 integers from file MyFile.txt into an array. Returns array for processing. 
  public static int[] readFile(File file) throws FileNotFoundException{
    int[] temp = new int[100];  
    try{
      Scanner input = new Scanner(file);
      while (input.hasNext()){
        for(int i=0;i<100;i++){
          temp[i] = input.nextInt();  
        }
      }
    }  
    catch (FileNotFoundException ex){
      System.out.println(ex);      
    }
    return temp;  
          
  }
  //Sorts and displays integer array to screen.
  public static void sortInts(int[] myInts){
    Arrays.sort(myInts);
    for (int numbers: myInts){
      System.out.print(numbers + " ");
    }
  }
}
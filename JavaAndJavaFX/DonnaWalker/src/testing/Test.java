/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testing;

import javafx.application.Application;
import javafx.stage.Stage;

public class Test extends Application {
  public Test(){
    System.out.println("Test constructor is invoked");
  }
  public void start(Stage primaryStage){
    System.out.println("start method is imvoked");
    
  } 
  public static void main(String[] args){
    System.out.println("launch application");
  }
}

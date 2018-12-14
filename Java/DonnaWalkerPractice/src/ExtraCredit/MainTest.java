/*
 * MainTest tests the Payer and Team classes.
 */
package ExtraCredit;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;


public class MainTest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        String menuChoiceLine;
        char menuChoice;
        Scanner input = new Scanner(System.in);
        
        Team dreamTeam = new Team();
        Player selectedPlayer = new Player();   
        dreamTeam.setName("Tennessee Smokies");
        
        int userOption = 0;

        
        while(userOption != 4){
            menuChoiceLine = "";
            
            System.out.println("\nWelcome to Team Manager Administion and Stats App!"
                + "Use the following menu to maintain your Team and Player information!");
        
            System.out.println("Enter a number from the menu below: " );
            System.out.println("1 - Print roster");
            System.out.println("2 - Look in roster for player by number");
            System.out.println("3 - Sort roster by number");
            System.out.println("4 - Quit");
        
            menuChoiceLine = input.next();
            menuChoice = menuChoiceLine.charAt(0);
            if(Character.isDigit(menuChoice)){
                int menuNumber = Character.getNumericValue(menuChoice);
                if(menuNumber < 1 || menuNumber > 4){
                    System.out.println("\nPlease choose a number from the menu. " + menuChoice );
                
                }
                else if(menuNumber == 1){
                dreamTeam.printRoster();
                }
                else if (menuNumber == 2){
                   
                    selectedPlayer = null;
                    System.out.println("\nPlease provide a player number: ");
                
                    int playerNumber = input.nextInt();
                    selectedPlayer = dreamTeam.search(playerNumber); 
                    
                    if(selectedPlayer.name == ""){
                            System.out.println("Player not found in team roster.");
                    }else{
                            System.out.println(selectedPlayer.toString());
                    }
                        
                }
                        
                else if (menuNumber == 3){
                    Arrays.sort(dreamTeam.players);
                    System.out.println("Team players have been sorted by number.");
                }
                else if (menuNumber == 4){
                    
                    System.out.println("Thank you for using Team Manager Administration and Stats App! Goodbye!");
                    userOption = 4;
            }
        }
        else{
            System.out.print("You must enter a valid number.\n");
        }
        
    }
        
        
              Player one = new Player("Yogi", 11,0.111);
        Player two = new Player("Magilla", 22, 0.222);
        Player three = new Player("Martin Martian", 0, 0.445);
        Player four = new Player("Yosimite", 99, 0.001);
        Player five = new Player("Wiley", 44, 0.044);
        Player six = new Player("Runner", 69, 0.888);
        Player seven = new Player("Daffy", 33, 0.122);
        Player eight = new Player("Taz", 66, 0.666);
        Player nine = new Player("Foghorn", 23, 0.121);
        Player newOne = new Player("Bugs", 0,0.555);
        Player[] newTeam = new Player[9];
        Player[] blankTeam = new Player[9];
        newTeam[0] = one;
        newTeam[1] = two;
        newTeam[2] = three;
        newTeam[3] = four;
        newTeam[4] = five;
        newTeam[5] = six;
        newTeam[6] = seven;
        newTeam[7] = eight;
        newTeam[8] = nine;
        Team secondTeam = new Team(blankTeam);
        secondTeam.setPlayers(newTeam);
        secondTeam.setName("Daffy's Drivers");
        System.out.println(secondTeam.toString() + "\n");
        secondTeam.printRoster();
        
        Team thirdTeam = new Team(newTeam, "Bug's Bunnies");
        newTeam[6].setName("Bugs");
        newTeam[6].setNumber(77);
        newTeam[6].setBattingAverage(0.777);

        thirdTeam.printRoster();
        
        

        

    
    }
}

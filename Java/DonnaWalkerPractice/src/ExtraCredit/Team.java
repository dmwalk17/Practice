/*
 * Team class: Defines and implements the Team object.
 */
package ExtraCredit;

import java.util.Arrays;

/**
 *
 * @author Donna
 */
public class Team {
    

    String name;
    final int MIN_NUM_PLAYERS = 9;
    final String DEFAULT_NAME = "";
    Player[] players = new Player[MIN_NUM_PLAYERS];
    
    public Team(){
        players[0] = new Player("Berra", 8,0.285);
        players[1] = new Player("Ryan", 34, 0.0);
        players[2] = new Player("Aparicio", 11, 0.262);
        players[3] = new Player("Pujols", 5,0.328);
        players[4] = new Player("Jackson", 9, 0.262);
        players[5] = new Player("Schoendienst", 10, 0.289);
        players[6] = new Player("Carew", 29, 0.328);
        players[7] = new Player("Aaron", 44, 0.305);
        players[8] = new Player("Mantle", 7, 0.298);
    }
    
    public Team(Player[]p){
        if(p.length == MIN_NUM_PLAYERS){
        this.name = DEFAULT_NAME;
        this.players = Arrays.copyOf(p,p.length);
        } else{
            System.out.println("Teams must have exactly 9 players");
        }
    }
    
    public Team(Player[]p, String name){
        if(p.length == MIN_NUM_PLAYERS){
        this.name = name;
        this.players = Arrays.copyOf(p,p.length);
        } else {
            System.out.println("Teams must have exactly 9 players");
        }
    }
    
    public void setName(String newName){
        this.name = newName;
    }
    
    public String getName(){
        return this.name;
    }

    public void setPlayers(Player[] p){
        this.players = Arrays.copyOf(p, p.length);
    }

    public Player[] getPlayers(){
        return this.players;
    }

    @Override
    public String toString(){
        String output = "Team Name: " + this.getName();
        return output;
    }
    

    

    
    public void printRoster(){
        this.players = this.getPlayers();
        System.out.println(this.getName() + " Roster");
        System.out.println("Name\t\tNumber\t\tBA");
        System.out.println("--------------------------------------------");
        for(int i = 0; i<MIN_NUM_PLAYERS;i++){
            System.out.print(players[i].name);
            if(players[i].name.length() > 7){
              System.out.print("\t");}
            else{
                System.out.print("\t\t"); 
            }
            System.out.println(players[i].getNumber() + "\t\t" + players[i].getBattingAverage()  
                    );
        }
        System.out.println("\n");
    }
    public Player search(int playerNumber){
        Player selectedPlayer = new Player();
                            for(int i=0;i<this.players.length;i++){
                            
                              if(this.players[i].number == playerNumber){
                                    selectedPlayer = this.players[i];
                              }
                        }
               return selectedPlayer;         

    }
}

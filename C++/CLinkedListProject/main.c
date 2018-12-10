/*
 * File: main.c
 * Author: Donna Walker
 * Date: 10/8/2018
 * This program reports, buys and sells stock that is retained in a binary file
 * within the current directory, formatted- "STOCK.bin".
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include "stock.h"
#include "date.h"
#include "node.h"
#include "linkedList.h"

//prototypes
void printMenu();//prints main menu
void printBye();//prints farewell statement
void printSummaryHeader();//prints summary of stocks owned & amount
void printDetailHeader();//prints header for stock detail report
void summaryReporting();//prints stock summary report 
void printDetail(const char stockChoice[]); //prints stock detail report
void buyStock(); //buys stock
void sellStock(); //loads link list and takes details of stock sale
void processSale(linked_list_t* listPtr); // changes linked list to remove sold stocks
void makeUpper(char fileName[]); //helper function to meet stock naming convention (STOCK.bin)


int main( ){

    int menuChoice = -1;
    int valid;
    char stockChoice [MAX_TICKER_LENGTH];
    printf("Welcome to YourTrade.com\n");
    do{
        printMenu();
        valid = scanf("%d", &menuChoice);


        if(menuChoice == 1){//reporting
            summaryReporting();
            printf("Enter stock ticker symbol: ");
            scanf("%s", stockChoice);
            fflush(stdout);
            printDetail(stockChoice);
        }
        else if(menuChoice == 2){//buying
            buyStock();
        }
        else if(menuChoice == 3){//selling
            sellStock();

        }     
        else if(menuChoice != 0 && valid == 1){//handles invalid numbers
            printf("Invalid menu choice.\n");
        }
        else if(valid != 1 ){//handles chars
            while(getchar() != '\n');
            printf("Invalid menu choice.\n");
        } 
    }while(menuChoice != 0);//while not quit
    
    printBye();
    return 0;
}

/* printMenu:       Prints the user selection menu for a transaction type
 * Parameters:      none
 * Postcondition:   Ends without end of line awaiting user input
 * returns:         nothing
 */
void printMenu(){
    printf("Reporting, buying or selling?\n");
    printf("(0=quit, 1=report, 2=buy, 3=sell): ");
    fflush(stdout);

}

/* printBye:        Gives a farewell message when the user exits the main tranaction menu
 * Parameters:      none
 * returns:         nothing
 */
void printBye(){
    printf("Thank you for trading with YourTrade.com\n");
    fflush(stdout);
}

/* printSummaryHeader:  Prints a formatted header for the summary report
 * Parameters:      none
 * returns:         nothing
 */
void printSummaryHeader(){
    int filler = '-';
    int width = 12;
    int i;
    printf("Stocks Owned\n");
    for(i = 0; i < width; i++){
        putchar(filler);
    }
    printf("\n");
    fflush(stdout);
}

/* printDetailHeader:   Prints a formatted header for the single stock detail report
 * Parameters:          none
 * returns:             nothing
 */
void printDetailHeader(){
    int filler = '-';
    int width = 45;
    int i;
    printf("Ticker  Purchase Date Shares Price Per Share\n"); 
    for(i = 0;i<width;i++){
        putchar(filler);
    }
    printf("\n");
    fflush(stdout);

}

/* summaryReporting:    Prints summary of name and # of shares of all stocks owned
 * Parameters:          none
 * Postcondition:       Ends without /n to prompt user for file input
 * returns:             nothing
 */
void summaryReporting(){
    char name[MAX_TICKER_LENGTH];
    name[0] = '\0';
    DIR* dirPtr;
    struct dirent* dirEntry; 
    double portfolioValue = 0;
    dirPtr = opendir( "." );
    printSummaryHeader(); 

    //Checks local directory for all stock files (*.bin), 
    while((dirEntry = readdir( dirPtr )) != NULL ) {
        int sum = 0;
        double stockValue = 0;
        stock_t s;
        FILE* in;
        
        //Reads all the stocks in the bin files to sum the number of shares
        if(strstr(dirEntry->d_name,".bin") != NULL){
                    
            in = fopen(dirEntry->d_name, "rb");
            if(in == NULL){//stock found but couldn't open
                printf("Error accessing stock\n");
                fflush(stdout);
            }
            else{ //get sum of each stock 
                fread(&s,sizeof(stock_t), 1,in);
                while(!feof(in)){
                            
                    sum += s.numShares;
                    stockValue += s.numShares * s.pricePerShare;    
                    fread( &s, sizeof( stock_t), 1, in);
                           
                }    
                //Takes ".bin" off file leaving  stock name to print along with total of each stock                              
                strncpy(name, dirEntry->d_name,strlen(dirEntry->d_name)-4);
                printf("%-8s%4d     $%10.2lf\n", name, sum, stockValue);
                fflush(stdout);
                portfolioValue += stockValue;
                memset(name,0,strlen(name));
                fclose(in);
           }
        } 
    }
    printf("Porfolio Value:$%12.2lf\n", portfolioValue);
    fflush(stdout);
    closedir(dirPtr);
}  

/* printDetail:     Reads a stock file and prints out details for one user selected stock
 * Parameters:      stockChoice - the user selected stock name to detail
 * returns:         nothing
 */
 void printDetail(const char stockChoice[]){
    
    char fileName [10];
    DIR* dirPtr;
    struct dirent* dirEntry;
    stock_t s; 
    int flag=0;
    dirPtr = opendir( "." );
    
    //Processed user choice into file name (adds .bin)
    strcpy(fileName, stockChoice);
    makeUpper(fileName);
    strcat(fileName, ".bin");    
    

    //Searches to see if the user has this stock    
    while((dirEntry = readdir( dirPtr )) != NULL ) {
        FILE* in;
        //if exists, reads and prints each stock's details
        if(strstr(dirEntry->d_name, fileName) != NULL){
            flag = 1;
            printDetailHeader();
            in = fopen(fileName, "rb");
            if(in == NULL){//stock found but error opening
                printf("Error accessing stock.");
                
            } 
            else{//print all stock purchases for one stock
                fread(&s,sizeof(stock_t),1,in);
                while(!feof(in)){
                    printStock(s);//function in stock.c
                    fread(&s, sizeof(stock_t),1,in);
             
                }   
                fflush(stdout);
                fclose(in);
            }
        }
                
    }
    if(!flag){//uses sentinal value to determine if stock was found 
        printf("Stock not found.\n");
        fflush(stdout);
    }

    closedir(dirPtr);
}

/* buyStock:        Processed a stock purchase request and appends to file
 * Parameters:      none
 * returns:         nothing
 */
void buyStock(){
    FILE* out;
    stock_t s;
    char fileName[MAX_TICKER_LENGTH+4] = "\0";
    getStock(&s); //function in stock.c requests stock buy info
    printf("BUY: %5d shares of %-5s @ $%7.2lf\n", s.numShares, s.ticker, s.pricePerShare);     
    strcat(fileName, s.ticker); //puts together filename for write
    strcat(fileName, ".bin");

    out = fopen(fileName, "ab"); //prepare to write purchase to file
    fwrite(&s, sizeof(stock_t), 1,out);
    
    fclose(out);
}

/* sellStock:           Takes user request to sell stock, reads and writes stocks to file, if approrpriate.
 *                      Puts stocks into linked list to process oldest stock first, if owned. 
 * Parameters:          none
 * Post-conditional:    Linked list is deallocated at the end of this function. Can no longer be referenced.
 * returns:             nothing
 */
void sellStock(){
    FILE* in;
    FILE* out;
    linked_list_t list;
    linked_list_t* listPtr;
    listPtr = &list;  
    createList(listPtr);  
    char fileName[MAX_TICKER_LENGTH+4] = "/0"; 
    int sum;

    //Takes user provided stock and transitions to file name
    printf("Enter symbol for stock to sell: ");
    scanf("%s", fileName);
    fflush(stdout);
    makeUpper(fileName);
    strcat(fileName, ".bin");
   
    //checks if stock file exists and reads into linked list if present
    in = fopen(fileName, "rb");
    if(in == NULL){
        printf("You don't appear to own this stock.\n");
        fflush(stdout);
    } 
    else {
        node_t* nodePtr;
        stock_t s;
        fread(&s, sizeof(stock_t), 1, in);
        while(!feof(in)){
            nodePtr = initNode(&s); 
            insertNode(listPtr, nodePtr);
            fread(&s, sizeof(stock_t), 1, in);
        }
        fclose(in);

        processSale(listPtr);  //manipuates linked list to removed sold stock  
         
        //Takes out stock node if empty. Writes back stocks still owned, then deletes list
        out = fopen(fileName, "wb");
        if(out == NULL){
            printf("Error saving stock transaction\n");
            fflush(stdout);
        }
        else{
            if(listPtr->tailPtr == NULL){
                remove(fileName);
            }
            else{
                fflush(stdout);
                traverseWriteNodes(listPtr, out);
            }
            deleteList(listPtr);
            fclose(out);
            
        }
        
    }
    
}

/* processSale:      Takes sale details and manipulates list to removed stocks sold.
 * Parameters:      listPtr - pointer to linked list of stocks
 * Postcondition:   linkedList is modified, but list is not deleted in this function.
 * returns:         nothing
 */
void processSale(linked_list_t* listPtr){

    int numShares = -1;
    int sharesOwned = 0;
    int processed = 0;
    int totalShares = 0;
    double currentValue = 0;
    double currentCost = 0;
    double originalBasis = 0;
    double gainOrLoss = 0.00;
    node_t* currentNode;
    int currentNodeShares;
    do{
        sharesOwned = getSumStocksOwned(listPtr);//Function in linkedList.c that sums number stocks in list
        printf("You own %d shares of %s\n", sharesOwned, listPtr->tailPtr->stock.ticker);
        //Asks for number shares and checks if valid
        printf("Number of shares to sell (Enter 0 to cancel sale):  ");
        scanf("%d", &numShares);
        if(numShares < 0){
            printf("Not a valid number of shares.\n");
            fflush(stdout);
        } 
        else if(numShares > 0){
 
            if(numShares > sharesOwned){
                printf("You do not have that many shares of stock. \n");
                fflush(stdout);
                return;
            } 
            else{ //process valid sale
                printf("Enter current price per share: ");
                scanf("%lf", &currentCost); 
                if(currentCost < 0){
                    printf("Not a valid current price\n");
                    return;
                }

                currentValue = numShares * currentCost;
                totalShares = numShares;
                printf("Processing sale\n");//START HERE TO DO WRITES
                fflush(stdout);
                currentNode = listPtr->tailPtr;
                do{//sell stock until number requested are taken out of list
                    
                    if(currentNode->stock.numShares > numShares){//buying less than stock than oldest purchase
                        originalBasis += (numShares * currentNode->stock.pricePerShare);
                        currentNode->stock.numShares -= numShares;
                        numShares = 0;
                        processed = 1;                       
                    }
                    else if(currentNode->stock.numShares == numShares){//buying stock equal oldest purchase
                        originalBasis += currentNode->stock.numShares * currentNode->stock.pricePerShare;
                        currentNode = dequeueNode(listPtr);
                        
                            free(currentNode);
                            
                        numShares = 0;
                        processed = 1;
                    
                    }
                    else{ //buying more than oldest purchase
                        originalBasis += currentNode->stock.numShares * currentNode->stock.pricePerShare;
                        numShares -= currentNode->stock.numShares;
                        currentNode = dequeueNode(listPtr);
                        
                            free(currentNode);
           
                            currentNode = listPtr->tailPtr;
                      
                    
                    }
                
                }while(numShares > 0);
                gainOrLoss = currentValue - originalBasis;
                printf("%d shares sold. Original Basis: $%10.2lf   Current Value: $%10.2lf   Gain/(Loss): ", totalShares, originalBasis, currentValue);
                if(gainOrLoss < 0){
                    gainOrLoss = abs(gainOrLoss);
                    printf("( $%10.2lf )\n", gainOrLoss);
                }
                else{
                    printf(" $%10.2lf \n", gainOrLoss);
                }
                
                fflush(stdout);   
            }   
        }
    }while(numShares != 0 && !processed); //exits once all shares requested are sold
     
}

/* makeUpper:       Helper upper case method to follow naming convention for stock files (STOCK.bin)
 * Parameters:      fileName - name of stock provided by user
 * returns:         nothing - filename is a cstring (pointer), so uppercase "return" is done by reference
 */
void makeUpper(char fileName[]){
    int i, size = strlen(fileName);
    for(i = 0; i < size; i++){
        fileName[i] = toupper(fileName[i]);
    }
}

/*
 * File: stock.c
 * Author: Donna Walker
 * Date: 10/8/2018
 * Contains processing methods for stock structure.
 * 
 */
#include <stdio.h>
#include <time.h>
#include "stock.h"

/* printStock:      Prints the properties of each stock in a neat format
 * Parameters:      s - the stock to be printed
 * Postcondition:   Ends without end of line awaiting user into
 * returns:         nothing
 */
void printStock(const stock_t s){
    printf("%-10s%2d/%2d/%4d  %6d   $%12.2lf\n", s.ticker, s.date.month, s.date.date, s.date.year, s.numShares, s.pricePerShare);
    fflush(stdout);
}

/* printStock:      Prints the properties of each stock in a neat format  START HERE
 * Parameters:      s - the stock to be printed
 * Postcondition:   Ends without end of line awaiting user into
 * returns:         nothing
 */
void getStock(stock_t* s){//for binaryWrite program
    int month, day, year;
    struct tm* tPtr;    
    time_t t = time(NULL);
    tPtr  = localtime(&t);

    printf("\nEnter the stock name: ");
    scanf("%s",&s->ticker);
    fflush(stdout);
    makeUpper(s->ticker);
    s->date.month = tPtr->tm_mon + 1;
    s->date.date = tPtr->tm_mday;
    s->date.year = tPtr->tm_year + 1900;

    printf("Number of Shares: ");
    scanf("%d", &s->numShares);
    printf("Price per share: ");
    scanf("%lf", &s->pricePerShare);
    fflush(stdout);

}

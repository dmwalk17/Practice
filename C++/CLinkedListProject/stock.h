/*
 * File: stock.h
 * Author: Donna Walker
 * Date: 10/8/2018
 * Defines stock 
 * 
 */



#ifndef STOCK_H
#define STOCK_H
#include "date.h"

//Constants
#define MAX_TICKER_LENGTH 6

//stock definition
typedef struct stock_t {
    char ticker[MAX_TICKER_LENGTH];
    date_t date; //date bought
    int numShares;
    double pricePerShare;
} stock_t;


//Prototypes
void printStock(const stock_t s); //Formatted print of stock, also used in binaryread that instructor provided
void getStock(stock_t* s);//(for binaryWrite program) gets stock info for purchase called buyStock, main.c

#endif

/*
 * File: node.c
 * Author: Donna Walker
 * Date: 10/8/2018
 * This program reports, buys and sells stock.
 * 
 */
#include <stdlib.h>
#include "node.h"

// initNode: Initiates a node allocating memory and setting pointers to null
// Parameters: s- stock_t struct with data for node
// returns: nodePtr - node_t* 
node_t* initNode(stock_t* s){
	node_t* nodePtr = malloc(sizeof(node_t));
	nodePtr->stock = *s;
	nodePtr->prevPtr = nodePtr->nextPtr = NULL;
	return nodePtr;
}

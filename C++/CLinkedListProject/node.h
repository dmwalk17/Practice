/*
 * File: node.h
 * Author: Donna Walker
 * Date: 10/8/2018
 * Defines node
 * 
 */



#ifndef NODE_H
#define NODE_H
#include "stock.h"

//node definition
typedef struct node_t{
	stock_t stock;
	struct node_t* prevPtr;
	struct node_t* nextPtr;
}node_t;

//prototype
node_t* initNode(stock_t* s);//creates a node containing s

#endif

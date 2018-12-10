/*
 * File: linkedList.h
 * Author: Donna Walker
 * Date: 10/8/2018
 * Defines linked list struct and functions.
 * 
 */



#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"

//linked list definition
typedef struct {
	node_t* headPtr;
	node_t* tailPtr;
} linked_list_t;

//prototypes
void createList(linked_list_t* listPtr); //creates an empty linked list 
void insertNode (linked_list_t* listPtr, node_t* newNode); //inserts a node at the head of the list (newest stock)
node_t* dequeueNode(linked_list_t* listPtr); //dequeues the first node inserted from the end of the list and returns it. Does not deall. memory.
void deleteList(linked_list_t* listPtr); //deletes entire list
int getSumStocksOwned(linked_list_t* listPtr);//Traverses list to add and return sum of stock
void traverseQueue(const linked_list_t* listPtr); //traverses and prints list from tail to head
void traverseWriteNodes(const linked_list_t* listPtr, FILE* out);//writes nodes in queue (tail is oldest) to binary file


#endif

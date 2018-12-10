/*
 * File: linkedList.c
 * Author: Donna Walker
 * Date: 10/8/2018
 * Functions for linked list using nodes with stock_t property and 
 * list used as queue with tail being the front and head being the rear.
 * Oldest stock is stored in list->tailPtr.
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "linkedList.h"


 /* createList:     Creates an empty list, initializing pointers if list exists
 * Parameters:      listPtr - pointer to linked list
 * returns:         nothing
 */
void createList(linked_list_t* listPtr){
    if(listPtr != NULL){
        listPtr->headPtr = NULL;
        listPtr->tailPtr = NULL;
    }
}

/* insertNode:      Inserts a node at the end of the queue (headPtr)
 * Parameters:      listPtr - pointer to linked list
 *                  newNode - pointer to node
 * returns:         nothing
 */
void insertNode (linked_list_t* listPtr, node_t* newNode){
    if (listPtr != NULL){
        if (listPtr->headPtr == NULL){
            listPtr->headPtr = listPtr->tailPtr = newNode;
       }
        else{
            newNode->nextPtr = listPtr->headPtr;
            listPtr->headPtr->prevPtr = newNode;
            listPtr->headPtr = newNode;
        }     
        
    
    } 
}

/* dequeuNode:      Dequeues the first node inserted from the end of the list and returns it.
 * Parameters:      listPtr - linked list pointer
 * Postcondition:   Does not deallocate memory of the returned node_t pointer
 * returns:         node_t*
 */
node_t* dequeueNode(linked_list_t* listPtr){
    node_t* nodePtr;
    if ((listPtr != NULL) && (listPtr->tailPtr != NULL)){
        nodePtr = listPtr->tailPtr;
        listPtr->tailPtr = nodePtr->prevPtr;
        if (listPtr->tailPtr != NULL) {
            listPtr->tailPtr->nextPtr = NULL; 
            fflush(stdout);   //Don't still know why it needs this line of code, but it breaks without it
        }
        else {
            listPtr->tailPtr = listPtr->headPtr = NULL;
            nodePtr->prevPtr = nodePtr->nextPtr = NULL;
            return nodePtr;        
        }   
    }
    else 
        return NULL;
}

/* deleteList:      Deletes entire list
 * Parameters:      listPtr - pointer to linked list
 * Postcondition:   All nodes in list are deallocated and list pointers are nulled
 * returns:         nothing
 */
void deleteList(linked_list_t* listPtr){
    node_t* curPtr;
    node_t* nextPtr;
    if(listPtr != NULL && listPtr->headPtr != NULL){
        curPtr = listPtr->headPtr;
        while(curPtr != NULL){
            nextPtr = curPtr->nextPtr;
            free(curPtr);
            curPtr = nextPtr;
        }
        listPtr->headPtr = listPtr->tailPtr = NULL;
    }
} 

/* getSumStocksOwned:   Traverses list to add and return sum of stocks in list
 * Parameters:      listPtr - pointer to linked list  
 * returns:         sumStock - sum of quantity of stocks
 */
int getSumStocksOwned(linked_list_t* listPtr){
    node_t* curPtr;
    int sumStock = 0;
    if(listPtr != NULL){
        curPtr = listPtr->tailPtr;
        while(curPtr != NULL){
            sumStock += curPtr->stock.numShares;
            curPtr= curPtr->prevPtr;
        }
        return sumStock;
    }
    return 0;
}


/* traverseQueue:   traverses and prints number of stocks shares in nodes (tail to head)
 *                  primarily was used for testing previous function
 * Parameters:      listPtr - pointer to linked List
 * returns:         nothing
 */
void traverseQueue(const linked_list_t* listPtr){
    node_t* curPtr;

    if(listPtr != NULL){
        curPtr = listPtr->tailPtr;
        while(curPtr != NULL){
            printStock(curPtr->stock);
            fflush(stdout);
            curPtr = curPtr->prevPtr;
        }
        printf("\n");
        fflush(stdout);
    }
}

/* traverseWriteNodes:  traverse and write list from tail to head (oldest to newest)
 * Parameters:      listPtr - pointer to linked list
 *                  out - file pointer 
 * Precondtion:     out - successfully opened for binary write
 * Postcondition:   out is not closed in this function
 * returns:         nothing
 */
void traverseWriteNodes(const linked_list_t* listPtr, FILE* out){
    node_t* curPtr;
        
    if(listPtr != NULL && listPtr->headPtr != NULL){
        curPtr = listPtr->tailPtr;
        while(curPtr != NULL){
            fwrite((char*)curPtr, 1, sizeof(stock_t), out);
            curPtr = curPtr->prevPtr;
        }
    }
}

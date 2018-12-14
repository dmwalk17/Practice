/* File: Position.h *
 * Author: Donna Walker/ Pair Programming Assignment
 * Description: Defines and implements Position class.
 * Most functions are implemented in place. 
 */
#ifndef POSITION_H
#define POSITION_H

template<class T> class BinaryTree; //declaration for friend
#include "node.h"
template<class T>
class Position {
public:
    /* overloaded * to dereference iterator. 
     * Returns node iterator references
     * Precondition: Position points to a valid node with an item in it
    */ 
    Node<T>& operator*(){ return *nodePtr; }
    
    /* parent: creates a Position pointing to this current
     * referencing node's parent. Returns Postion
     * referencing current node's parent.
     * Precondition: class T has overloaded operator<
     */ 
    Position parent() const{
        return Position<T>(this->nodePtr->parentPtr ); }
        
    /* left:  returns an iterator that points to the left pointer of
     * the current node.
     * Returns: Postion pointing to left ptr of current node or null
     * if node is external.
     * Precondition: class T has overloaded operator<
     */         
    Position left() const {
        return Position<T>(nodePtr->leftPtr); }
        
    /* right: returns an iterator that points to the right pointer
     * of the current node
     * Returns: Postion pointing to right pointer of current node.
     * Precondition: class T has overloaded operator< 
     */         
    Position right() const{
        return Position<T>(nodePtr->rightPtr); }
        
    /* isRoot: determines if the current node is the root
     * Returns True if the current node is the tree root.
     */         
    bool isRoot() const {
        // does this iterator point to real root?
        return this->nodePtr->parentPtr->parentPtr == NULL; }
        
    /* isSuperRoot: determines if the pointer is pointing to the superroot
     * Returns true if the position points to the true super root
     */ 
    bool isSuperRoot() const {
        //does this iterator point to fake superroot?
        return this->nodePtr->parentPtr == NULL; }
        
    /* isExternal: determines if the node is fake
     * Returns: true if the node is a leaf
     */         
    bool isExternal() const {
        //is it a fake end node?
        return this->nodePtr->leftPtr == NULL && 
        this->nodePtr->rightPtr == NULL; }
        
    /* isInternal: determines if node is real
     * Returns: true if node is not a leaf
     */     
    bool isInternal() const { return !(isExternal()); }
    
    /* overloaded == returns true if both Positions point to 
     * same node in the tree. 
     * Returns true if both iterators point to the same node
     * Precondition: class T has overloaded operator==
     */ 
    bool operator==( const Position& p ){
        return this->nodePtr == p.nodePtr; }
        
    /* overloaded ++ comments in implementation below
     */
    Position& operator++(); // inorder traversal
    T getItem() { return nodePtr->item; }
    
    friend class BinaryTree<T>;

private:
    //only friends like BST can create positions from its nodes
    Node<T>* nodePtr;
    Position(Node<T>* n){ //private constructor, implemented in place 
        nodePtr = n;
    }
    
    
};

/* overloaded ++ returns an iterator that points to the next
 * node in the tree, in-order traversal. Returns Postion
 * with NULL nodePtr if get to end of tree in-order.
 * Precondition: class T has overloaded operator<
 */ 
template <class T>
 Position<T>& Position<T>::operator++(){
     Position w = this->rightPtr;
     if(w.isInteral()){
         do{
             *this = w;
             w = w.leftPtr; 
         }while(w.isInternal());
     }
     else{
         w = this->parentPtr;
         while(w->nodePtr != NULL && *this == w->rightPtr){
             *this = w;
             w = w->parentPtr;
         }
         *this = w; //this = 100, the next in-order
     }
     return *this;
 }
 #endif
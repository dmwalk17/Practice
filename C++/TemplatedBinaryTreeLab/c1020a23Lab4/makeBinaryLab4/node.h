/* File: Node.h *
 * Author: Donna Walker/ Pair Programming Assignment
 * Description: Defines and implements Node template class. 
 */

#ifndef NODE_H
#define NODE_H
#include <cstdlib>
template<class T> class BinaryTree; //declaration for friends
template<class T> class Position;


template<class T>
class Node {
public:
    Node(); //default constructor
    //constructor that takes node's data
    Node(const T&);
    //copy constructor
    Node(const Node<T>&);
    virtual ~Node<T>() {} //destructor
    void setItem( const T&);
    T getItem() const { return item; }
    Node<T>& operator=( const Node<T>&);
    friend class BinaryTree<T>;
    friend class Position<T>; //Position is an iterator class
private:
    Node<T>* leftPtr;
    Node<T>* rightPtr;
    Node<T>* parentPtr;
    T item;
    
};
/* No argument Node constructor
 * Instantiates empty node
 */ 
template<class T>
Node<T>::Node(){
    leftPtr = rightPtr = parentPtr = NULL;
}

/* One argument Node constructor
 * Takes an item and instantiates
 * a node with data
 */ 
template<class T>
Node<T>::Node(const T& i){
    leftPtr = rightPtr = parentPtr = NULL;
    item = i;
}

/* copy constructor
 */ 
template<class T>
Node<T>::Node(const Node<T>& n){
    leftPtr = rightPtr = NULL;
    item = n.item;
}


/*setItem: sets/resets the item in a node
 */
template<class T>
void Node<T>::setItem( const T& i){
    item = i;
}
/* overloaded operator= : makes the calling node 
 * the same values as the parameter node, but does not
 * copy pointers.
 * Returns: the referencing node with the new data
 */
template<class T>
Node<T>& Node<T>::operator=( const Node<T>& n){
    leftPtr = rightPtr = parentPtr = NULL;
    item = n.item;
    return *this;
}


#endif
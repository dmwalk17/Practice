/* File: binaryTree.h *
 * Author: Donna Walker/ Pair Programming Assignment
 * Description: Defines and implements binary tree template class. 
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <algorithm>
#include "node.h"
#include <fstream>
using std::fstream;
using std::cout;
using std::endl;
using std::max;
using std::ios;
template<class T> class Position; //declaration for friend

//for printing
const int PREORDER = 1;
const int INORDER = 2;
const int POSTORDER = 3;

template<class T>
class BinaryTree {
public:
    /* no argument constructor
     */ 
    BinaryTree();
    /* copy constructor
     */ 
    BinaryTree( const BinaryTree&);
    
    /* size: returns number of real nodes in tree
     * Parameter: none
     * Returns: int - # of real nodes in tree
     */ 
    int size() const { return numNodes; }
    
    /* empty: returns true if tree empty of real nodes
     * Parameters: none
     * Returns: bool - true if empty
     */ 
    bool empty() const { return numNodes == 0; }
    
    /* root: superroot right pointer always points to real root node
     * Parameter: none
     * Returns: Position<T> pointing to tree's root
     */ 
    Position<T> root() const {
        return Position<T>( superRootPtr->rightPtr );
    }
    
    /* traverseAndPrint: Method that redirects to the appropriate 
     *   recursive print function based on type parameter
     * Parameters: p - normally starts at position pointer to root() to print
     *             type - intended to use const at top of this header (PREORDER, INORDER, 
     *                    POSTORDER)
     * Precondition: overloaded < and << for Participant
     * Returns: none
     */ 
    void traverseAndPrint( const Position<T>& p, int type) const;
    
    /* preorderTraverseAndWrite: prints real nodes in tree in preorder
     * Parameters: output - ostream passed by reference
     *             p - position to start print, normally root()
     * Precondition: overloaded < and << for Participant
     * Returns: none
     */ 
    void preorderTraverseAndWrite(ostream &output, const Position<T>& p) const;//new
    
    /* inorderTraverseAndAdd: adds the grand total of miles 
     *  for all Participants in the file
     * Parameter: output - stream passed by reference
     *            p - position to start traverse to write
     * Precondition: overloaded < and << for Participant
     * Returns: none (attempted passing ostream back by reference, but with errors and no time to figure it out) 
     */ 
    void inorderTraverseAndAdd(const Position<T>& p, double& );
    
    /* depth: calculates depth of node at position
     * Parameter: the position of the node to determine depth from root
     * Precondition: grandtotal is previously declared and sent by reference 
     *   Participant has < defined to traverse
     * Returns: number of node depth
     */ 
    int depth( const Position<T>& ) const;
    
    /* height: calculates height of tree (max between left or right)
     * Parameter: Position to determine node height
     * Returns: node height
     */ 
    int height( const Position<T>& ) const;
    
    /* begin: returns position iterator to first node on tree - the
     * leftmost
     * Returns: leftpost position in the tree
     */ 
    Position<T> begin() const;

    /* end: returns NULL iterator
     * Parameter: none
     * Precondition: Participant has operator= defined
     * Returns: null Position<T>
     */ 
    Position<T> end() const { return Position<T>(); }
    
    /* find: finds a T object in tree
     * Parameters: the object to find
     * Pre-condition: class T has overloaded operator==
     * Returns iterator to object, superroot iterator if tree
     * is empty, fake leaf position if not found
     */
    Position<T> find( const T& )const;

    /* insert: inserts object T in the binary tree
     * Parameter: the object to insert
     * Pre-condition: class T has overloaded operator<
     * Returns iterator to newly inserted object or superRootPtr
     * if item already in tree
     */ 
    Position<T> insert(const T& );
    
    /* erase: identified node containing parameter item, and if
     * present, removes a node above Position p
     * Precondition position p is a valid position in tree
     * Returns true if successful
     */ 
    bool erase( const T& );

    /* erase: removes a node above Positionp
     * Precondition position p is a valid position in tree
     * Returns true if successful
     */ 
    bool erase( const Position<T>& );

    /* destructor: calls deleteUtility to remove all nodes from tree
     */
    virtual ~BinaryTree() { deleteUtility(superRootPtr); }
    
    /*operator= 
     *Parameter: tree1, the tree to copy
     *Return: this, the copied tree
     */ 
    BinaryTree<T> operator=(const BinaryTree<T>& tree1);
    friend class Position<T>;
private:
    Node<T>* superRootPtr;
    //number real nodes in tree, not including fake super
    //root and fake ends nodes
    int numNodes;
    
    /* preorderTraverseAndPrint: prints real nodes in tree in preorder
     * Parameters: p - position to start traverse, normally root
     * Precondition: normally called by public method, traverseAndPrint using type PREORDER
     * Returns: none
     */ 
    void preorderTraverseAndPrint( const Position<T>& ) const;
    
    /* inorderTraverseAndPrint: prints real nodes in tree in order
     * Parameters: p - position to start traverse, normally root
     * Precondition: normally called by public method, traverseAndPrint using type INORDER
     * Returns: none
     */ 
    void inorderTraverseAndPrint( const Position<T>& ) const;
    
    /* postorderTraverseAndPrint: prints real nodes in tree in postorder
     * Parameters: p - position to start print, normally root
     * Precondition: normally called by public method, traverseAndPrint using type POSTORDER
     * Returns: none
     */ 
    void postorderTraverseAndPrint( const Position<T>& ) const;

    /* findUtility: recursive utility find function
     * Parameters:
     * item to look for
     * p postition to start looking from
     * Pre-condition: class T has overloaded operator== and
     * operator<, tree not empty of real nodes
     * Returns: position iterator where found or NULL iterator
     */ 
    Position<T> findUtility( const T& item, const Position<T>& ) const;
    
    /* inserts object T in the binary tree
     * Parameter: the object to insert
     * Pre-condition: class T has overloaded operator<
     * Returns: iterator to newly inserted object or to superRoot
     *  fake node if item already in tree
     */ 
    Position<T> insertUtility(const T& item );

    /* deleteUtility: deletes all nodes in the tree
     * Parameter: nPtr normally pointing to superroot
     * Returns: none
     */ 
    void deleteUtility(Node<T>* );

    /* eraseUtility, a private utility function that determines a leaf node to swap the
     * node to delete (if necessary) and calls removeAboveExternal to remove the leaf or
     * node with one subtree.
     * Parameters: p position iterator of node with the key to delete
     * Returns: a Position<T> of sibling of node that was removed??
     */ 
    Position<T> eraseUtility( const Position<T>& p);

    /*expandExternal - inserts item by copying its data to
     * position p and setting positions's left and right ptrs
     * to end nodes
     * Parameters
     * item to be inserted
     * p fake end node where item will be inserted
     * Precondtion: p is an expternal node (a fake leaf) and
     * class T ha overloaded = operator
     */ 
    void expandExternal ( const T& item, Position<T>& p);

    /*removeAboveExternal: removes "leaf" node just above fake
     * leaf node pointed to by p. Decrements number of nodes
     * in tree.
     * Parameter:
     * p - leaf node of real node to delete
     * Returns: position iternator to sibling of node removed
     */
    Position<T> removeAboveExternal(const Position<T>& p );
    
    /*copyTree utility function that copies one tree to this' tree
     * Parameters:
     *      p - pointer to parent it this' tree that new node's
     *          parentPtr should point to
     *      n - pointer to new node in tree to copy from
     * Returns pointer to node just allocated for this' tree or NULL
     *  (if at the end of a branch) and no new node to copy
     */ 
    Node<T>* copyTree(Node<T>* p, const Node<T>* n );
    
};

template<class T>
BinaryTree<T>::BinaryTree(){
    superRootPtr = new Node<T>();
    superRootPtr->rightPtr = new Node<T>();
    superRootPtr->rightPtr->parentPtr = superRootPtr;
    superRootPtr->leftPtr = NULL;
    numNodes = 0;
}

template<class T>
BinaryTree<T>::BinaryTree( const BinaryTree& b){
    numNodes = b.numNodes;
    superRootPtr = new Node<T>();
    if(b.empty()){
        superRootPtr->rightPtr = new Node<T>();
        superRootPtr->rightPtr->parentPtr = superRootPtr;
    }
    else{ //tree b has real nodes in it
        superRootPtr->rightPtr = copyTree( superRootPtr, b.superRootPtr->rightPtr);
    }
}

template<class T>
void BinaryTree<T>::traverseAndPrint( const Position<T>& p, int type) const{
    if( type == 1){
        preorderTraverseAndPrint(p);
    }
    else if(type == 2){
        inorderTraverseAndPrint(p);
    }
    else if(type == 3){
        postorderTraverseAndPrint(p);
    }
    else{
        cout << "Invalid type of print format" << endl;
    }
}

template<class T>
int BinaryTree<T>::depth( const Position<T>& p) const{
    if(p.isSuperRoot()) return -1;
    
    else if(p.isRoot()) return 0;
    else{
        return 1 + depth(p.parent());
    }
}

template<class T>
int BinaryTree<T>::height( const Position<T>& p) const{
    if(p.isExternal()) return 0;
    int h = 0;
    //h = max of 0 and height of left subtree
    h = max(h, height(Position<T>(p.nodePtr->leftPtr)));
    //h = max of height of left subtree and
    //height of right subtree
    h = max(h, height( Position<T>(p.nodePtr->rightPtr)));
    return 1 + h;
}

template<class T>
Position<T> BinaryTree<T>::begin() const{
    if(numNodes > 0){
        Position<T> p = root();
        while(p.isInternal()){
            p = p.left();
        }
        return p.parent();
    }
    else return Position<T>( superRootPtr );
}

template<class T>
Position<T> BinaryTree<T>::find( const T& item)const{
    if( numNodes > 0){
        Position<T> v = findUtility( item, root() );
        return v;
    }
    else return Position<T>( superRootPtr );
}

template<class T>
Position<T> BinaryTree<T>::insert(const T& item){
   // root() = superroot's right ptr
    Position<T> p = insertUtility( item );
    //return iterator to position where new node inerted
    return p;
}

template<class T>
bool BinaryTree<T>::erase( const T& item){
    Position<T> p = find(item);
    if(!p.isSuperRoot() && !p.isExternal()){
        eraseUtility(p);
        return true;
    }
    return false;
}

template<class T>
bool BinaryTree<T>::erase( const Position<T>& p){
    //can't remove superroot or fake external node
    if(!p.isSuperRoot() && !p.isExternal()){
        eraseUtility(p);
        return true;
    }
    return false;
}

template<class T> 
BinaryTree<T> BinaryTree<T>::operator=(const BinaryTree<T>& tree1){
    deleteUtility(superRootPtr);
    numNodes = tree1.numNodes;
    superRootPtr = new Node<T>();
    if(tree1.empty()){
        superRootPtr->rightPtr = new Node<T>();
        superRootPtr->rightPtr->parentPtr = superRootPtr;
    }
    else{ //tree1 has real nodes in it
        superRootPtr->rightPtr = copyTree( superRootPtr, tree1.superRootPtr->rightPtr);
    }    
    return *this;    
}  
  
//private functions
template<class T>
void BinaryTree<T>::preorderTraverseAndPrint( const Position<T>& p) const{
    if(p.nodePtr == NULL || p.isExternal()){
        return;
    }
    cout << p.nodePtr->item << endl;
    preorderTraverseAndPrint(p.nodePtr->leftPtr);
    preorderTraverseAndPrint(p.nodePtr->rightPtr);
}

template<class T>
void BinaryTree<T>::inorderTraverseAndPrint( const Position<T>& p) const{
    if(p.nodePtr == NULL || p.isExternal()){
        return;
    }
    inorderTraverseAndPrint(p.nodePtr->leftPtr);
    cout << p.nodePtr->item << endl;
    inorderTraverseAndPrint(p.nodePtr->rightPtr);
}

template<class T>
void BinaryTree<T>::postorderTraverseAndPrint( const Position<T>& p) const{
    if(p.nodePtr == NULL || p.isExternal()){
        return;
    }
    postorderTraverseAndPrint(p.nodePtr->leftPtr);
    postorderTraverseAndPrint(p.nodePtr->rightPtr);
    cout << p.nodePtr->item << endl;
}

//Reference: https://stackoverflow.com/questions/2239607/can-a-recursive-function-write-to-a-file-in-c
//tried to return ostream by reference, but it was causing errors, so I took it back out
template<class T>
void BinaryTree<T>::preorderTraverseAndWrite(ostream& output, const Position<T>& ptr) const{
    
    Participant p;

    
        if(ptr.nodePtr == NULL || ptr.isExternal()){
            return;
        }
        p.clear();
        p = ptr.nodePtr->item;
        output.write((char*)&p, sizeof(Participant));
        preorderTraverseAndWrite(output, ptr.nodePtr->leftPtr);
        preorderTraverseAndWrite(output, ptr.nodePtr->rightPtr);
}

//recursively adds total class miles
template<class T>
void BinaryTree<T>::inorderTraverseAndAdd(const Position<T>& p, double& totalClassMiles){
    
    if(p.nodePtr == NULL || p.isExternal()){
        return;
    }
        inorderTraverseAndAdd(p.nodePtr->leftPtr, totalClassMiles);
        totalClassMiles =  totalClassMiles + (p.nodePtr->getItem().getTotalMiles());
        inorderTraverseAndAdd(p.nodePtr->rightPtr, totalClassMiles);
}

//finds item in tree starting at position
template<class T>
Position<T> BinaryTree<T>::findUtility( const T& item, const Position<T>& p) const{
    if(p.isExternal()){
        return p;
    }
    else if(item == p.nodePtr->item){
        return p;
    }
    else if(item < p.nodePtr->item){
        return findUtility(item, p.nodePtr->leftPtr);
    }
    else{
        return findUtility(item, p.nodePtr->rightPtr);
    }
    return Position<T>(superRootPtr);
}

// inserts item into tree
template<class T>
Position<T> BinaryTree<T>::insertUtility(const T& item ){
    Position<T> foundPosition = findUtility(item, root());
    if(foundPosition.isExternal()){
        expandExternal(item, foundPosition);
        return foundPosition;
    }
   return Position<T>( superRootPtr );
}

//deletes all nodes in the tree
template<class T>
void BinaryTree<T>::deleteUtility(Node<T>* nPtr){
            if(nPtr != NULL){
            deleteUtility(nPtr->leftPtr);
            deleteUtility(nPtr->rightPtr);
            delete nPtr;
        }
}
  
//erases just one node from the tree at position p
template<class T>
Position<T> BinaryTree<T>::eraseUtility( const Position<T>& p){
    Position<T> w(p), u(p);
    if(p.left().isExternal()){
        w = p.left();
    }
    else if(p.right().isExternal()){
        w = p.right();
    }
    else{//case 3 - p has two, non-empty subtrees)
        w = p.right();
        while(w.isInternal()){
            w = w.left();
        }
            u = w.parent();
            p.nodePtr->item = u.nodePtr->item;

    }
    Position<T> s = removeAboveExternal(w);
    return s;
}

//insert item data at position p
template<class T>
void BinaryTree<T>::expandExternal ( const T& item, Position<T>& p){
    Node<T>* left = new Node<T>();
    Node<T>* right = new Node<T>();
    p.nodePtr->leftPtr = left;
    p.nodePtr->rightPtr = right;
    left->parentPtr = p.nodePtr;
    right->parentPtr = p.nodePtr;
    p.nodePtr->item = item;
    numNodes++;
}

//remove node above fake leaf node at position p
template<class T>
Position<T> BinaryTree<T>::removeAboveExternal(const Position<T>& p ){//LOOK AT ALGORITHM
    Node<T>* w = p.nodePtr;
    Node<T>* v = p.nodePtr->parentPtr;
    Node<T>* siblingPtr, *grandparentPtr;
    if(w == v->leftPtr){
        siblingPtr = v->rightPtr;
    }
    else{
        siblingPtr = v->leftPtr;
    }
    if(v == superRootPtr->rightPtr){
        superRootPtr->rightPtr = siblingPtr;
        siblingPtr->parentPtr = superRootPtr;
    }
    else{ //removing a leaf that isn't the actual root
        grandparentPtr = v->parentPtr;//ADDED CODE
        siblingPtr->parentPtr = grandparentPtr;//ADDED-MOVED CODE TO FIGURE OUT WITH ALGORITHM
        if(grandparentPtr->leftPtr == v){
            grandparentPtr->leftPtr = siblingPtr;
            
        }
        else{//v is to the right of its parent
            
            grandparentPtr->rightPtr = siblingPtr;    
        }
        
    }
    delete w;
    delete v;
    return Position<T>(siblingPtr);
}

template<class T>
Node<T>* BinaryTree<T>::copyTree(Node<T>* p, const Node<T>* n ){
    Node<T>* newNode;
    if(n != NULL){
        newNode = new Node<T>(*n);
        newNode->parentPtr = p;
        newNode->leftPtr = copyTree(newNode, n->leftPtr);
        newNode->rightPtr = copyTree(newNode, n->rightPtr);
        return newNode;
    }
    return NULL;
}
#endif
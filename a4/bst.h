/*
 * 6.088 IAP 2010
 * Assignment #4: Introduction to C++
 *
 * BST.h
 * Header file for the binary search tree 
 * 
 * You will implement a binary search tree that adheres to this interface.
 * 
 */

#ifndef BST_H
#define BST_H

class node {
  friend class BST;
  int val;
  node* left;
  node* right;

  public:
    node(int val);
};

/*
 * Binary search tree
 */
class BST {
 node* root;
 void inorder(node* n);
 void delete_node(node* n);

 public:

  // DO NOT change the declarations of the given methods.
  
  // constructor
  BST();

  // destructor
  ~BST();
  
  // inserts "val" into the tree
  void insert(int val);

  // returns true if and only if "val" exists in the tree.
  bool find(int val);

  // prints the tree elements in the in-order traversal order
  void print_inorder();
  
};

#endif  // BST_H

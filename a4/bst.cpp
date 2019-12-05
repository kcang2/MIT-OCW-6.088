#include "bst.h"
#include <iostream>

using namespace std;

node::node(int val){
  this->val = val;
  left = NULL;
  right = NULL;
}

BST::BST() {
  root=NULL;
}

// Search may not be recursive
void BST::insert(int val){
  node** curr = &root;

  while (*curr!=NULL) {
    if (val > (*curr)->val)  // RHS
      curr = &(*curr)->right; 
    else if (val < (*curr)->val)  // LHS
      curr = &(*curr)->left; 
    else  // same value
      return;
  }

  *curr = new node(val);
  return;
}

bool BST::find(int val) {
  node** curr = &root;
   
  while (*curr!=NULL) {
    if (val > (*curr)->val)  // RHS
      curr = &(*curr)->right; 
    else if (val < (*curr)->val)  // LHS
      curr = &(*curr)->left; 
    else  // same value
      return true;
  }
  return false;
}


// Traversal MUST be recursive
void BST::inorder(node* n) {
  if(n!=NULL) {
    inorder(n->left);
    cout << n->val << " ";
    inorder(n->right);
  }
}

void BST::print_inorder() {
  inorder(root);
  cout << endl;
}

void BST::delete_node(node* n) {
  if (n->left!=NULL)
    delete_node(n->left);
  if (n->right!=NULL)
    delete_node(n->right);
  delete n;
}

BST::~BST() {
  delete_node(root);
}



#include <iostream>
#include "bst.h"
#include <cassert>

int main () {

  BST tree;

  // Test case 1: insert 1
  std::cout << "Test case 1: Insert 1\n";
  tree.insert(1);
  tree.print_inorder();
  if (tree.find(1)) 
    std::cout << "Passed!\n";
  else 
    std::cout << "Failed! Tree should contain 1.\n";

  // Test case 2: insert 0
  std::cout << "Test case 2: Insert 0\n";
  tree.insert(0);
  tree.print_inorder();
  if (tree.find(1) && tree.find(0)) 
    std::cout << "Passed!\n";
  else 
    std::cout << "Failed! Tree should contain 1, 0.\n";

  // Test case 3: insert -1
  std::cout << "Test case 3: Insert -1\n";
  tree.insert(-1);
  tree.print_inorder();
  if (tree.find(-1) && tree.find(0) && tree.find(1))
    std::cout << "Passed!\n";
  else     
    std::cout << "Failed! Tree should contain -1, 1, 0.\n";

  // ADD YOUR TESTS HERE
  tree.insert(-1);  //Duplicate
  tree.print_inorder();
  tree.insert(2);  
  tree.insert(4);  
  tree.insert(3);
  assert(tree.find(33)==false);
  tree.insert(6);  
  tree.insert(5);  
  tree.insert(7);  
  tree.insert(-2);
  tree.print_inorder();
  return 0;
}

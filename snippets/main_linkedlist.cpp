#include "linkedlist.h"
#include <cstddef>
#include <iostream>

int main(){
   LinkedList ll = LinkedList(3);

   node* n = new node;
   n->next = NULL;
   n->val = 2;

   ll.insert(n, START);
   ll.printAll();

   n = new node;
   n->next = NULL;
   n->val = 4;

   ll.insert(n, END);
   ll.printAll();

   n = ll.search(3);
   std::cout << "Found: " << n->val << std::endl;
   
   n = ll.search(7);

   n = new node;
   ll.deletenode(n);
   delete n;

   n = new node;
   n->next = NULL;
   n->val = 5;
   ll.insert(n, END);

   ll.deletenode(ll.search(2));
   ll.deletenode(ll.search(4));
   ll.deletenode(ll.search(5));
   ll.printAll();

}

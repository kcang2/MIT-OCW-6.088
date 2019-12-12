#include "ds.h"
#include <iostream>

int main(){
   // Create using node*
   int* p = new int(1);
   node<int>* node_1 = new node<int>(p);
   Stack<int> Stack_1(node_1);
   Stack_1.~Stack();

   // create using T*
   p = new int(2);
   Stack<int> Stack_2(p);
   Stack_2.~Stack();
   
   // create using T
   Stack<int> Stack_3(3);
   Stack_3.~Stack();

   // Push and Pop
   Stack<int> Stack_0(1);
   Stack_0.push(2);
   Stack_0.push(new int(3));
   Stack_0.push(new node<int>(new int(4)));

   node_1 = Stack_0.pop();
   std::cout << node_1->getElem() << std::endl;
   delete node_1;

   Stack_0.printStack();
}

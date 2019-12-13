#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList(int first) {
   head = new node;
   head->val = first;
   head->next = NULL;
}

LinkedList::~LinkedList(){
   while (head != nullptr) {
      node* temp = head->next;
      delete head;
      head = temp;
   }
}

void LinkedList::printAll(){
   node* it = head;
   while (it!=nullptr) {
      std::cout << it->val << " ";
      it = it->next;
   }
   std::cout << std::endl;
}

void LinkedList::insert(node* newnode, pos position=END){
   if (position == END) { 
      node* it = head;
      while (it->next!=nullptr) {
         it = it->next;
      }
      it->next = newnode;
   }

   else {
      newnode->next = head;
      head = newnode;
   }
}

void LinkedList::deletenode(node* nodeptr){
   
   if (nodeptr == head){
      head = head->next;
      delete nodeptr;
      return;
   }

   node* prev = NULL;
   node* curr = head;

   while(curr != nodeptr) {
       prev = curr;
       curr = curr->next;
       if (curr == nullptr) {
          std::cout << "Ptr not found" << std::endl;
          return;
       }
   }

   prev->next = curr->next;
   delete curr;
}

node* LinkedList::search(int val){
   node* it = head;
   while(it != nullptr){
      if (it->val == val)
	  return it;
      else
          it = it->next;
   }
   std::cout << "Value not found" << std::endl;
   return NULL;
}

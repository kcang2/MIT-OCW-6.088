#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList(int first) {
   head = new node;
   head->val = first;
   head->next = NULL;
   length = 1;
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

void LinkedList::insert(node* newnode, pos position){
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

   length += 1;
}

void LinkedList::insert(int val, pos position){
   node* temp = new node;
   temp->val = val;
   insert(temp, position);
}

void LinkedList::deleteNode(node* nodeptr){
   
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

   length -= 1;
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

node* LinkedList::getHead(){ return head;}

int LinkedList::getLength(){ return length;}

node* LinkedList::find(int index, bool isPrev=false){
   int r;
   if (isPrev)  r = index-2;
   else  r = index-1;

   if (r<0)  return NULL;
   
   node* temp = head;
   for (int i=0; i<r; ++i) {
      if (temp != nullptr)  temp = temp->next;
      else  return NULL;
   }

   return temp;
}

LinkedList& mergeLists(LinkedList& list1, LinkedList& list2, int a, int b){
   int l1 = list1.length;
   int l2 = list2.length;

   if( b < a || b < 1 || a > l1 ) {
      return list1;
   }

     bool twoOne, oneTwo;
     if(a<2) twoOne = true;
     else  twoOne = false;
  
     if(b>=l1)  oneTwo = true;
     else  oneTwo = false;

   if(twoOne && oneTwo){
       return list2;
   }

   else if(twoOne && !oneTwo){
      node* bNode = list1.find(b);
      node* l2_tail = list2.find(l2);
      l2_tail->next = bNode->next;
      list2.length += l1-b;

      bNode->next = NULL; // cut-off to allow easier deletion
      return list2;
   }
   
   else if(!twoOne && oneTwo){
      node* aNode = list1.find(a, true);
      node* temp = aNode->next;
      aNode->next = list2.head;
      list1.length += l2-(l1-a+1);

      list2.head = temp;
      return list1;
   }

   else{ 
      node* aNode = list1.find(a, true);
      node* bNode = list1.find(b);
      node* l2_tail = list2.find(l2);

      node* temp = aNode->next;
      aNode->next = list2.head;
      l2_tail->next = bNode->next;
      bNode->next = NULL;
      list1.length += l2-(b-a+1);

      list2.head = temp;
      return list1;
   }
}


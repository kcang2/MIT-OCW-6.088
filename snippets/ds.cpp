#include "ds.h"
#include <iostream>

// Explicit template instantiation
template class node<int>;
template class Stack<int>;

/////////////////////////////////////////////////////////////////////////////

template <typename T>
node<T>::node(T* newElem){
   next = nullptr;
   elem = newElem;
}

template <typename T>
T node<T>::getElem(){
   return *elem;
}

template <typename T>
node<T>::~node(){
   delete elem;
}

//////////////////////////////////////////////////////////////////////////////

template <typename T>
Stack<T>::Stack(){
   head = nullptr;
   size = 0;   
}

template <typename T>
Stack<T>::Stack(node<T>* newElem){
   head = newElem;
   size = 1;
}

template <typename T>
Stack<T>::Stack(T* newElem){
   head = new node<T>(newElem);
   size = 1;
}

template <typename T>
Stack<T>::Stack(T newElem){
   head = new node<T>(new T(newElem));
   size = 1;
}

template <typename T>
int Stack<T>::getSize(){
   return size;
}

template <typename T>
const node<T>* Stack<T>::getHead(){
   return head;
}

template <typename T>
void Stack<T>::push(node<T>* newElem){
   node<T>* old = head;
   head = newElem;
   head->next = old;
   size = size + 1;
}

template <typename T>
void Stack<T>::push(T* newElem){
   node<T>* old = head;
   head = new node<T>(newElem);
   head->next = old;
   size = size + 1;
}

template <typename T>
void Stack<T>::push(T newElem){
   node<T>* old = head;
   head = new node<T>(new T(newElem));
   head->next = old;
   size = size + 1;
}

template <typename T>
node<T>* Stack<T>::pop(){
   node<T>* top = head;
   head = head->next;
   return top;
}

template <typename T>
Stack<T>::~Stack(){
   while (head!=nullptr) {
      node<T>* temp = head->next;
      delete head;
      head = temp;
   }
}

template <typename T>
void Stack<T>::printStack(){
   node<T>* temp = head;
   while (temp!=nullptr) {
      std::cout << *(temp->elem) << " ";
      temp = temp->next;
   }
   std::cout << std::endl;
}

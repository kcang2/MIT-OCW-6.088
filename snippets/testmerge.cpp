 #include "linkedlist.h"
 #include <cstddef>
 #include <iostream>
 
 int main(){
    LinkedList list1 = LinkedList(5);
    for(int i=4;i>0;--i)  list1.insert(i);
    //list1.printAll();

    LinkedList list2 = LinkedList(-1);
    for(int i=-2;i>-4;--i)  list2.insert(i);
    //list2.printAll();

    // out-of-range
    //LinkedList& merged = mergeLists(list1, list2, 0, 0);
    //LinkedList& merged = mergeLists(list1, list2, 6, 7);
    //LinkedList& merged = mergeLists(list1, list2, 4, 1);

    // starting edge case
    //LinkedList& merged = mergeLists(list1, list2, 1, 1);
    //LinkedList& merged = mergeLists(list1, list2, 0, 1);
    //LinkedList& merged = mergeLists(list1, list2, 1, 3);
 
    // ending edge case
    //LinkedList& merged = mergeLists(list1, list2, 3, 6);
    //LinkedList& merged = mergeLists(list1, list2, 3, 5);
    //LinkedList& merged = mergeLists(list1, list2, 5, 5);
    
    // In-between
    //LinkedList& merged = mergeLists(list1, list2, 2, 4);
    //LinkedList& merged = mergeLists(list1, list2, 2, 3);
    //LinkedList& merged = mergeLists(list1, list2, 3, 3);

    // replace
    LinkedList& merged = mergeLists(list1, list2, -1, 8);

    std::cout << merged.getLength() << std::endl;    
    merged.printAll();
 }


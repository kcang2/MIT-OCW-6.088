typedef struct node {
   int val;
   node* next;
} node;

typedef enum position {
  START, END
} pos;

class LinkedList {
   node* head;
   int length;
   friend LinkedList& mergeLists(LinkedList& list1, LinkedList& list2, int a, int b);

public:
   int getLength();
   node* getHead();

   node* search(int val);
   node* find(int index, bool isPrev);
   
   void deleteNode(node* nodeptr);
   void insert(int val, pos position=START);
   void insert(node* newnode, pos position=END);
   void printAll();

   LinkedList(int first);
   ~LinkedList();
};

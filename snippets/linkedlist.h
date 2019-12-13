typedef struct node {
   int val;
   node* next;
} node;

typedef enum position {
  START, END
} pos;

class LinkedList {
   node* head;

public:
   node* search(int val);
   void deletenode(node* nodeptr);
   void insert(node* newnode, pos position);
   void printAll();
   LinkedList(int first);
   ~LinkedList();
};

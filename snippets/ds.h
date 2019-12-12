
template <typename T>
class node{
  T* elem;
  node<T>* next;
  template <typename U> friend class Stack;
  // TODO: add queue as friend later

  public:
     node(T* newElem);
     T getElem();
     ~node();
};

template <typename T>
class Stack{
  node<T>* head;  // pointer to top element
  int size;  // number of elements

  public:
    int getSize();  // how many elements?

    const node<T>* getHead();  // reference to first element without popping

    void printStack();

    void push(node<T>* newElem);  // add new element to top
    void push(T* newElem);
    void push(T newElem);

    node<T>* pop();  // remove and return first element

    Stack();  // construct empty stack
    Stack(node<T>* newElem);  // construct stack with element
    Stack(T* newElem);  // construct stack with element (unwrapped)
    Stack(T newElem);

    ~Stack();  // destruct stack and all nodes
};


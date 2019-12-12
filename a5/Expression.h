#ifndef EXPRESSION
#define EXPRESSION

class Expression {

 public: 
  virtual ~Expression() {}
  
  // Returns the result of evaluating this expression.
  virtual float eval() = 0;

  // Prints the expression. DO NOT evaluate before printing.
  virtual void print() = 0;  
};

#endif  // EXPRESSION

#include <stack>
#include <vector>
#include <string>

using namespace std;

typedef enum TokenType {
   OPERATOR, OPERAND, LPAR, RPAR
} token_type;

typedef enum Operator {
   ADD, SUB, MUL, DIV, NEG
} op_type;

const unsigned int op_prec[] = {0, 0, 1, 1, 2};

typedef union token {
   op_type op;
   float val;
} token;

typedef struct node{
   token* elem;
   token_type t_type;
} node;

class ArithmeticExpression: public Expression{
   stack<node*> out;
   stack<node*> ops;
   deque<node*> q;
   string input;

   void string2infix();
   void infix2answer();
   void operate();
   void string2float(string& temp);

   public:
     ~ArithmeticExpression();
     ArithmeticExpression(string input): input(input){};
     float eval();
     void print(); 
};



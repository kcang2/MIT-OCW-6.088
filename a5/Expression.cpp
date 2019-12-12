#include "Expression.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

float ArithmeticExpression::eval() {
   string2infix();
   infix2answer();
   cout << out.top()->elem->val << endl;
   return out.top()->elem->val;
}

void ArithmeticExpression::print() {
   for (auto it=q.cbegin(); it!=q.cend(); ++it) {
      if ((*it)->t_type == OPERAND)
         cout << (*it)->elem->val << '_';
      
      else{
         if ((*it)->t_type == LPAR || (*it)->t_type == RPAR)
            cout << ((*it)->t_type == LPAR? '(': ')') << '_';
         else {
            switch((*it)->elem->op) {
               case ADD:
                  cout << '+' << '_';
                  break;
               case SUB:
                  cout << '-' << '_';
                  break;
               case MUL:
                  cout << '*' << '_';
                  break;
               case DIV:
                  cout << '/' << '_';
                  break;
               case NEG:
                  cout << '!' << '_';
                  break;
               default:
                  cout << '?' << '_';
            } // end switch
         } // end else
      }  // end else
   }  // end for
   cout << endl;      
} // end print

void ArithmeticExpression::string2infix() {
   // Remove white-space
   // remove_if just pushes whitespace to the rear, and returns
   // the iterator where whitespace begins.
   // erase then removes from the start to the end of whitespaces
   input.erase(remove_if(input.begin(), 
                         input.end(),
                         // lambda expression. Returns true if isspace
                         [](unsigned char x){return std::isspace(x);}
                         ), input.end());
   string temp;  // to read floats

   for(char& c : input) {

      if(c=='(' || c==')') {
         string2float(temp);  // add float (if needed)
         node* n = new node;
         n->t_type = (c=='('? LPAR: RPAR);
         q.push_back(n);
      }  // PARANTHESES
      
      else if(c=='+' || c=='-' || c=='*' || c=='/') {
         string2float(temp);  // add float if needed
         node* n = new node;
         n->t_type = OPERATOR;
         n->elem = new token;

         switch(c){
            case '+':
               n->elem->op = ADD;
               break;
            case '-':
               // Negative if at start of string or follows operator or '('
               if(q.empty())
                  n->elem->op = NEG;
               else if(q.back()->t_type==OPERATOR || q.back()->t_type==LPAR)
                  n->elem->op = NEG;
               else
                  n->elem->op = SUB;
               break;
            case '*':
               n->elem->op = MUL;
               break;
            case '/':
               n->elem->op = DIV;
               break;
            default:
               cout<< "Encountered unknown operator"<<c<<endl;
         }
         q.push_back(n);
      }  // OPERATORS
      
      else  // OPERANDS
        temp += c; 

   }  // end for

}  // end string2infix


void ArithmeticExpression::string2float(string& temp){
   if (temp.empty())  // continuous operators or parantheses
      return;
   else {
      float flt = stof(temp);

      node* n = new node;
      n->elem = new token;
      n->t_type = OPERAND;
      n->elem->val = flt;

      q.push_back(n);
      temp.clear();
   }   
}


void ArithmeticExpression::infix2answer(){ 

   while (!q.empty()) {

      auto it = q.begin();
 
      if ((*it)->t_type==OPERAND)
         out.push(*it);

      else if((*it)->t_type==LPAR)
         ops.push(*it);

      else if((*it)->t_type==RPAR) {
         while (ops.top()->t_type!=LPAR)
            operate();
         // delete LPAR
         delete ops.top();
         ops.pop();

         // delete RPAR
         delete (*it);
      }  // end else-if RPAR

      else {  // LEFT OR RIGHT ASSOC. OPERATORS
          while(true) {
             // empty, parenthesis or lower precedence
             if (ops.empty())
	       break;
             if (ops.top()->t_type == LPAR || ops.top()->t_type == RPAR)
               break;
             if (  ((op_prec[ops.top()->elem->op] < op_prec[(*it)->elem->op]) 
                 && (*it)->elem->op != NEG) ||
                   ((op_prec[ops.top()->elem->op] <= op_prec[(*it)->elem->op])
                 && (*it)->elem->op == NEG) )
                 break;
             // evaluate
             operate();
          }

          ops.push(*it);
      }  // end if (+-*/!)

      q.pop_front();  // remove 1st elem but dont free
   }  // end while

   while(!ops.empty())
      operate();  // evaluate all remaining operators

}  // infix2answer


void ArithmeticExpression::operate() {

   // Check operator (get reference to top element)
   node* oper = ops.top();
   ops.pop(); // just remove address from stack

   if (oper->elem->op != NEG) {  // Not negative

      node* first = out.top();
      out.pop(); // just remove address from stack

      node* second = out.top();

      switch(oper->elem->op){
         case ADD:
            second->elem->val += first->elem->val;
            break;
         case SUB:
            second->elem->val -= first->elem->val;
            break;
         case MUL:
            second->elem->val *= first->elem->val;
            break;
         case DIV:
            second->elem->val /= first->elem->val;
            break;
         default:
            cout << "Unknown Operation with 2 Operands" << endl;
      }  // end switch-case
      
      // Clean up
      delete first->elem;
      delete first;
   }  // end if

   else {  // Negative
      node* first = out.top(); 
      first->elem->val = -(first->elem->val); 
   }

   delete oper->elem;
   delete oper;
}


ArithmeticExpression::~ArithmeticExpression(){ 
   // Parantheses have no tokens 
   for (auto it=q.begin(); it!=q.end(); ++it) {
      if ((*it)->t_type != LPAR && (*it)->t_type != RPAR)
          delete (*it)->elem;
      delete *it;
   }

   // Delete output stack
   delete out.top()->elem;
   delete out.top();
   out.pop();
}



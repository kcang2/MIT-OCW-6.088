#include "Expression.h"

using namespace std;

int main(){
   ArithmeticExpression AE("- 3.1 +(-2*4- 1/1.0+-0)");
   AE.eval();
}


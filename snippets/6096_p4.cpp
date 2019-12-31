#include <iostream>
#include <vector>

template <typename T>
T min(T x, T y) {
   if (x < y)
	return x;
   else
	return y;
}

template <typename T>
T min_pm(T x, T y) {
   return x < y ? x : y;
}

template <typename T>
class Stack{
   std::vector<T> v;
   template <typename U>
   friend Stack<U> operator+(Stack<U> a, Stack<U> b);

public:

   bool empty(){
      return v.empty();
   }
   void push(const T &item){
      v.emplace(v.begin(), item);
   }
   void show(){
      for (auto i = v.begin(); i != v.end(); ++i)
      std::cout << *i << ' ';
   }  
   T& top(){
      return v.front();
   }
   void pop(){
      if (!empty())
         v.erase(v.begin());
   }
};

template <typename T>
Stack<T> operator+(Stack<T> a, Stack<T> b){
    Stack<T> c;
    c.v.insert(c.v.end(), a.v.begin(), a.v.end());
    c.v.insert(c.v.end(), b.v.begin(), b.v.end());
    return c;
}

int main()
{
    Stack<int> a;
    int myint = 2;
    a.push(myint);
    myint = 4;
    a.push(myint);

    Stack<int> b;
    myint = 2;
    b.push(myint);
    myint = 1;
    b.push(myint);

    Stack<int> c = a + b;
    c.show();


    return 0;
}


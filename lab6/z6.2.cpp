/*
Zmodyfikuj prosty szablon stosu:
template<typename T = int , size_t N = 100> class Stack {
przez dodanie nowego parametru,który będzie określał klasę wytyczną do sprawdzenia zakresu pamięci:
template<typename T = int , size_t N = 100,
typename Checking_policy = No_checking_policy > class Stack {
privat
T _rep[N];
size_t _top; ….
Klasa wytycznych powinna posiadać minimum 3 funkcje składowe: check_push(size_t,size_t), check_pop(size_t) 
oraz check_top(size_t). Zaimplementuj przykłady klasy wytycznych dla strategii: braku sprawdzania 
(No_checking_policy) oraz przerywania działania (Abort_on_error_policy).
*/


#include<stdlib.h>
#include<iostream>
#include<stdexcept>
#include<algorithm>



struct No_checking_policy;
struct Abort_on_error_policy;
struct Std_exception_on_error_policy;


template<typename T = int , size_t N = 100,
	 typename Checking_policy = No_checking_policy >  
class Stack {
  T  _rep[N];
  size_t _top;
public:
  Stack(size_t n = N):_top(0) {};

  void push(const T &val) {
    Checking_policy::check_push(_top,N);
    _rep[_top++]=val;
  }

  void pop()              {
    Checking_policy::check_pop(_top);
    --_top;
  }
  
  const T top()  const   {
    Checking_policy::check_top(_top);
    return &_rep[_top-1];
  }

   T &top()     {
    Checking_policy::check_top(_top);
    return _rep[_top-1];
  }

  bool is_empty()         {
    return !_top;
  } 
};

const int n=10;

int main() {
  using namespace std;
Stack<int,10>                                  s_no_check;
Stack<double , 10,Abort_on_error_policy>       s_abort;
Stack<int *,25,Std_exception_on_error_policy>  s_except;

s_no_check.pop(); //nothing
s_abort.pop(); //abort
}


struct No_checking_policy {
  static void check_push(size_t,size_t) {};
  static void check_pop(size_t) {};
  static void check_top(size_t) {};
};

struct Abort_on_error_policy {
  static void check_push(size_t top,size_t size) {
   
    if(top >= size) {
      std::cerr<<"trying to push elemnt on full stack: aborting"<<std::endl;
      abort();
    }
  };
  
  static void check_pop(size_t top) {
      if(top == 0) {
      std::cerr<<"trying to pop an empty stack: aborting"<<std::endl;
      abort();
      }
  };
  static void check_top(size_t top) {
      if(top == 0) {
      std::cerr<<"trying to read from empty stack: aborting"<<std::endl;
      abort();
      }
  };
};

struct Std_exception_on_error_policy {

  static void check_push(size_t top,size_t size) {
   
    if(top >= size) {
      throw std::range_error("over the top");
    }
  };
  static void check_pop(size_t top) {
      if(top == 0) {
	throw std::range_error("poping empty");
      }
  };
  static void check_top(size_t top) {
      if(top == 0) {
	throw std::range_error("reading empty");
      }
  };
};



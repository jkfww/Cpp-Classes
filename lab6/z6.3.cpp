/*
W celu zaimplementowania różnych strategii przydziału pamięci dodajemy 
dodatkowy parametr szablonu, który sam będzie szablonem:
template<typename T = int , size_t N = 100,

typename Checking_policy = No_checking_policy,
template<typename U,size_t M> class Allocator_policy
= Static_table_allocator > class Stack;
Szablon typu Allocator_policy posiada jeden typ stowarzyszony i szereg funkcji. 
Na przykład szablon ze statyczną tablicą w pamięci:
template<typename T,size_t N = 0> struct Static_table_allocator {
typedef T rep_type[N];
void init(rep_type &,size_t) {};
void expand_if_needed(rep_type &,size_t) {};
void shrink_if_needed(rep_type &,size_t) {};
void dealocate(rep_type &){};
static size_t size() {return N;};
};

Zaimplementuj szablon stosu wykorzystujący dodatkowy parametr 
do alokacji oraz przykład klasy Dynamic_table_allocator.*/

#include <iostream>


struct No_checking_policy;
struct Abort_on_error_policy;
struct Std_exception_on_error_policy;
template<typename T, size_t N = 0> struct Static_table_allocator ;


template<typename T = int , size_t N = 100,
	 typename Checking_policy = No_checking_policy,  
         template<typename U,size_t M>  class Allocator_policy 
	 =  Static_table_allocator> 
class Stack {

  typedef typename Allocator_policy<T,N>::rep_type rep_type;
  rep_type  _rep;
  size_t _top;
  Allocator_policy<T,N> alloc;
public:
  Stack(size_t n = N):_top(0) {
    alloc.init(_rep,n);
  };

  void push(const T &val) {
    alloc.expand_if_needed(_rep,_top);
    Checking_policy::check_push(_top,alloc.size());
    _rep[_top++]=val;
  }

  void pop()              {
    Checking_policy::check_pop(_top);
    --_top;
    alloc.shrink_if_needed(_rep,_top);
  }
  
  const T& top()  const   {
    Checking_policy::check_top(_top);
    return _rep[_top-1];
  }

   T& top()     {
    Checking_policy::check_top(_top);
    return _rep[_top-1];
  }

  
  bool is_empty()         {
    return !_top;
  } 

  ~Stack() {alloc.dealocate(_rep);}

};


template<typename T,size_t N> struct Static_table_allocator {
  typedef T rep_type[N];
  void init(rep_type &,size_t) {};
  void expand_if_needed(rep_type &,size_t) {};
  void shrink_if_needed(rep_type &,size_t) {};
  void dealocate(rep_type &){};

  static size_t size() {return N;};

};


template<typename T,size_t N > struct Dynamic_table_allocator {
  typedef T * rep_type;
  size_t _size;
  void init(rep_type &rep,size_t n) {_size=n;rep = new T[_size];};
  void expand_if_needed(rep_type &,size_t) {};
  void shrink_if_needed(rep_type &,size_t) {};
  void dealocate(rep_type &rep){delete [] rep;};

  size_t size() const {return _size;};


};

template<typename T,size_t N > struct Expandable_new_allocator {
  typedef T * rep_type;
  size_t _size;
  void init(rep_type &rep,size_t n) {_size=n;rep = new T[_size];};
  void expand_if_needed(rep_type & rep,size_t top) {
    if(top == _size) {
      _size=2*_size;
      T *tmp= new T[_size];
      std::copy(rep,&rep[top],tmp);
      delete [] rep;
      rep = tmp;
    }
  };
  void shrink_if_needed(rep_type &size_t) {
  };
  void dealocate(rep_type &rep){delete [] rep;};

  size_t size() const {return _size;};

};



//main

int main() {
  int n=10;
  Stack<int,0,Std_exception_on_error_policy,Dynamic_table_allocator > s1(n);
  Stack<int,10,Abort_on_error_policy,Static_table_allocator > s2(n);
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

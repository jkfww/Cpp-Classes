/*4. Wykorzystując prywatne dziedziczenie wykonaj modyfikację i przenieś zmienną _rep (dane ze stosu) 
z klasy Stack do klasy wytycznej, która dokonuje alokacji. Zmodyfikuj odpowiednio klasę Stack.*/


#include<stdlib.h>
#include<iostream>
#include<stdexcept>
#include<algorithm>

struct No_checking_policy ;

template<typename T, size_t N = 0> struct Static_table_allocator ;



template<typename T = int , size_t N = 100,
	 typename Checking_policy = No_checking_policy,  
         template<typename U,size_t M>  class Allocator_policy 
	 = Static_table_allocator > 
class Stack: private Checking_policy, public Allocator_policy<T,N> {

  typedef typename Allocator_policy<T,N>::rep_type rep_type;

  size_t _top;

public:
  Stack(size_t n = N):_top(0) {
    Stack::init(n);
  };

  void push(const T &val) {
    Stack::expand_if_needed(_top);
    Checking_policy::check_push(_top,this->size());
    Stack::_rep[_top++]=val;
  }

  void pop()              {
    Checking_policy::check_pop(_top);
    --_top;
    Stack::shrink_if_needed(_top);
  }
  
  const T& top()  const   {
    Checking_policy::check_top(_top);
    return Stack::_rep[top-1];
  }
  
  bool is_empty()         {
    return !_top;
  } 

  ~Stack() {Stack::dealocate();}

};


template<typename T,size_t N> class Static_table_allocator {
protected:
  typedef T rep_type[N];
  rep_type _rep;
  void init(size_t) {};
  void expand_if_needed(size_t) {};
  void shrink_if_needed(size_t) {};
  void dealocate(){};

  static size_t size() {return N;};

};


template<typename T,size_t N > class Dynamic_table_allocator {
protected:
  typedef T * rep_type;
  rep_type _rep;
  size_t _size;
  void init(size_t n) {_size=n;_rep = new T[_size];};
  void expand_if_needed(size_t) {};
  void shrink_if_needed(size_t) {};
  void dealocate(){delete [] _rep;};

  size_t size() const {return _size;};
public:
  void resize(size_t n) {
      T *tmp= new T[n];
      std::copy(_rep,&_rep[(_size<n)?_size:n],tmp);
      delete [] _rep;
      _rep = tmp;
      _size=n;
  }
};

template<typename T,size_t N > class Expandable_new_allocator {
protected:
  typedef T * rep_type;
  rep_type _rep;
  size_t _size;
  void init(size_t n) {_size=n;_rep = new T[_size];};
  void expand_if_needed(size_t top) {
    if(top == _size) {
      _size=2*_size;
      T *tmp= new T[_size];
      std::copy(_rep,&_rep[top],tmp);
      delete [] _rep;
      _rep = tmp;
    }
  };
  void shrink_if_needed(size_t) {
  };
  void dealocate(){delete [] _rep;};

  size_t size() const {return _size;};

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

int main() {
    using namespace std;
    const int n = 10;
    Stack<int,n,Std_exception_on_error_policy,Dynamic_table_allocator > s(n);

    for(int i = 0;i<n;++i)
    s.push(i);

    s.resize(20);
    cout<<"11. push after resize"<<endl;
    s.push(0);
    cout<<"loop\n";
    while(1)
    s.pop();
}





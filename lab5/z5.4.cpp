/* Zdefiniuj szablon Strip, który jako funkcja typów dokonuje 
operacji usunięcia jednego lub obydwu kwalifikatorów 
(const oraz &) i uzyskanie gołego typu podstawowego.*/

#include <iostream>

//---z poprzedniego zadania:---

//dwa rozne typy <T, U>
template<typename T,typename U> class Is_convertible {
    typedef int one;
    typedef struct {int c[2];} two;
    //dwa typy rozniace sie rozmiarem

    static one test(U) ;
    static two test(...);
    static T makeT();

    public: enum {yes = sizeof(test(makeT()))==sizeof(one),
    same_type=false }; 
};

//ten sam typ <T, T>
template<typename T> class Is_convertible<T,T> {
    public:
    enum {yes = true, same_type=true }; 
};

//---------------------------------

template<typename T> struct Strip {
  typedef T arg_t;
  typedef T striped_t;
  typedef T base_t;
  typedef const T   const_type;
  
  typedef T&        ref_type;
  typedef T&        ref_base_type;
  typedef const T & const_ref_type;


};

template<typename T> struct Strip< T const> {
  typedef const T arg_t;
  typedef       T striped_t;
  typedef typename Strip<T>::base_t  base_t;
  typedef T const   const_type;

  typedef T const & ref_type;
  typedef T &       ref_base_type;
  typedef T const & const_ref_type;


};

template<typename T> struct Strip<T&> {

  typedef T& arg_t;
  typedef T  striped_t;
  typedef typename Strip<T>::base_t  base_t;
  typedef base_t const    const_type;

  typedef T               ref_type;
  typedef base_t &        ref_base_type;
  typedef base_t const &  const_ref_type;


};


int main() {

    using namespace std;

    string boolArray[] = {"false", "true"};
    int b;

    b = Is_convertible<Strip< const int&>::base_t,int>::same_type; 
    cout<<"same_type<Strip<const int&>::base_t, int>: "<<boolArray[b]<<endl;

    b = Is_convertible<Strip< const int&>::striped_t,const int>::same_type; 
    cout<<"same_type<Strip<const int&>::stripped_t, const int>: "<<boolArray[b]<<endl;

    b = Is_convertible<Strip< const int>::base_t,int>::same_type; 
    cout<<"same_type<Strip<const int>::base_t, int>: "<<boolArray[b]<<endl;

}
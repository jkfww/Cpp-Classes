/* Zmodyfikuj szablon operatora + którym dodajemy dwa wektory: 
template<typename T,typename U> std::vector<T> operator+(const std::vector<T> &a,
 const std::vector<U> &b). Modyfikacja polegać powinna na implementacji klasy cech 
 PROMOTION (będącą funkcją typów), która będzie określała typ wyniku na podstawie typu 
 składników. Wybierzemy następującą strategię: jeśli typy mają różny rozmiar to wybieramy 
 typ większy, jeżeli mają ten sam rozmiar to liczymy na specjalizacje. Dla identycznych 
 typów wynik jest jasny (choć jak przekonuje nas przykład 5.1 typ sumy nie musi być typem 
 składników). Resztę musimy definiować ręcznie korzystając ze specjalizacji pełnych. 
Specjalizację proszę sobie uprościć definiując odpowiednie makro MK_PROMOTION(T1,T2,Tr).*/

#include<iostream>
#include<vector>
#include <cassert>


//uzywamy ogolnego jesli flaga==true
template<bool flag,typename T1,typename T2> struct If_then_else {
typedef T1 Result; 
};

//uzywamy tej specjalizacji z false jesli sizeof(T1) < sizeof(T2)
template<typename T1,typename T2> 
struct If_then_else<false,T1,T2> {
typedef T2 Result; 
};

//wywoluje If_the_else dla flagi bool
template<typename T1,typename T2> struct PROMOTION {
typedef typename If_then_else<(sizeof(T1) > sizeof(T2)), T1,
typename If_then_else< (sizeof(T1)< sizeof(T2)), T2, void>::Result >::Result Result;
};

//ten sam typ
template<typename T> struct PROMOTION<T,T> {
  typedef T Result;
};




#define MK_PROMOTION(T1,T2,Tr)            \
    template<> class PROMOTION<T1, T2> {    \
      public:                             \
        typedef Tr ResultT;               \
    };                                    \
                                          \
    template<> class PROMOTION<T2, T1> {    \
      public:                             \
        typedef Tr ResultT;               \
    };

MK_PROMOTION(bool, char, int)
MK_PROMOTION(bool, unsigned char, int)
MK_PROMOTION(bool, signed char, int)
MK_PROMOTION(float, int, float)
MK_PROMOTION(float, unsigned int, float)
MK_PROMOTION(int, unsigned int,  int)
MK_PROMOTION(long int, double,  double)
MK_PROMOTION(unsigned long int, double,  double)


//jesli ten sam typ
template<typename T> std::vector<T> 
operator+(const std::vector<T>  &a, const std::vector<T>  &b) {
    
  assert(a.size()==b.size());

  std::vector<T> res(a);
  for(size_t i=0;i<a.size();++i)
    res[i]+=b[i];

  return res;
}



template<typename T,typename U> 
std::vector<typename PROMOTION<T,U>::Result>
operator+(const std::vector<T>  &a,
	  const std::vector<U>  &b) {

  assert(a.size()==b.size());

  std::vector<typename PROMOTION<T,U>::Result> res(a.size());
  for(size_t i=0;i<a.size();++i)
    res[i]=a[i]+b[i];

  return res;
}


int main() {

  using namespace std;

  vector<double> x;
  vector<double> y;
  vector<int>    l;

  for(int i=0; i<10; i++){
    x.push_back(1);
    y.push_back(2);
    l.push_back(3);
  }

  x = x+y;
  for(int i=0; i<10; i++){
    cout<<x[i]<<" ";
  }
  cout<<endl;

  x = l+x;
  for(int i=0; i<10; i++){
    cout<<x[i]<<" ";
  }

  cout<<endl;




}
/*
Szablony parametrów szablonu umożliwiają przekazanie nazwy szablonu
jako argumentu szablonu funkcji. Podaj prosty przykład jak można dedukować
wartości pozatypowych argumentów szablonu (void f(C<K>)).
*/


#include<iostream>
using namespace std;

template< template<int N> class  C, int K>
void f(C<K>){
  cout<<K<<endl;
};

//funkcja f ma 2 parametry
//1) klase C ktora ma parametr int N
//2) int K
//ale wywolujac funkcje f(C<K>) dedukujemy ze K==N, 
//i w konsekwencji wypisujemy int jakiego uzywalismy do tworzenia SomeClass

template<int N> 
struct SomeClass {
};
//struktura SomeClass posiada jeden parametr typu int


int main(){
  SomeClass<16>  c1;
  SomeClass<-3>  c2;

  f(c1); 
  f(c2); 
}
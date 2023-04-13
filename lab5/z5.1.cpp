/*
Zaimplementuj szablon is_class służący do sprawdzania czy dany typ jest klasą.
*/

#include<vector>
#include<iostream>


template<typename T> class Is_class {
    //-> dwa typy ktore roznia sie rozmiarem
    typedef int one;
    typedef struct {int c[2];} two;
  
  //-> dwa szablony, jeden z argumentem ktory uzywa :: (argumentem jest klasa)
  template<typename U> static one test(int U::*); 
  template<typename U> static two test(...);
  
  //jesli T jest klasa to zostanie uzyta funkcja test zwracacajaca one, wtedy wyrazenie ma wartosc true
  public:
  enum {yes = (sizeof(test<T>(0))==sizeof(one) )};
};

struct exampleStruct {};

int main(){

    using namespace std;

    cout<<"Is_class"<<endl;
    cout<<"int: "<<(Is_class<int>::yes ? "true" : "false")<<endl;
    cout<<"struct: "<<(Is_class<exampleStruct>::yes ? "true" : "false")<<endl;
    cout<<"vector: "<<(Is_class<vector<int>>::yes ? "true" : "false")<<endl;


}
/* Napisz szablon, który sprawdza czy jego parametr 
posiada typ stowarzyszony value_type, np.: 
has_value_type<std::vector<int> >::yes 
powinno mieć wartość true, 
a has_value_type<int>::yes wartość false.*/

#include <iostream>
#include <vector>

template<typename T> class has_value_type {
    //-> dwa typy ktore roznia sie rozmiarem
    typedef int one;
    typedef struct {int c[2];} two;
  
  //-> dwa szablony, jeden z argumentem ktory bierze U::value_type
  template <typename U> static one test(typename U::value_type v);
  template<typename U> static two test(...);
  
  //jesli T jest klasa to zostanie uzyta funkcja test zwracacajaca one, wtedy wyrazenie ma wartosc true
  public:
  enum {yes = (sizeof(test<T>(0))==sizeof(one) )};
};


struct exampleStruct {
    //typedef int value_type;
};

int main(){

    using namespace std;

    cout<<"has_value_type"<<endl;
    cout<<"int: "<<(has_value_type<int>::yes ? "true" : "false")<<endl;
    cout<<"struct: "<<(has_value_type<exampleStruct>::yes ? "true" : "false")<<endl;
    cout<<"vector: "<<(has_value_type<vector<int>>::yes ? "true" : "false")<<endl;
    cout<<"string: "<<(has_value_type<string>::yes ? "true" : "false")<<endl;

}
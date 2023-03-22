/*
Szablony parametrów szablonu umożliwiają przekazanie nazwy szablonu
jako argumentu szablonu funkcji. Podaj prosty przykład jak można dedukować
wartości pozatypowych argumentów szablonu (void f(C<K>)).
*/

#include<iostream>
using namespace std;

template< template<int N> class  C, int K>
void washVehicle(C<K>){
  cout<<"washing Time: "<<K*3<<endl;
};


template<int N> 
struct Vehicle {
  int numberOfWheels = N;
};

int main(){
  Vehicle<4>  v1;
  Vehicle<8>  v2;

  washVehicle(v1); 
  washVehicle(v2); 
}
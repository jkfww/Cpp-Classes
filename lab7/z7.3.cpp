/*3. Wymyśl i zaimplementuj jako metaprogram szybszy algorytm funkcji pow(x).*/

#include <iostream>

template<int N> inline double pow(int x) {return x*pow<N-1>(x);}
template<>      inline double pow<0>(int x) {return 1.0;}

int main(){

  double z = pow<62>(2);
  
}
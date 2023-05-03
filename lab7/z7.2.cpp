/*2. Zaimplementuj szablon Pow<N,M> obliczający N^M.*/

#include<iostream>


template<int N,int  M> struct Pow {
  enum {val=N*Pow<N,M-1>::val};
};

template<int N> struct Pow<N,0> {
  enum {val=1};
};


int main() {
    using namespace std;
    cout<< Pow<4,3>::val <<endl;
    cout<< Pow<2,10>::val <<endl;
}
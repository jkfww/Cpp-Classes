/*1. Napisz szablon funkcji lub klasy wyliczający funkcję silnia.*/

#include<iostream>

template<int  N> struct Factorial {
  enum {val=N * Factorial<N-1>::val};
};

template<> struct Factorial<0> {
  enum {val=1};
};


int main() {
    using namespace std;
    cout<< Factorial<3>::val <<endl;
    cout<< Factorial<4>::val <<endl;
    cout<< Factorial<10>::val <<endl;
    cout<< Factorial<12>::val <<endl;
}
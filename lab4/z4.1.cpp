/*Zaimplementuj szablon funkcji sumującej elementy dla podanego zakresu wskaźników. 
Przygotowując odpowiednie klasy cech sum_traits dla każdego z typów (char, int, float, double) 
zadbaj o poprawność typu zmiennej total, która w szablonie sum przechowuje wartość kolejnych kroków sumowania. */

#include<iostream>
#include <string.h>
#include <array>
using  namespace std;

template<typename T>  struct sum_traits;


template<>  struct sum_traits<char> {
typedef int sum_type; 
};
template<>  struct sum_traits<int> {
typedef long int sum_type; 
};
template<>  struct sum_traits<float> {
typedef double sum_type; 
};
template<>  struct sum_traits<double> {
typedef double sum_type; 
};

template<typename T> 
typename sum_traits<T>::sum_type sum(T *beg,T *end) { 
  typedef typename sum_traits<T>::sum_type sum_type;
  sum_type total = sum_type(); 
  while(beg != end ) { 
    total += *beg; 
    beg++; 
  } 
  return total; 
};


int main() {
char name[]="abc";
int length=strlen(name);
cout<<sum(name,&name[length])<<endl;

int arr[]= {1, 2, 3, 4};
int size = sizeof(arr)/sizeof(int);
cout<<sum(arr, arr+size)<<endl;

}
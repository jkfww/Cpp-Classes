/*Rozwiązać za pomocą klas cech również problem inicjalizacji zmiennej total. */

#include <iostream>
#include <string.h>

template<typename T>  struct sum_traits;

template<>  struct sum_traits<char> {
typedef int  sum_type;
static  sum_type zero() {return 0;} 
};

template<>  struct sum_traits<float> {
typedef double  sum_type;
static  sum_type zero() {return 0.0;}
};


template<typename T> 
typename sum_traits<T>::sum_type sum(T *beg,T *end) { 
  typedef typename sum_traits<T>::sum_type sum_type;
  sum_type total = sum_traits<T>::zero(); 
  while(beg != end ) { 
    total += *beg; 
    beg++; 
  } 
  return total; 
}

int main() {

using namespace std;

char name[]="abc";
int length=strlen(name);
cout<<sum(name,&name[length])<<endl;

float arr[]= {1.2, 2.3, 3.4, 4.5};
int size = sizeof(arr)/sizeof(float);
cout<<sum(arr, arr+size)<<endl;
}
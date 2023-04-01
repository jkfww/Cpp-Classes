/*Szablony funkcji nie dopuszczają stosowania parametrów domyślnych. 
Można to ograniczenie obejść za pomocą przeciążenia szablonu definiując szablon o mniejszej 
ilości argumentów, który zwraca wynik podstawienia domyślnych parametrów do bardziej ogólnego szablonu. 
Zmienić implementację funkcji sum tak aby podając odpowiednią klasę cech (sum_char) jako pierwszy 
z argumentów szablonu można było zażądać sumowania znaków char do zmiennej total również typu char. 
Równocześnie, w przypadku gdy nie jest podana klasa cech, szablon powinien działać tak jak w zad. 2. */

#include<iostream>
#include <string.h>
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

template<typename Traits,typename T > 
typename Traits::sum_type sum(T *beg,T *end) { 
  typedef typename Traits::sum_type sum_type;
  sum_type total = sum_type(); 
  while(beg != end ) { 
    total += *beg; 
    beg++; 
  } 
  return total; 
};

template<typename T> 
typename sum_traits<T>::sum_type sum(T *beg,T *end) { 
  return sum<sum_traits<T>, T>(beg,end);
}


struct char_sum {
  typedef char sum_type;
};


int main() {
char name[]="@@@";
int length=strlen(name);

int arr[]= {1, 2, 3, 4};
int size = sizeof(arr)/sizeof(int);

 cout<<(int)sum(name,&name[length])<<endl;

 cout<<(int)sum<char_sum>(name,&name[length])<<endl;

 cout<<(int)sum<char>(name,&name[length])<<endl;

  cout<<sum<int>(arr ,&arr[size])<<endl;

}

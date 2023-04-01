/*Uogólnić funkcję sum, aby działała nie tylko ze wskaźnikami, ale i iteratorami. 
Widać, że tu użycie klas cech jest już niezbędne, musimy bowiem dowiedzieć się na 
obiekty jakiego typu wskazuje iterator. Nie można do tego celu użyć typów stowarzyszonych 
IT::value_type, bo jako iterator może zostać podstawiony zwykły wskaźnik. Dlatego w STL
 istnieje klasa iterator_traits, definiująca podstawowe typy dla każdego rodzaju iteratora. 
Korzystając z tej klasy zdefiniuj ogólny szablon funkcji sum. */

#include <iostream>
#include<iterator>
#include <string.h>
#include <vector>

using namespace std;

template<typename T>  struct sum_traits;

template<>  struct sum_traits<int> {
typedef long int sum_type; 
};

template<typename IT> 
typename sum_traits<typename iterator_traits<IT>::value_type>::sum_type 
sum(IT beg, IT end) { 
  typedef typename iterator_traits<IT>::value_type value_type;
  typedef typename sum_traits<value_type>::sum_type sum_type;
  sum_type total = sum_type(); 
  while(beg != end ) { 
    total += *beg; 
    beg++; 
  } 
  return total; 
}

int main(){

  vector<int> v;

  for(int i=0; i<5; i++){
    v.push_back(i);  
  }

  int t[] = {1, 2, 3};

  cout<<sum(v.begin(), v.end())<<endl;
  cout<<sum(t, t+3)<<endl;
}
/*
Zaimplementuj szablon funkcji accumulate, której pierwszy i drugi argument są iteratorami dowolnego kontenera STL. 
Funkcja ma za zadanie wyliczać sumę wszystkich elementów w przedziale podanych iteratorów. */

#include <iostream>
#include <vector>


template <class InputIterator, class T>
T accumulate(InputIterator first, InputIterator last, T init) {
T total=init;
for( ; first != last;++first) 
   total+= *first;
return total;
}

int main(){
    using namespace std;

    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(10);

    cout<<"Sum = "<<accumulate(v.begin(), v.end(), 0)<<endl;
}

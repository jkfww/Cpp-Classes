/*
Wykorzystując pozatypowe parametry szablonów przedstaw sposób
implementacji iloczynu (dot_product) skalarnego dwóch wektorów o
wymiarze N.
*/

#include <iostream>

template<size_t N, typename T>
T dot_product(T *a, T *b){
    T value = 0.0;
    for(size_t i=0; i<N; i++)
    {
        value += a[i] * b[i];
    }
    return value;
}

#define N 4

int main(){
    using namespace std;


    int a[N] = {1, 2, 1, 1};
    int b[N]= {3, 4, 1, 2};

    cout<<dot_product<N>(a, b)<<endl; 
}
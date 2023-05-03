/*6. Rozszerz powyższy szablon tak, aby również typ elementów wektora był parametrem szablonu:

template<size_t N, typename T> T dot(T *x, T *y);*/

#include <iostream>

template<size_t N, typename T, size_t I=0 >
struct DotProduct{
    static T calculate(T *x, T *y){
    return x[I] * y[I] + DotProduct<N, T, I+1>::calculate(x, y);
    }
};

template<size_t N, typename T>
struct DotProduct<N, T, N>{
    static T calculate(T *x, T *y){
        return T();
    }
};

template <size_t N, typename T>
T dot(T *x, T *y)
{
    return DotProduct<N, T>::calculate(x, y);
}


//poprawne
template<size_t N, typename T>
T dot_prod(T *x, T *y){
   
   if constexpr (N == 1){
        return x[0] * y[0];
   }else{
        return x[N-1] * y[N-1] + dot_prod<N-1, T>(x, y);
   }
}


int main(){
    using namespace std;
    int x[] = {1, 2, 3, 4};
    int y[] = {5, 6, 7, 8};
   
    cout<<dot<4>(x, y)<<endl;
    cout<<dot_prod<4, int>(x, y)<<endl;
}
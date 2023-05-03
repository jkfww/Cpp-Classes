/*5. Napisz szablon generujący funkcję implementującą iloczyn skalarny dwu wektorów.

template<size_t N> double inner(double *x, double *y);*/

#include <iostream>

template<size_t N, size_t I=0>
struct InnerProduct{
    static double calculate(double *x, double *y){
    return x[I] * y[I] + InnerProduct<N, I+1>::calculate(x, y);
    }
};

template<size_t N>
struct InnerProduct<N, N>{
    static double calculate(double *x, double *y){
        return 0.0;
    }
};

template<size_t N> 
    double inner(double *x, double *y){
        return InnerProduct<N>::calculate(x, y);
    }

//poprawne  ?
template<size_t N>
double dot_prod(double *x, double *y){
    
    return x[N-1] * y[N-1] + dot_prod<N-1>(x, y);
    
}
template<>
double dot_prod<1>(double *x, double *y){
    
    return x[0] * y[0];
    
}

//drugie poprawne
template<size_t N>
double dot_prod2(double *x, double  *y){
   
   if constexpr (N == 1){
        return x[0] * y[0];
   }else{
        return x[N-1] * y[N-1] + dot_prod2<N-1>(x, y);
   }
}

int main(){
    using namespace std;
    double x[4] = {1, 2, 3, 4};
    double y[4] = {5, 6, 7, 8};
    
    cout<<inner<4>(x, y)<<endl;
    cout<<dot_prod<4>(x, y)<<endl;
    cout<<dot_prod2<4>(x, y)<<endl;
}
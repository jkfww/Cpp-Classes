/*Zaimplementuj szablon funkcji maksimum() , wybierającej większy z
dwóch argumentów. Argumenty są jednakowego typu i posiadają operator< .
*/
#include <iostream>


template<typename T> T makismum(T a, T b){
    return (a<b)?b:a;
}

int main(){
    using namespace std;

    cout<<makismum(3, 5)<<endl;
    cout<<makismum(3.9, 5.1)<<endl;
    cout<<makismum(3, -5)<<endl;
    cout<<makismum("ela", "ja")<<endl;
}


/*Argumenty szablonu mogą być wydedukowane z argumentów funkcji.
Zaimplementuj funkcję convert, której zadaniem jest zmiana typu podanego
argumentu funkcji.*/

#include <iostream>

template<typename T, typename U>
T convert(U val){
    return (T) val;
}


int main(){
    using namespace std;

    cout<<convert<int>(33.73)<<endl;
    cout<<convert<char>(68)<<endl;

}
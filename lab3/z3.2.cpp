/*Na  przykładzie  szablonu  funkcji convert pokazać, 
 że  jest  możliwe zdefiniowanie dwóch funkcji o tej samej
nazwie i argumentach wywołania, różniących się 
tylko zwracanym typem.*/

#include <iostream>
using namespace std;

template<typename T,typename U> T convert(U u) {
  return static_cast<T>(u);
};

template<> int convert<int,double>(double u) {
    cout<<"zwracam int: ";
    return static_cast<int>(u);
};
template<> double convert<double,double>(double u) {
    cout<<"zwracam double: ";
    return static_cast<double>(u);
};

int main(){

    cout<<convert<int>(5.17)<<endl;
    cout<<convert<double>(5.17)<<endl;

}
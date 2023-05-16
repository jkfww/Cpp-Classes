//Wyjaśnij zastosowanie dwóch możliwych specjalizacji dla szablonu unique_ptr
//template< class T, class... Args > unique_ptr<T> make_unique( Args&&... args );
//template< class T > unique_ptr<T> make_unique( std::size_t size );

#include <iostream>
#include <memory>

class ExampleClass{
    int num;
public:
    ExampleClass(int n){
        num=n;
        std::cout<<"constructor"<<std::endl;
    };
};

int main(){

    //template< class T, class... Args > unique_ptr<T> make_unique( Args&&... args );
    auto ptr = std::make_unique<ExampleClass>(5);

    //template< class T > unique_ptr<T> make_unique( std::size_t size );
    auto ptr2 = std::make_unique<double[]>(3);

}

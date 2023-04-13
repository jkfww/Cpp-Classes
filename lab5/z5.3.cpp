/* Zaimplementuj szablon klasy Is_convertible za pomocą którego możliwe 
jest stwierdzenie czy jeden
 z typów można rzutować na drugi.*/

#include<vector>
#include<deque>
#include<iostream>
#include <string>

//dwa rozne typy <T, U>
template<typename T,typename U> class Is_convertible {
    typedef int one;
    typedef struct {int c[2];} two;
    //dwa typy rozniace sie rozmiarem

    static one test(U) ;
    static two test(...);
    static T makeT();

    public: enum {yes = sizeof(test(makeT()))==sizeof(one),
    same_type=false }; 
};

//ten sam typ <T, T>
template<typename T> class Is_convertible<T,T> {
    public:
    enum {yes = true, same_type=true }; 
};

int main() {

    using namespace std;

    string boolArray[] = {"false", "true"};

    cout<<"Is_convertible<double, int> : \t";
    cout<<boolArray[Is_convertible<double,int>::yes]<<endl;

    cout<<"Is_convertible<char, vector<double>::iterator> : \t";
    cout<<boolArray[Is_convertible<char, vector<double>::iterator>::yes]<<endl;

    cout<<"same_type<int, double> : \t";
    cout<<boolArray[Is_convertible<double,int>::same_type]<<endl;

    cout<<"same_type<size_t, unsigned int> : \t";
    cout<<boolArray[Is_convertible<size_t,unsigned int>::same_type]<<endl;

    cout<<"same_type<vector<double>::value_type, double> : \t";
    cout<<boolArray[Is_convertible<vector<double>::value_type,
    double >::same_type]<<endl;

    cout<<"same_type<vector<double>::iterator, double *> : \t";
    cout<<boolArray[Is_convertible<vector<double>::iterator,
    double *>::same_type]<<endl;
}
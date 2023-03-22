/*Zapoznaj  się  z  rodziną  funktorów  porównujących,  
do  której  należą  np. less<>(),   greater<>(),   less_equal<>(),  
 greater_equal<>().   Przypomnij sobie pojemnik std::set.
  Następnie napisz programik korzystający 
ze zbioru liczb posortowanego odwrotnie (czyli malejąco). */

#include <iostream>
#include <set>

int main(){
    using namespace std;

    set<int> set1; //default czyli rosnaco
    set<int, greater<>> set2; //malejaco

    set1.insert(5);
    set1.insert(8);
    set1.insert(2);

    set2.insert(5);
    set2.insert(8);
    set2.insert(2);

    cout<<"set1: ";
    for(auto it = set1.begin(); it!=set1.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<"set2: ";
    for(auto it = set2.begin(); it!=set2.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;



}
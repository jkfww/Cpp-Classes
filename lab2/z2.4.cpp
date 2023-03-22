/*Zaimplementuj klasę (funktor typu generator) SeqenceGen przy wykorzystaniu której wypełnij, 
za pomocą algorytmu generate_n, wektor sekwencją 20 pierwszych nieparzystych liczb całkowitych. 
Znajdź element większy od 4 przy wykorzystaniu adaptera bind2nd oraz algorytmu find_if. */


#include<iostream>
#include<vector>
#include<functional>


template<typename T> class SequenceGen {
private:
  T _start; 
  T _step;
public:
  SequenceGen(T start = T(),T step = 1 ):
  _start(start),_step(step){};

  T operator()() {T tmp=_start; _start+=_step; return tmp;}
};

const size_t n = 20 ;


int main(){

  using namespace std;
  using namespace placeholders;

  vector<int> v(n);

  generate_n(v.begin(), n, SequenceGen<int>(1,2));
  
  cout<<"Vector: ";
  for(int i=0; i<(int)v.size(); i++)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;

  vector<int>::iterator it = find_if(v.begin(), v.end(), bind(greater<int>(), _1, 4));
  
  if(it!=v.end())
  {
    cout<<"First greater than 4: "<<*it<<endl;
  }
  else{
    cout<<"Not found\n";
  }
    

}
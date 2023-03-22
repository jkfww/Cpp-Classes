/*
Wykład przedstawia prosty stos jako przykład pojemnika. Korzystając z
typu stowarzyszonego (typedef T value_type) zaimplementuj szablon funkcji
sumującej wszystkie elementy stosu.
*/

#include <iostream>

template<typename T, size_t N> 
class Stack{

    public:
    typedef T value_type;

    Stack():top(0) {};

    void push(T val){
        rep[top++]=val;
    }
    T pop(){
        return rep[--top];
    }
    bool is_empty(){
        return (top==0);
    } 

   
    private:
    
    int top;
    value_type rep[N];
};

template<typename S> typename S::value_type stack_sum(S stack){

    typename S::value_type total = 0;

    while(!stack.is_empty())
    {
        total+= stack.pop();
    }

    return total;


}



int main(){

    using namespace std;
    Stack<int, 100> stack;


    stack.push(2);
    stack.push(2);
    stack.push(3);
    
    cout<<stack_sum(stack)<<endl;

    Stack<double, 100> dstack;

    dstack.push(2.5);
    dstack.push(2.1);
    dstack.push(3.7);
    
    cout<<stack_sum(dstack)<<endl;
}
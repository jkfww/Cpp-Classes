/*Zaimplementuj krótki program w którym wykorzystany będzie polimorfizm dynamiczny oraz polimorfizm statyczny. */

#include <iostream>
#include <string>
using namespace std;

class Animal{

    protected:
    string name;
    public:
    Animal(string _name){name = _name;}
    virtual void saySomething() = 0;
};

class Dog: public Animal{
    
    public:
    Dog(string _name): Animal(_name){}
    virtual void saySomething(){
        cout<<"I'm "<<name<<" and I can't speak.\n";
    } 

};

class Baby{
    protected:
    string name;

    public:
    Baby(string _name){name = _name;}
    void saySomething(){
        cout<<"I'm "<<name<<" and I'm trying to speak.\n";
    }
};

template<typename T> void saying_template(T o){
    o.saySomething();
  }

int main()
{
    Dog dog("Alex");
    Baby baby("Jo");

    //polimorfizm dynamiczny
    dog.saySomething();

    //polimorfizm statyczny
    saying_template(dog);
    saying_template(baby);

}
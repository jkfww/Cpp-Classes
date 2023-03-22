/*Podaj implementacje funkcji maxx dla różnego typu argumentów. Skorzystaj z możliwości przeciążania 
i specjalizacji szablonów funkcji:
maxx(T a, T b)
maxx(T *a, T *b)
maxx(T *data,size_t n)
maxx(char *a,char *a)
maxx(const char *a,const char *a)
maxx(char *a,const char *a)*/

#include <iostream>
#include <string.h>

using namespace std;

template<typename T> T maxx(T a,T b) { //1
    cout<<"maxx 1\n";
    return (a>b)?a:b;
}


template<typename T> T maxx(T *data,size_t n) { //2
    cout<<"maxx 2\n";
    T _maxx = data[0];
    for(size_t i=0;i<n;i++)
    if(data[i]>_maxx) _maxx=data[i];
    return _maxx;
}

template<typename T> T* maxx(T *a, T *b) { //3
    cout<<"maxx 3\n";
    return ((*a)>(*b))?a:b;
}

template<> char *maxx(char *a,char *b) { //4
    cout<<"maxx 4\n";
    return (strcmp(a,b)>0)?a:b;
}

template<> const char* maxx(const char *a,const char *b) { //5
    cout<<"maxx 5\n";
    return (strcmp(a,b)>0)?a:b;
}

template<typename T> T maxx(char *a, const char *b) { //6
    cout<<"maxx 6\n";
    return (strcmp(a,b)>0)?a:b;
}



int main(){
    int a = 3, b = 2;
    int ab[2] = {2, 5};
    char s1[] = "abcd";
    char s2[] = "abdd";
    const char cs1[] = "abcd";
    const char cs2[] = "abca";

    //1
    cout<<maxx(a, b)<<endl;

    //2
    cout<<maxx(ab, 2)<<endl;

    //3
    cout<< *maxx(&a, &b)<<endl;

    //4
    cout<<maxx(s1, s2)<<endl;

    //5
    cout<<maxx(cs1, cs2)<<endl;

    //6
    cout<<maxx<const char *>(s1, cs2)<<endl;

}
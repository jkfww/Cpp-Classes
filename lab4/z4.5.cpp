/*Zapoznaj się z plikiem kategorie.cpp.(http://wazniak.mimuw.edu.pl/images/c/c4/Kategorie.cpp).
 Jest w nim przedstawiony sposób selekcji jednej spośród kilku implementacji algorytmu na podstawie
  możliwości oferowanych przez przekazany iterator; w tym konkretnym przykładzie rozróżniamy dwie grupy:
  iteratory o swobodnym dostępie oraz wszystkie inne. Rozszerz kod tak, aby wybierana była jedna z trzech możliwości:
 swobodny dostęp, dwukierunkowe, gorsze niż dwukierunkowe. */

#include <iostream>
#include <list>
#include <iterator>
#include <forward_list>

using namespace std;

template <typename Iter>
int perform(Iter i, forward_iterator_tag)
{
    cout << "everything else\n";

    return 1;
}

template <typename Iter>
int perform(Iter i, bidirectional_iterator_tag)
{
    cout << "bidirectional_iterator_tag\n";

    return 2;
}

template <typename Iter>
int perform(Iter i, random_access_iterator_tag)
{
    cout << "random_access_iterator_tag\n";

    return 3;
}

template <typename Iter>
inline int operation(Iter i)
{
    return perform(i, typename iterator_traits<Iter>::iterator_category());
}

int main()
{
     
    int t[3];
    operation(t);
    
    list<int> l;
    operation(l.begin());

    forward_list<int> fl;
    operation(fl.begin());
   

    return 0;
}
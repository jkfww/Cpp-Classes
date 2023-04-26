/*Przeanalizuj przykład zaczynający się od pliku glowny.cpp. 
Zamienia on nazwy zrozumiałe dla człowieka ("czarny", "zielony") na strukturki ze
 składowymi RGB, wykorzystując do tego celu fabrykę kolorów. Domyślną reakcją fabryki 
 na przekazanie nieznanej nazwy koloru powinno być rzucenie wyjątkiem, ale chcemy zachować
  możliwość zmiany tej defaultowej reakcji; wprowadzono więc klasę wytycznych. Zwróć uwagę 
  na podział tego projektu na poszczególne pliki źródłowe. Zaimplementuj w odrębnym pliku 
  (albo plikach) alternatywną politykę, która zamiast wyjątku zwraca pewien ustalony kolor 
  domyślny. Przerób ją następnie z klasy na 
szablon klasy tak, aby można było zadawać kolor domyślny jako trzy parametry tego szablonu.*/

#include <iostream>
using std::cin;
using std::cout;

#include "kolor.h"
#include "fab_kol.h"

template <int R=0, int G=0, int B=0>
struct PolitykaDefaultowegoKoloru //default zwroci 0,0,0
{
    Kolor nieznanyKolor(std::string nazwa)
    {
        return Kolor(R, G, B);
    }
};

struct NiebieskaPolityka //zwroci niebieski
{
    Kolor nieznanyKolor(std::string nazwa)
    {
        return Kolor(0, 0, 255);
    }
};



typedef PolitykaDefaultowegoKoloru<128, 128, 128> SzaraPolityka;

FabrykaKolorw<SzaraPolityka> szara_fabryka;
FabrykaKolorow<NiebieskaPolityka> niebieska_fabryka;



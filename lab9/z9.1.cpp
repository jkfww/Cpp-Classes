//1. Objaśnij działanie inteligentnych wskaźników: shared_ptr, unique_ptr


//std::unique_ptr realizuje ideę wyłącznej własności (ang. exclusive ownership). Oznacza to, iż jednocześnie
//powinien istnieć dokładnie jeden obiekt tego typu, wskazujący na konkretny obiekt w pamięci. Inaczej rzecz ujmując,
//std::unique_ptr zawsze jest wyłącznym właścicielem tego, na co wskazuje.
//
//nie można skopiować obiektu klasy std::unique_ptr
//w momencie usunięcia (zniszczenia) obiektu klasy std::unique_ptr, wywoływany jest też destruktor
//obiektu przechowywanego wewnątrz można dokonać przeniesienia (nie skopiowania !) obiektu,
//przechowywanego w jednym unikalnym wskaźniku, do innego unikalnego wskaźnika –
//        wskaźnik źródłowy staje się wtedy wskaźnikiem pustym

//std::shared_ptr
//W odróżnieniu od std::unique_ptr, std::shared_ptr opiera się na współdzieleniu właśności (ang. shared ownership)
//przechowywanego zasobu. Z tego powodu możemy posiadać wiele inteligentnych wskaźników typu std::shared_ptr,
//wskazujących na ten sam obiekt w pamięci.
//
//Ten koncept ma bardzo dużo wspólnego z realizacją automatycznego odśmiecania pamięci w innych językach programowania,
//ponieważ klasa std::shared_ptr ma zaimplementowany mechanizm tzw. zliczania referencji.
//
//Implementacja współdzielonego wskaźnika zawiera 2 główne elementy – wskaźnik na przechowywany obiekt oraz wskaźnik
//na dynamicznie alokowany licznik. Licznik mówi nam o tym, ile obiektów klasy std::shared_ptr pokazuje aktualnie na
//interesujący nas zasób. Jeśli wartość licznika spadnie do zera,
//przechowywany obiekt nie jest nam potrzebny – zostanie usunięty, a pamięć po nim zostanie poprawnie zwolniona.
//Zaimplementuj szablon funkcji SongFactory tak aby obiekt ‘song’ był wskaźnikiem typu unique_ptr
//dla obiektów klasy Song
//auto song = SongFactory(L"Michael Jackson", L"Beat It");
//oraz przedstaw działanie konstruktora i destruktora obiektu przechowywanego przez wskaźnik we wnętrzu inteligentnego wskaźnika.
//Wypełnij std::vector<std::unique_ptr<Song>> songs i pokaż, że zakresowa pętla „for” musi wykorzystywać referencje.

#include <memory>
#include <iostream>
#include <vector>


class Song{
public:
    std::wstring artist;
    std::wstring title;

    Song(std::wstring artist_, std::wstring title_) : title{std::move(title_)}, artist{std::move(artist_)}{
        std::wcout<<"constructor"<<std::endl;
    };
    ~Song() {
        std::wcout<<"deconstructor"<<std::endl;
    }

};

std::unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title) {
    return std::make_unique<Song>(artist, title);
}


int main() {
    using namespace std;
    auto song1 = SongFactory(L"Michael Jackson", L"Beat It");
    vector<unique_ptr<Song>> vector1;

    vector1.push_back(std::make_unique<Song>(L"Namie Amuro", L"Funky Town"));
    vector1.push_back(make_unique<Song>(L"Michael Jackson", L"Beat It"));


    for (const auto& song : vector1){
       wcout << L"Artist: " << song->artist << L" Title: " << song->title << std::endl;
    }

}
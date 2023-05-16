//2. Sprawdź czy wielkość inteligentnego wskaźnika różni się od wielkości zwykłego wskaźnika.
#include <iostream>
#include <utility>
#include <memory>

class Song{
    std::wstring artist;
    std::wstring title;
public:
    Song( std::wstring title_, std::wstring artist_) : title{std::move(title_)}, artist{std::move(artist_)}{};

};



int main() {
    Song* pSong = new Song(L"Nothing on You", L"Bruno Mars");
    std::unique_ptr<Song> song2(new Song(L"Nothing on You", L"Bruno Mars"));
    std::shared_ptr<Song> song3(new Song(L"Nothing on You", L"Bruno Mars"));
    std::weak_ptr<Song> song4 = song3;

    //This means that unique_ptr is exactly the same size as that pointer
    std::cout<<"Sizeof raw pointer: "<<sizeof(pSong)<<std::endl;
    std::cout<<"Sizeof unique_ptr: "<<sizeof(song2)<<std::endl;
    std::cout<<"Sizeof weak_ptr: "<<sizeof(song4)<<std::endl;
    //The size is two pointers; one for the object and one for the shared control block that contains the reference count.
    std::cout<<"Sizeof shared_ptr: "<<sizeof(song3)<<std::endl;
    return 0;
}

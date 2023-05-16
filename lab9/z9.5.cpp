//Pokaż, że używanie wskaźnika typu shared_ptr zapewnia wywołanie destruktora w przypadku znikania ostatniego z nich.

#include <iostream>
#include <memory>

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

std::shared_ptr<Song> create() {
    std::cout << "start create()" << std::endl;
    auto ptr = std::make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing");;
    std::wcout<<ptr->title<<std::endl;
    std::cout << "end create()" << std::endl;
    return ptr;
}

void use(std::shared_ptr<Song> ptr) {
    std::cout << "start use()" << std::endl;
    std::wcout<<ptr->title<<std::endl;
    std::cout << "end use()" << std::endl;
}

int main() {
    std::cout << "start main()" << std::endl;
    use(create());
    std::cout << "end main()" << std::endl;
}
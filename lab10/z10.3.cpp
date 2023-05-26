//Wyierz pięć różnych algorytmów i przedstaw przykład wykorzystania, w którym równoległe
// obliczenia przyśpieszą obliczenia proporcjonalnie do ilości występujących w procesorze rdzeni.

#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>

int main(){

//    count_if
    std::vector<int> v = {1, 5, 8, 3, 9, 6, 7, 8};
    int count_div4 = std::count_if(std::execution::par, v.begin(), v.end(), [](int i) { return i % 4 == 0; });
    std::cout << "numbers divisible by four: " << count_div4 << '\n';

//    remove_if
    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(std::remove_if(std::execution::par, str2.begin(), str2.end(),
                              [](unsigned char x) { return std::isspace(x); }),
               str2.end());
    std::cout<<str2<<"\n";

//    replace_if
    std::array<int, 10> s {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    std::replace_if(std::execution::par, s.begin(), s.end(),
                    [](auto && PH1) { return std::less<int>()(std::forward<decltype(PH1)>(PH1), 5); }, 55);
    for (int a : s)
        std::cout << a << ' ';
    std::cout << '\n';

//    copy_if
    std::vector<int> to_vector = {1, 4, 7, 0, 5, 2, 9};
    std::copy_if(std::execution::par, to_vector.begin(), to_vector.end(),
                 std::ostream_iterator<int>(std::cout, " "),
                 [](int x) { return x % 2 != 0; });
    std::cout << '\n';

//    any_of
    struct DivisibleBy
    {
        const int d;
        DivisibleBy(int n) : d(n) {}
        bool operator()(int n) const { return n % d == 0; }
    };
    std::vector<int> d = {1, 5, 2, 8, 0, 11, 43, 2, 14, 3};
    if (std::any_of(std::execution::par, d.cbegin(), d.cend(), DivisibleBy(7)))
        std::cout << "At least one number is divisible by 7\n";

}
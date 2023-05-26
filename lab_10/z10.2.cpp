//Program [...] zakończy się tragicznie z punktu widzenia programisty (core dupmed).
// Wykorzystując std::lock_guard zmodyfikuj lambda expression tak aby nie dochodziło do
// niezsynchronizowanego dostępu do wektora wyjściowego. Porównaj wydajność przy wykorzystaniu polityki typu seq.

#include <vector>
#include <iostream>
#include <algorithm>
#include <execution>
#include <mutex>
#include <chrono>


int main2() {

    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);
    std::vector<int> output;
    const auto start = std::chrono::high_resolution_clock::now();
    std::for_each(std::execution::seq, vec.begin(), vec.end(),[&](int elem) {

        if (elem % 2 == 0) {
            output.push_back(elem);
        }
    });
    const auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout<<"seq: "<< duration.count() <<"ms " << std::endl;


    std::vector<int> vec2(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);
    std::vector<int> output2;
    std::mutex m;
    const auto start2 = std::chrono::high_resolution_clock::now();
    std::for_each(std::execution::par, vec.begin(), vec.end(),[&](int elem) {
        std::lock_guard<std::mutex> lock{m};
        if (elem % 2 == 0) {
            output.push_back(elem);
        }
    });
    const auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration2 = end2 - start2;
    std::cout<<"par: "<< duration2.count() <<"ms " << std::endl;

}  
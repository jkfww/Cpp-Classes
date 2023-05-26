//Opisz wykorzystując funkcjonalne przykłady występujące w C++17 execution policy  :
//
//std::execution::sequenced_policy,  std::execution::parallel_policy
//
//std::execution::parallel_unsequenced_policy,

#include <algorithm>
#include <iostream>
#include <vector>
#include <execution>

int main1()
{
//    std::execution::seq
//    We create a vector of integers and then sort its elements using
//    the std::sort algorithm with the std::execution::seq policy. The result is a sorted vector with elements { 1, 2, 3, 4, 5 }.
    std::vector<int> v = { 5, 2, 3, 1, 4 };
    std::sort(std::execution::seq, v.begin(), v.end());
    for (auto i : v)
        std::cout << i << " ";
    std::cout<<std::endl;

//    std::execution::par
//    we create two vectors of integers v1 and v2, and then use the std::transform algorithm with the std::execution::par
//    policy to square the elements of v1 and store the result in v2. The result is a vector v2 with elements { 1, 4, 9, 16, 25 }.
    std::vector<int> v1 = { 1, 2, 3, 4, 5 };
    std::vector<int> v2(5);
    std::transform(std::execution::par, v1.begin(),
                   v1.end(), v2.begin(),

                   [](int x) { return x * x; });

    for (int i : v2) {
        std::cout << i << " ";
    }
    std::cout<<std::endl;

//     std::execution::par_unseq
//     we create a vector of integers and then use the std::for_each algorithm with the std::execution::par_unseq policy to print its elements
//     in parallel and unordered. The result can be any permutation of the input vector, depending on the order in which the elements are processed.
    std::vector<int> y = { 1, 2, 3, 4, 5 };
    std::for_each(std::execution::par_unseq, y.begin(),
                  y.end(),
                  [](int x) { std::cout << x << " "; });
}

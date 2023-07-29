#include "chapter14.h"

#include <algorithm>
#include <vector>
#include <iostream>


int main()
{
    constexpr int N = 5;
    typedef std::pair<int, int&> Ty;
    int a[N] = { 17, 4, 8, 10, 0 };
    std::vector<Ty> v;
    for (int i = 0; i < N; ++i) {
        v.emplace_back(i, a[i]);
    }

    // Print, just to be sure :)
    for (auto& x : v) {
        std::cout << x.first << ',' << x.second << std::endl;
    }

    std::sort(v.begin(), v.end(),
        [](const Ty& a, const Ty& b) { return a.second < b.second; });

    std::cout << "With std::reference_wrapper (good):" << std::endl;
    for (auto& x : v) {
        std::cout << x.first << ',' << x.second << std::endl;
    }

    for (auto& x : a) {
        std::cout << x << std::endl;
    }

    return 0;
}

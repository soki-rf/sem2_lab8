#include <iostream>
#include <vector>
#include <iterator>
#include <functional>

template <class It, class Out, class Compare = std::less<>>
Out merge(It first1, It last1, It first2, It last2, Out out, Compare cmp = Compare{}) {
    while (first1 != last1 && first2 != last2) {
        if (cmp(*first2, *first1)) {
            *out = *first2;
            ++first2;
        } else {
            *out = *first1;
            ++first1;
        }
        ++out;
    }

    while (first1 != last1) {
        *out = *first1;
        ++first1;
        ++out;
    }

    while (first2 != last2) {
        *out = *first2;
        ++first2;
        ++out;
    }

    return out;
}

int main() {
    std::vector<int> a = {1, 2, 6, 9};
    std::vector<int> b = {1, 1, 1, 3, 7, 8, 10, 11};
    std::vector<int> c(a.size() + b.size());

    merge(a.begin(), a.end(),
          b.begin(), b.end(),
          c.begin());
    for (auto val : c) {
        std::cout << val << " ";
    }
}

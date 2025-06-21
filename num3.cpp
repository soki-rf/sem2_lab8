#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <class It, class Compare>
void simple_inplace_merge(It first, It mid, It last, Compare cmp) {
    It i = first;  
    It j = mid;    

    while (i < j && j < last) {
        if (cmp(*i, *j)) {
            ++i;
        }
        else {
            auto temp = *j;
            It k = j;
            while (k != i) {
                *k = *(k - 1);
                --k;
            }
            *i = temp;
            ++i;
            ++j;
            ++mid; 
        }
    }
}

template <class It, class Compare = std::less<>>
void inplace_merge_sort(It first, It last, Compare cmp = Compare{}) {
    auto len = std::distance(first, last);
    if (len <= 1) return;

    It mid = first + len / 2;

    inplace_merge_sort(first, mid, cmp);
    inplace_merge_sort(mid, last, cmp);
    simple_inplace_merge(first, mid, last, cmp);
}

int main() {
    std::vector<int> v = {5, 2, 8, 1, 3, 7, 4, 6};
    std::cout << "Before: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    inplace_merge_sort(v.begin(), v.end());

    std::cout << "After: ";
    for (int x : v) std::cout << x << " ";

    return 0;
}

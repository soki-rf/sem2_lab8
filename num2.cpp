#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>


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

template <class It, class Out, class Compare = std::less<>>
Out merge_sort(It first, It last, Out out, Compare cmp = Compare{}) {
    auto size = std::distance(first, last);

    // Базовые случаи
    if (size == 0) return out;
    if (size == 1) {
        *out = *first;
        return ++out;
    }

    It mid = first;
    std::advance(mid, size / 2);

    using ValueType = typename std::iterator_traits<It>::value_type;
    std::vector<ValueType> left_sorted;
    std::vector<ValueType> right_sorted;

    merge_sort(first, mid, std::back_inserter(left_sorted), cmp);
    merge_sort(mid, last, std::back_inserter(right_sorted), cmp);

    return merge(
        left_sorted.begin(), left_sorted.end(),
        right_sorted.begin(), right_sorted.end(),
        out, cmp
    );
}

int main() {
    std::vector<int> v = {5, 2, 8, 1, 3, 7, 4, 6};
    std::vector<int> result;

    merge_sort(v.begin(), v.end(), std::back_inserter(result));

    for (int x : result) {
        std::cout << x << " ";
    }
}

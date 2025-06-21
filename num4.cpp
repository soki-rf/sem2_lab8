#include <iostream>
#include <vector>
#include <iterator>
#include <functional>

template<class It, class Compare = std::less<>>
void heap_sort(It first, It last, Compare cmp = Compare{}) {
    using std::swap;
    auto len = std::distance(first, last);
    if (len <= 1) return;
    
    auto heapify = [&](auto heapify, It start, size_t heap_size, size_t root) -> void {
        size_t largest = root;
        size_t left = 2 * root + 1;
        size_t right = 2 * root + 2;

        if (left < heap_size && cmp(*(start + largest), *(start + left))) {
            largest = left;
        }

        if (right < heap_size && cmp(*(start + largest), *(start + right))) {
            largest = right;
        }

        if (largest != root) {
            swap(*(start + root), *(start + largest));
            heapify(heapify, start, heap_size, largest);
        }
    };

    for (int i = len / 2 - 1; i >= 0; --i) {
        heapify(heapify, first, len, i);
    }

    for (int i = len - 1; i > 0; --i) {
        swap(*first, *(first + i));
        heapify(heapify, first, i, 0);
    }
}

int main() {
    std::vector<int> v = {5, 2, 8, 1, 3, 7, 4, 6};
    heap_sort(v.begin(), v.end());

    for (int x : v) {
        std::cout << x << " ";
    }
}

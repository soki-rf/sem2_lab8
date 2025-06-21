#include <iostream>
#include <algorithm>
#include <vector>


template <class It, class Compare=std::less<>>
void quick_sort(It first, It last, Compare cmp=Compare{}){
    if (first == last || next(first) == last) {
        return;
    }

    auto pivot = *prev(last);

    It middle = partition(first, prev(last),[&pivot, &cmp](const auto& item) {
            return cmp(item, pivot);
        });

    iter_swap(middle, std::prev(last));

    quick_sort(first, middle, cmp);
    quick_sort(next(middle), last, cmp);
}


int main(){
    std::vector<int> n = {5, 2, 8, 1, 3, 7, 4, 6};
    quick_sort(n.begin(),n.end());
    for (int x : n) std::cout << x << " ";
    return 0;
}

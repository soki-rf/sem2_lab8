#include <iostream>
#include <iterator>
#include <functional>
#include <vector>

using namespace std;

template <class It,class Compare = less<>>
void insort(It first,It last,Compare cmp=Compare{}) {
    if(first==last || next(first)==last) {
        return;
    }
    for(It i=next(first);i!=last;++i) {
        auto k=move(*i);
        It j=i;
        while (j!=first && cmp(k,*prev(j))) {
            *j=move(*prev(j));
            --j;
        }
        *j=move(k);
    }
}


int main() {
    vector<int> v = {5, 2, 8, 1, 3, 7, 4, 6};
    insort(v.begin(),v.end());
    for (int x : v) std::cout << x << " ";
    return 0;
}

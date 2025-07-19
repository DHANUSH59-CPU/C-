#include <iostream>
#include <set>

int main() {
    std::set<int> s = {2,4,3,5,2};
    int x = 2;

    auto it = s.lower_bound(x);  // first element not less than x
    for (auto itr = s.begin(); itr != it; ++itr) {
        std::cout << *itr << " ";
        // std::cout<<it;
    }

    return 0;
}

#include <iostream>
#include <set>

int main() {
    std::set<int> s = {1, 3, 5, 7, 9};
    int x = 5;

    auto it = s.lower_bound(x);
    if (it == s.begin()) {
        std::cout << "No element less than " << x << " found.\n";
    } else {
        --it;
        std::cout << "Element less than " << x << " is: " << *it << "\n";
    }

    return 0;
}

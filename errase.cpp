#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    int index = 2; // Removing the element at index 2 (value 30)

    if (index >= 0 && index < vec.size()) {
        vec.erase(vec.begin() + index);
    }

    // Print the vector after removal
    for (int num : vec) {
        std::cout << num << " ";
    }

    return 0;
}

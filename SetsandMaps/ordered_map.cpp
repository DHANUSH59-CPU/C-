#include <iostream>
#include <map>

int main() {
    // Create an ordered map
    std::map<int, std::string> orderedMap;

    // Insert key-value pairs into the map
    orderedMap[10] = "Ten";
    orderedMap[5] = "Five";
    orderedMap[20] = "Twenty";
    orderedMap[15] = "Fifteen";

    // Display elements of the map
    std::cout << "Elements in the ordered map: " << std::endl;
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Check if a key exists
    int searchKey = 10;
    if (orderedMap.find(searchKey) != orderedMap.end()) {
        std::cout << searchKey << " exists in the map with value: " << orderedMap[searchKey] << std::endl;
    } else {
        std::cout << searchKey << " does not exist in the map." << std::endl;
    }

    // Remove an element by key
    orderedMap.erase(5);
    std::cout << "After removing key 5, elements in the map: " << std::endl;
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}

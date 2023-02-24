#include <iostream>
#include "unordered-map/hashMap.h"

int main() {

    container::HashTable<int, std::string> testHash;
    std::cout << testHash.size() << std::endl;
    return 0;
}

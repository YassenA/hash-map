#include <iostream>
#include "unordered-map/hashMap.h"

int main() {

    UnorderedMap::HashTable<int, std::string> testHash;
    std::cout << testHash.size() << std::endl;
    return 0;
}

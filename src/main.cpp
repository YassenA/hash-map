#include <iostream>
#include "unordered-map/hashMap.h"

int main() {

    UnorderedMap::HashTable<std::string, int> testHash = { {"test", 54}, {"test2", 5}};
    //std::cout << testHash["test"] << std::endl;
    testHash["test"];
    //container::HashTable<std::string, int> testHash = { {"test", 54} };
    return 0;
}

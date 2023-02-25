#include <iostream>
#include "unordered-map/hashMap.h"

int main() {

    UnorderedMap::HashTable<std::string, int> testHash = { {"test", 54}, {"test2", 5} };
    //std::cout << testHash["test"] << std::endl;
    //testHash["test"];
    //container::HashTable<std::string, int> testHash = { {"test", 54} };
    std::cout << testHash.size() << std::endl;
    testHash.insert({ "voodo", 234 });
    std::cout << testHash.size() << std::endl;
    testHash.clear();
    std::cout << testHash.size() << std::endl;
    //std::cout << testHash["test"] << std::endl;
    return 0;
}

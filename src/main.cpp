#include <iostream>
#include "unordered-map/hashMap.h"

int main() {

    UnorderedMap::HashTable<std::string, int> testHash = { {"test1", 54}, {"test2", 5}, {"test3", 657}, {"test4", 523} };
    UnorderedMap::HashTable<std::string, int> testHash2 = { {"test3", 657}, {"test4", 523}, {"test5", 456}, {"test6", 345} };
    UnorderedMap::HashTable<std::string, int> testHash3 = { {"test3", 657} };

    //std::cout << testHash["test1"] << std::endl;
    //testHash["test"];
    //container::HashTable<std::string, int> testHash = { {"test", 54} };
    
    //testHash.insert({ "voodo", 234 });
    
    //std::cout << testHash.size() << std::endl;
    ////std::cout << testHash["test"] << std::endl;
    //testHash.reserve(1000);

    std::cout << (testHash == testHash2) << std::endl;

    //std::cout << testHash.size() << std::endl;
    //testHash.printTable();
    //std::cout << "\n";
    ////testHash.insert(testHash2);
    //testHash.removeByKey("test1");
    //testHash.removeByValue(5);
    //std::cout << "\n" << testHash.size() << std::endl;
    //testHash.printTable();

    //for (auto pair : testHash.getTable()) {
    //    std::cout << pair. << std::endl;
    // }
    
    //testHash.insert({ "voodo", 234 });
    //std::cout << testHash.size() << std::endl;
    //testHash.clear();
    //std::cout << testHash.size() << std::endl;
    //std::cout << testHash["test"] << std::endl;
    return 0;
}
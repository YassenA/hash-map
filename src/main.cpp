#include <iostream>
#include "unordered-map/hashMap.h"

int main() {

    //UnorderedMap::HashTable<std::string, int> testHash = { {"test1", 54}, {"test2", 5}, {"test3", 657}, {"test4", 523} };
    //UnorderedMap::HashTable<std::string, int> testHash2 = { {"test1", 54}, {"test2", 5}, {"test3", 657}, {"test4", 523} }; //{ {"test3", 657}, {"test4", 523}, {"test5", 456}, {"test6", 345} };
    //UnorderedMap::HashTable<std::string, int> testHash3 = { {"test3", 657} };
    UnorderedMap::HashTable<std::string, int> testHash = { {"1-1", 54}, {"1-2", 5}, {"1-3", 65}, {"1-4", 523}, {"1-1", 54} };
    UnorderedMap::HashTable<std::string, int> testHash2 = { {"2-1", 76}, {"2-2", 1} };
    UnorderedMap::HashTable<std::string, int> testHash3 = { {"3-1", 85834} };



    //std::cout << testHash["test1"] << std::endl;
    //testHash["test"];
    //container::HashTable<std::string, int> testHash = { {"test", 54} };
    
    //testHash.insert({ "voodo", 234 });
    
    //std::cout << testHash.size() << std::endl;
    ////std::cout << testHash["test"] << std::endl;
    //testHash.reserve(1000);

    //std::cout << (testHash == testHash3) << std::endl;
    //std::cout << testHash << std::endl;
    //testHash.insert(testHash2);
    //std::cout << testHash << std::endl;

    //testHash.printContents();
    //testHash.insert(testHash2);
    //testHash.printContents();

    testHash.printContents();
    testHash.merge(testHash2, testHash3);
    std::cout << "\n\n";
    testHash.printContents();
    std::cout << "\n\n";
    std::cout << testHash.count({ "1-1", 54 }) << std::endl;

    //testHash.eraseIf({ "test1", 54 });
    //UnorderedMap::HashTable<std::string, int> testHash4 = testHash + testHash3;
    //testHash.insert(testHash2);

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
#include <iostream>
#include "unordered-map/hashMap.h"

int main() {
    UnorderedMap::HashTable<std::string, int> testHash = { {"1-1", 54}, {"1-2", 5}, {"1-3", 65}, {"1-4", 523}, {"1-1", 54} };
    UnorderedMap::HashTable<std::string, int> testHash2 = { {"2-1", 76}, {"2-2", 1} };
    UnorderedMap::HashTable<std::string, int> testHash3 = { {"3-1", 85834}, {"3-2", 12} };
    UnorderedMap::HashTable<std::string, int> testHash4 = { {"4-1", 1238} };

    /// Functionality 
    // Lookup functions
    std::cout << testHash.at("1-1") << "\n"; // 54
    std::cout << testHash.containsKey("1-1") << "\n"; // true (1)
    std::cout << testHash.containsValue(51223) << "\n"; // false (0)
    std::cout << testHash.count({"1-1", 54}) << "\n"; // 2
    std::cout << testHash["1-1"] << "\n"; // 54
    testHash.printContents();
    std::cout << testHash.size() << "\n";

    // Modifiers
    testHash4.clear();
    testHash4.empty(); // true (1)
    testHash4.insert({{ "4-2", 5 }, { "4-2", 5 }});

    //testHash4.insert({ { "4-3", 1 }, { "4-4", 183 } });
    //testHash.printContents();
    
    //testHash4.insert({{ "4-3", 1 }, { "4-4", 183 }});
    // testHash4.insert(testHash);
    
    //testHash.emplace();

    testHash3.merge(testHash, testHash2);
    testHash3 = testHash + testHash2;
    testHash3.reHash();
    testHash3.removeByKey("3-1");
    testHash3.removeByValue(12);
    testHash3.reserve(30);
    testHash3.swap(testHash4);

    // Bucket interface
    std::cout << testHash.bucketSize(2) << "\n"; // 2
    std::cout << testHash.maxBucketCount() << "\n"; // 768614336404564650


   
    // Other
    std::cout << testHash.calculateLoadBalance() << "\n"; // 0.25
    std::cout << testHash.maxLoadFactor() << "\n";

    //testHash.printContents();
    //std::cout << "\n";
    //testHash.insert({ "voodo", 234 });
    //testHash.printContents();
    //std::cout << "\n\n";
    //testHash.clear();
    //std::cout << testHash.empty() << std::endl;
    //std::cout << "\n\n";
    //testHash.printContents();
    
    //std::cout << << "\n";

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

    //testHash.printContents();
    //testHash.merge(testHash2, testHash3);
    //std::cout << "\n\n";
    //testHash.printContents();
    //std::cout << "\n\n";
    //std::cout << testHash.count({ "1-1", 54 }) << std::endl;

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
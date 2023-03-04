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

    return 0;
}
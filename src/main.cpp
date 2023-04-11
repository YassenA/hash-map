#include <iostream>
#include "unordered-map/unorderedMap.h"

namespace HM = UM;

int main() {
    HM::HashTable<std::string, int> testHash = { {"1-1", 54}, {"1-2", 5}, {"1-3", 65}, {"1-4", 523}, {"1-1", 54} };
    HM::HashTable<std::string, int> testHash2 = { {"2-1", 76}, {"2-2", 1} };
    HM::HashTable<std::string, int> testHash3 = { {"3-1", 85834}, {"3-2", 12} };
    HM::HashTable<std::string, int> testHash4 = { {"4-1", 1238} };

    // === Functionality ===
    // Lookup functions
    HM::print(testHash.at("1-1"));
    HM::print(testHash.containsKey("1-1")); 
    HM::print(testHash.containsValue(51223)); 
    HM::print(testHash.count({ "1-1", 54 })); 
    HM::print(testHash["1-1"]); 
    testHash.printContents();
    HM::print(testHash.size()); 

    // Modifiers
    testHash4.clear();
    testHash4.empty();
    testHash4.insert({{ "4-2", 5 }, { "4-2", 5 }});

    testHash3.merge(testHash, testHash2);
    testHash3 = testHash + testHash2;
    testHash3.reHash();
    testHash3.removeByKey("3-1");
    testHash3.removeByValue(12);
    testHash3.reserve(30);
    testHash3.swap(testHash4);

    // Bucket interface
    HM::print(testHash.bucketSize(2)); // std::cout << testHash.bucketSize(2) << "\n";
    HM::print(testHash.maxBucketCount()); //std::cout << testHash.maxBucketCount() << "\n"; 

    // Other
    HM::print(testHash.calculateLoadBalance()); //std::cout << testHash.calculateLoadBalance() << "\n";
    HM::print(testHash.maxLoadFactor()); //std::cout << testHash.maxLoadFactor() << "\n";

    return 0;
}
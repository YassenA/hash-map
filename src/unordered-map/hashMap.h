#pragma once
#include <algorithm>
#include <list>
#include <vector>
#include <initializer_list>

namespace UnorderedMap {
	template<typename Key, typename Type, typename Hash = std::hash<Key>>
	
	class HashTable {
	private:
		using hashTable = std::vector<std::list<std::pair<const Key, Type>>>;
		using uInt = std::size_t;

		uInt mSize{}; // Size of the elements that have been inserted
		Hash mHash;  // Keeps track of the consutrcted hash 
		uInt mBucketCount{};

		std::vector<std::list<std::pair<const Key, Type>>> mTable; // Where the hash table is tored
	public:
		using mappedType = Type;
		using valueType = std::pair<const Key, mappedType>;

		// List initialisation constructor
		constexpr HashTable(std::initializer_list<valueType> hashList, const Hash& hash = Hash())
			: mSize{ hashList.size() },
			mHash{ hash }
		{}

		// Default constructor, empty initilisation 
		constexpr HashTable(const Hash& hash = Hash())
			: mSize{ 0 }
			, mHash{ hash }
			, mBucketCount{ 0 }

		{}

		// Copy constructor
		constexpr HashTable(const HashTable& otherTable)
			: mSize{ otherTable.mSize }
			, mSize{ otherTable.mSize }
			, mTable{ otherTable.mTable }
		{}

		// Swap constructor 
		constexpr HashTable(HashTable&& other) noexcept
			: HashTable() {
			other.swap(*this);
		}

		// Swap constructor, overloading assingment operator 
		constexpr HashTable& operator=(HashTable&& other) noexcept {
			HashTable temp;
			other.swap(*this);
			temp.swap(other);
			return *this;
		}

		// Swap keys and values between two maps constructor	
		constexpr HashTable& operator=(const HashTable& other) {
			HashTable temp(other);
			temp.swap(*this);
			return *this;
		}

		// Initialise with key and value pair lists constructor
		constexpr HashTable& operator=(std::initializer_list<valueType> list) {
			HashTable temp{ list };
			temp.swap(*this);
			return *this;
		}

		// Modifiers
		constexpr bool insert(std::initializer_list<valueType> hashList) {}
		constexpr bool insert(valueType&& value) {}
		constexpr bool insert(const valueType& value) {}

		constexpr void clear() noexcept {
			mTable.clear();
			mSize = 0;
			mBucketCount = 0;
		}
		constexpr bool emplace() {}
		constexpr bool remove() {}
		//constexpr merge 


		// Lookup functions
		constexpr Type& at(const Key& key) const {
			uInt index{mHash(key) & mBucketCount};
			auto& currentList{mTable.at(index)};
			for (auto& element : currentList) {
				if (element.first == key) {
					return element.second;
					//return 34;
				}
			}
		}
		constexpr Type& at(const Key& key) {
			uInt index{ mHash(key) & mBucketCount };
			auto& currentList{ mTable.at(index) };
			for (auto& element : currentList) {
				if (element.first == key) {
					return element.second;
				}
			}
		}

		constexpr Type contains() {}
		constexpr Type find() {}
		constexpr Type count() {}
		constexpr bool empty() const { return (mSize == 0); }
		constexpr int  size()  const { return mSize; }
		//constexpr void printTable(const HashTable& hashTable) {
		//	for (auto content : hashTable.mTable) {
		//		std::cout << hashTable.at
		//	}
		//}

		constexpr const Type& operator[](const Key& key) const {
			uInt index{ mHash(key) & mBucketCount };
			auto& currentList{ mTable.at(index) };
			for (auto& element : currentList) {
				if (element.first == key) {
					return element.second;
					//return 34;
				}
			}
			return currentList.front().second;
		}
		//std::ostream& operator<<(std::ostream& os, const HashTable& hash){}
		
		
		// Comparison functions - the operator!= is implicitly an inverse of the operator== as of C++20
		constexpr bool operator==(const Key& key) {}
		//void eraseIf()
	};
}


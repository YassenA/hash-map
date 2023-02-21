#pragma once
#include <algorithm>
#include <list>
#include <vector>
#include <initializer_list>

namespace container {
	template<typename Key, typename Type, typename Hash = std::hash<Key>>
	
	class HashTable {
		private:
			using hashTable = std::vector<std::list<std::pair<const Key, Type>>>;
			
			int mSize{}; // Size of the elements that have been inserted
			Hash mHash; // Keeps track of the consutrcted hash 
			int mBucketCount{};

			std::vector<std::list<std::pair<const Key, Type>>> mTable; // Where the hash table is tored
		public:
			using mappedType = Type;
			using valueType = std::pair<const Key, mappedType>;

			// List initialisation consuctrion
			//constexpr int HashTable(std::initializer_list<valueType> hashList, const hasher& hash = Hash())
			//	: mSize {hashList.size()},
			//	  mHash {hash}
			//{}
		
			// Default constructor
			//constexpr HashTable(const Hash hash = Hash())
			//	: mSize{ 0 }
			//	, mSize{ hash }
			//	, mBucketCount{ 0 }

			//{}
		
			// Initialisation constructor
			constexpr HashTable(const HashTable& other)
				: mSize{ other.mSize }
				, mSize{ other.mSize }
				, mTable{ other.mTable }
			{}

			// Swap constructor, itialise object
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
		
			// Initialise with key and value pair constructor
			constexpr HashTable& operator=(std::initializer_list<valueType> list) {
				HashTable temp{ list };
				temp.swap(*this);
				return *this;
			}





			constexpr bool empty() const { return (mSize == 0); }
			constexpr int  size()  const { return mSize;        }


	};
}


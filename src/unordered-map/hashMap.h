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
		Hash mHash;   // Keeps track of the consutrcted hash 
		uInt mBucketCount{};
		
		inline static const double growthFactor = 2.0;
		inline static const double maxLoadFactor = 0.75;


		std::vector<std::list<std::pair<const Key, Type>>> mTable; // Where the hash table is tored
	public:
		using mappedType = Type;
		using valueType = std::pair<const Key, mappedType>;

		// List initialisation constructor
		constexpr HashTable(std::initializer_list<valueType> hashList, const Hash& hash = Hash())
			: mSize{ hashList.size() },
			  mHash{ hash },
			  mBucketCount{static_cast<uInt>(hashList.size() * growthFactor)},
			  mTable(static_cast<uInt>(hashList.size() * growthFactor))
		{
			for (auto elementPair : hashList) {
				insert(elementPair);
			}
		}

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
		constexpr HashTable(HashTable&& otherTable) noexcept
			: HashTable() {
			otherTable.swap(*this);
		}

		// Swap constructor, overloading assingment operator 
		constexpr HashTable& operator=(HashTable&& otherTable) noexcept {
			HashTable temp;
			otherTable.swap(*this);
			temp.swap(otherTable);
			return *this;
		}

		// Swap keys and values between two maps constructor	
		constexpr HashTable& operator=(const HashTable& otherTable) {
			HashTable temp(otherTable);
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
		constexpr void insert(std::initializer_list<valueType> hashList) {
			for (auto elementPair : hashList) {
				insert(elementPair);
			}
		}
		//template<typename T>
		constexpr bool insert(valueType&& value) {
			uInt index{ mHash(value.first) % mBucketCount };
			auto& currentBucket{ mTable.at(index) };
			currentBucket.push_front(value);
			mSize++;

			if (calculateLoadBalance() > maxLoadFactor) { reHash(); }
			return true;
		}
		constexpr bool insert(const valueType& value) {
			uInt index{ mHash(value.first) % mBucketCount };
			auto& currentBucket{ mTable.at(index) };
			currentBucket.push_front(value);
			mSize++;

			if (calculateLoadBalance() > maxLoadFactor) { reHash(); }
			return true;
		}


		constexpr void clear() noexcept {
			mTable.clear();
			mSize = 0;
			mBucketCount = 0;
		}
		constexpr bool emplace() {}
		constexpr bool remove() {}
		//constexpr merge 



		// Lookup functions
		constexpr const Type& at(const Key& key) const {
			uInt index{mHash(key) % mBucketCount};
			auto& currentList{mTable.at(index)};
			for (auto& element : currentList) {
				if (element.first == key) {
					return element.second;
				}
			}
		}
		constexpr Type& at(const Key& key) {
			uInt index{ mHash(key) % mBucketCount };
			auto& currentList{ mTable.at(index) };
			for (auto& element : currentList) {
				if (element.first == key) {
					return element.second;
				}
			}
		}

		constexpr Type contains() {}
		constexpr Type find() {}
		constexpr Type& count() {}
		constexpr bool empty() const { return (mSize == 0); }
		constexpr int  size()  const { return mSize; }
		//constexpr void printTable(const HashTable& hashTable) {
		//	for (auto content : hashTable.mTable) {
		//		std::cout << hashTable.at
		//	}
		//}

		//constexpr Type& operator[](const Key& key){
		//	uInt index{ mHash(key) % mBucketCount };
		//	auto& currentList{ mTable.at(index) };
		//	for (auto& element : currentList) {
		//		if (element.first == key) {
		//			return element.second;
		//			//return 34;
		//		}
		//	}
		//	return currentList.front().second;
		//}
		constexpr const Type& operator[](const Key& key) const {
			uInt index{ mHash(key) % mBucketCount };
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
		//constexpr void eraseIf()

		constexpr void reHash() {
			hashTable tempHash{ mTable };
			mTable.clear();
			mSize = 0;
			mBucketCount = static_cast<uInt>(mBucketCount * growthFactor);
			mTable.resize(mBucketCount);
			for (const auto& currentBucket : tempHash) {
				for (const auto& currentPair : currentBucket) {
					insert(currentPair);
				}
			}
		}
		constexpr void reHash(uInt bucketAmount) {
			hashTable tempHash{ mTable };
			mTable.clear();
			mSize = 0;
			mBucketCount = bucketAmount;
			mTable.resize(mBucketCount);
			for (const auto& currentBucket : tempHash) {
				for (const auto& currentPair : currentBucket) {
					insert(currentPair);
				}
			}
		}

		constexpr double calculateLoadBalance() const noexcept { return static_cast<double>(mSize / mBucketCount); }
		//constexpr double maxLoadFactor() const noexcept { return maxLoadFactor; }
		//constexpr double maxLoadFactor(double newLoadFactorVal) { return maxLoadFactor = newLoadFactorVal; }
		constexpr void reserve(uInt reservationAmount) {
			mBucketCount = reservationAmount;
			reHash(reservationAmount);
		}

		// Bucket
		constexpr uInt bucket(const Key& key) const {
			const uInt index{ mHash(key) % mBucketCount };
			return index;
		}
		constexpr uInt bucketSize(uInt index) const noexcept {
			return mTable.at(index).size();
		}
		constexpr uInt maxBucketCount() const noexcept {
			return mTable.max_size();
		}
	};
}


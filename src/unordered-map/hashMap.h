#pragma once
#include <algorithm>
#include <list>
#include <vector>
#include <initializer_list>

#include <ranges>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
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
		inline static const double mMaxLoadFactor = 0.75;

		hashTable mTable; // Where the hash table is stored
	public:
		using mappedType = Type;
		using valueType = std::pair<const Key, mappedType>;
		friend std::ostream& operator<<(std::ostream& os, const HashTable& hashTableOS);

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
			: mBucketCount{ otherTable.mBucketCount }
			, mSize{ otherTable.mSize }
			, mTable{ otherTable.mTable }
			, mHash{ otherTable.mHash }
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
		constexpr bool insert(valueType&& value) {
			uInt index{ mHash(value.first) % mBucketCount };
			auto& currentBucket{ mTable.at(index) };
			currentBucket.push_front(value);
			mSize++;

			if (calculateLoadBalance() > mMaxLoadFactor) { reHash(); }
			return true;
		}
		constexpr bool insert(const valueType& value) {
			uInt index{ mHash(value.first) % mBucketCount };
			auto& currentBucket{ mTable.at(index) };
			currentBucket.push_front(value);
			mSize++;

			if (calculateLoadBalance() > mMaxLoadFactor) { reHash(); }
			return true;
		}
		//constexpr void insert(HashTable tableToInsert) {
		//	for (auto const& elementPair : tableToInsert) {
		//		//insert(elementPair);
		//		for (auto const& element : elementPair) {
		//			insert(element);
		//		}
		//	}

		//	std::cout << (this->size() + tableToInsert.size()) << std::endl;
		//	std::cout <<"calculateLoadBalance: " << (this->calculateLoadBalance()) << " and size: " << this->size() << 
		//		" Bucket: " << this->maxBucketCount() << 
		//		std::endl;
		//}


		constexpr void clear() noexcept {
			mTable.clear();
			mSize = 0;
			mBucketCount = 0;
		}
		constexpr bool emplace() {}
		constexpr bool removeByKey(const Key& key) {
			uInt index{ mHash(key) % mBucketCount };
			auto& currentList{ mTable.at(index) };
			for (const auto& elementPair : currentList) {
				if (elementPair.first == key) {
					currentList.remove(elementPair);
					mSize--;
					return true;
				}
			}
			return false;
		}
		constexpr bool removeByValue(const Type& value) {
			uInt index{ 0 };
			for (auto& element : mTable) {
				for (const auto& elementPair : element) {
					if (elementPair.second == value) {
						mTable.at(index).remove(elementPair);
						mSize--;
						return true;
					}
				}
				index++;
			}
			return false;
		}
		//constexpr merge 



		// Lookup functions
		constexpr const Type& at(const Key& key) const {
			uInt index{mHash(key) % mBucketCount};
			auto& currentList{mTable.at(index)};
			for (const auto& element : currentList) {
				if (element.first == key) {
					return element.second;
				}
			}
			throw std::out_of_range("Given key is not associated with any element");
		}

		constexpr void printTable() const {
			for (auto const& elementPair : mTable) {
				for (auto const& element : elementPair) {
					std::cout << "Key: " << element.first << " Value: " << element.second << "\n";
				}
			}
		}
		constexpr bool containsKey(const Key& key) const {
			for (auto const& elementPair : mTable) {
				for (auto const& element : elementPair) {
					if (element.first == key) {
						return true;
					}
				}
			}
			return false;
		}
		constexpr bool containsValue(const Type& value) const {
			for (auto const& elementPair : mTable) {
				for (auto const& element : elementPair) {
					if (element.second == value) {
						return true;
					}
				}
			}
			return false;
		}
		template <typename T>
		constexpr bool find(const T& input) {
			
		}
		constexpr uInt count() {}
		constexpr bool empty() const { return (mSize == 0); }
		constexpr uInt  size()  const { return mSize; }

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
		
		//for (auto& [a, b] : zip(containerA, containerB)) {
		//	a = b;
		//}
		
		// Comparison functions - the operator!= is implicitly an inverse of the operator== as of C++20
		constexpr bool operator==(const HashTable& otherTable) {
			if (this->size() != otherTable.size()) { return false; }

			//for (auto const& elementPair : this->mTable) {
			//	for (auto const& element : elementPair) {
			//		if (element.)
			//	}
			//}
			//for (auto const& elementPair : this->mTable) {
			//	for (auto const& element : elementPair) {
			//		if (element.)
			//	}
			//}
			for (const auto& thisTableElement : this->mTable) {
				//for (auto const& [thisElement, otherElement] : [thisTableElement, otherTableElement] ) {
				//	std::cout << thisElement.first << std::endl;
				//}
				std::cout << "Something" << std::endl;
			}

			//return false;

			return true;
		}
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
		constexpr double maxLoadFactor() const noexcept        { return mMaxLoadFactor; }
		constexpr double maxLoadFactor(double newLoadFactorVal){ return mMaxLoadFactor = newLoadFactorVal; }
		constexpr void reserve(uInt reservationAmount) {
			mBucketCount = reservationAmount;
			reHash(reservationAmount);
		}

		// Bucket interface
		constexpr uInt bucket(const Key& key) const {
			const uInt index{ mHash(key) % mBucketCount };
			return index;
		}
		constexpr uInt bucketSize(uInt index) const noexcept { return mTable.at(index).size(); }
		constexpr uInt maxBucketCount() const noexcept		 { return mTable.max_size(); }
		constexpr const hashTable getTable() const noexcept  { return mTable; }
	};

	std::ostream& operator<<(std::ostream& os, const hashTableOS & hashTableOS) {
		return os;
	}
}


#pragma once
#include <algorithm>
#include <vector>

namespace container {
	template<typename Key, typename Type, typename Hash = std::hash<Key>>
	
	class HashTable {
		private:
			using hashTable = std::vector<std::list<std::pair<const Key, Type>>>;
		
			std::size_t m_size{};		
			Hash m_hash								  

			std::vector<std::list<std::pair<const Key, Type>>> m_table; 
		public:
			using mappedType = Type;
			using valueType = std::pair<const Key, mappedType>;

		
			// Default constructor
			constexpr HashTable(const hasher& hash = Hash())
				: m_size{ 0 }
				, m_hash{ hash }
				, m_bucket_count{ 0 }

			{}
		
			// Initialisation constructor
			constexpr HashTable(const HashTable& other)
				, m_hash{ other.m_hash }
				, m_size{ other.m_size }
				, m_table{ other.m_table }
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


	};
}


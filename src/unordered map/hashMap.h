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

			constexpr HashTable(const HashTable& other)
				, m_hash{ other.m_hash }
				, m_size{ other.m_size }
				, m_table{ other.m_table }
			{
			}

			constexpr HashTable(HashTable&& other) noexcept
				: HashTable() {
				other.swap(*this);
			}

			constexpr HashTable& operator=(HashTable&& other) noexcept {
				HashTable temp;
				other.swap(*this);
				temp.swap(other);
				return *this;
			}

			constexpr HashTable& operator=(const HashTable& other) {
				HashTable temp(other);
				temp.swap(*this);
				return *this;
			}

			constexpr HashTable& operator=(std::initializer_list<value_type> list) {
				HashTable temp{ list };
				temp.swap(*this);
				return *this;
			}


	};
}


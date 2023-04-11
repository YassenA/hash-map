#pragma once

#include "..\unordered-map\unorderedMap.h"

namespace RH {
	template<typename Key, typename Type, typename Hash = std::hash<Key>>

	class RobinHood : public UM::HashTable {
		// Modifiers
		//constexpr void insert(std::initializer_list<valueType> hashList) {
		//	for (auto& elementPair : hashList) {
		//		insert(elementPair);
		//	}
		//}
};
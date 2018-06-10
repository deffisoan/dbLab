#include "consistent_hash.h"
#include "hash.h"
#include <sstream>
#include <cstring>
using namespace std;

ConsistentHash::ConsistentHash(int node_num, int virtual_node_num) {
	node_num_ = node_num;
	virtual_node_ = virtual_node;
	for (int i = 0; i < node_num; i++) {
		for (int j = 0; j < virtual_node_num) {
			stringstream hash_key;
			hash_key << "EntityNode-" << i << "VirtualNode-" << j;
			uint32_t partion = murmur3_32(hash_key.str().c_str(), hash_key.str().size());
			nodes_.insert(pair<uint32_t, size_t>(partion, i));
		}
	}
}

ConsistentHash::~ConsistentHash()
{
	nodes_.clear();
}

size_t ConsistentHash::GetServerIndex(string key)
{
	uint32_t partion = murmur3_32(key, key.size());
	auto iter = nodes_.lower_bound(partion);
	if (iter == nodes_.end()) {
		return nodes_.begin()->second;
	} 
	return iter->second;
}

void ConsistentHash::AddNode(const int index)
{
}

void ConsistentHash::DeleteNode(const int index)
{
}

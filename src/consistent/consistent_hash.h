#ifndef __CONSISTENT_HASH_H__
#define __CONSISTENT_HASH_H__
#include <string>
#include <map>

using namespace std;
class ConsistentHash
{
public:
	ConsistentHash(int node_num, int virtual_node_num);
	~ConsistentHash();

	size_t GetServerIndex(string key);
	void AddNode(const int index);
	void DeleteNode(const int index);

private:
	map<uint32_t, int> nodes_;
	int node_num_;
	int virtual_node_num_;
};
#endif // !__CONSISTENT_HASH_H__

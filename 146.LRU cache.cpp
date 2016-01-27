/******************************************
problem:
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

author: guohongzhi

language: C++

******************************************/
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

typedef struct CacheNode
{
	int key;
	int val;
	CacheNode(int key, int val) :key(key), val(val){}
}CacheNode;

class LRUCache{
public:
	LRUCache(int capacity)
	{
		maxSize = capacity;
		usedSize = 0;
		caches.clear();
		hashMap.clear();
	}

	int get(int key)
	{
		if (hashMap.find(key) == hashMap.end())return -1;
		caches.splice(caches.begin(), caches, hashMap[key]);
		hashMap[key] = caches.begin();
		return hashMap[key]->val;
	}

	void set(int key, int value)
	{
		if (hashMap.find(key) != hashMap.end())
		{
			caches.splice(caches.begin(), caches, hashMap[key]);
			hashMap[key] = caches.begin();
			hashMap[key]->val = value;
		}
		else
		{
			if (usedSize >= maxSize)
			{
				int endKey = caches.back().key;
				hashMap.erase(endKey);
				caches.pop_back();
				--usedSize;
			}
			++usedSize;
			caches.push_front(CacheNode(key, value));
			hashMap[key] = caches.begin();
		}
	}
private:
	int maxSize;
	int usedSize;
	list<CacheNode> caches;
	unordered_map<int, list<CacheNode>::iterator> hashMap;
};





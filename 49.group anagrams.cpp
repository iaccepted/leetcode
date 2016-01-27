/******************************************
problem:
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

author: guohongzhi

language: C++
******************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> groups;
		vector<vector<string>> res;

		int size = strs.size();

		string word;
		for (int i = 0; i < size; ++i)
		{
			word = strs[i];
			sort(word.begin(), word.end());
			groups[word].push_back(strs[i]);
		}

		for (auto ite = groups.begin(); ite != groups.end(); ++ite)
		{
			if (ite->second.size() >= 1)
			{
				sort(ite->second.begin(), ite->second.end());
				res.push_back(ite->second);
			}
		}

		return res;
	}
};

int main()
{
	string arr[] = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<string> strs(arr, arr + 6);

	Solution so;
	vector<vector<string>> res = so.groupAnagrams(strs);

	for (auto ite = res.begin(); ite != res.end(); ++ite)
	{
		for (auto i = ite->begin(); i != ite->end(); ++i)
		{
			cout << (*i) << " ";
		}
		cout << endl;
	}

	return 0; 
}

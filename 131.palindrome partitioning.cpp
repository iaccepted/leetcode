/******************************************
problem:
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = “aab”,
Return

[
    ["aa","b"],
    ["a","a","b"]
  ]
******************************************/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) 
	{
		vector<vector<string>> res;
		vector<string> path;
		partition(s, 0, s.size() - 1, path, res);
		return res;
	}

private:
	void partition(string &s, int start, int end, vector<string> &path, vector<vector<string>> &res)
	{
		if (start > end)return;

		if (isPalindrom(s, start, end) && end == s.size() - 1)
		{
			path.push_back(s.substr(start, end - start + 1));
			res.push_back(path);
			path.pop_back();
		}

		for (int i = start; i <= end; ++i)
		{
			if (isPalindrom(s, start, i))
			{
				path.push_back(s.substr(start, i - start + 1));
				partition(s, i + 1, end, path, res);
				path.pop_back();
			}
		}
	}

	bool isPalindrom(string &s, int start, int end)
	{
		bool ret = true;

		while (start <= end)
		{
			if (s[start] != s[end])
			{
				ret = false;
				break;
			}
			++start;
			--end;
		}
		return ret;
	}
};

int main()
{
	
	Solution so;
	vector<vector<string>> res = so.partition("aaabb");

	for each(auto vec in res)
	{
		for each(auto s in vec)
		{
			cout << s << "\t";
		}
		cout << endl;
	}
	return 0;
}
/*************************************************************************************
17. Letter Combinations of a Phone Number My Submissions Question
Total Accepted: 67566 Total Submissions: 245686 Difficulty: Medium
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
****************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) 
	{
		string phone[] = {
			"",
			"",
			"abc",
			"def",
			"ghi",
			"jkl",
			"mno",
			"pqrs",
			"tuv",
			"wxyz"
		};

		vector<string> res;
		if (digits.empty() || digits.find('0') != string::npos 
			|| digits.find('1') != string::npos)return res;

		string path = "";
		combine(digits, 0, phone, path, res);
		return res;
	}

private:
	void combine(string digits, int start, string *phone, string path, vector<string> &res)
	{
		if (path.length() == digits.length())
		{
			res.push_back(path);
			return;
		}

		string s = phone[digits[start] - '0'];
		int n = s.length();

		for (int i = 0; i < n; ++i)
		{
			path.push_back(s[i]);
			combine(digits, start + 1, phone, path, res);
			path.pop_back();
		}
	}
};

int main()
{

	Solution so;
	vector<string> res = so.letterCombinations("");

	for each (auto vec in res)
	{
		for each (auto ele in vec)
		{
			cout << ele;
		}
		cout << endl;
	}
	return 0;
}
/****************************************************************************
326. Power of Three My Submissions Question
Total Accepted: 15362 Total Submissions: 43489 Difficulty: Easy
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	bool isPowerOfThree(int n) 
	{
		if (n <= 0)return false;
		double base = log2(n * 1.0) / log2(3.0);
		if (fabs(base - int(base + 0.5)) <= 1e-10)return true;
		return false;
	}
};

int main()
{
	vector<int> vec = { 531442, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467 };
	Solution so;

	for (int i = 0; i < vec.size(); ++i)
	{
		cout << so.isPowerOfThree(vec[i]) << endl;
	}
	return 0;
}
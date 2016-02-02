/*************************************************************************************
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int version)
{
	if (version >= 1702766719)return true;
	return false;
}

class Solution {
public:
	int firstBadVersion(int n) 
	{
		int left = 1, right = n;
		while (left < right)
		{
			int mid = (left >> 1) + (right >> 1);
			if (!isBadVersion(mid))left = mid + 1;
			else right = mid;
		}
		return left;
	}
};

int main()
{
	Solution so;
	cout << so.firstBadVersion(2126753390) << endl;
	return 0;
}
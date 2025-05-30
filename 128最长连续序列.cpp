#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int> &nums)
	{

		unordered_set<int> uset;
		for (const int &num : nums)
		{
			uset.insert(num);
		}

		int maxLen = 0;

		for (const int &num : uset)
		{
			if (!uset.count(num - 1)) // 跳过已经遍历过的连续串
			{
				int currentNum = num;
				int currentLen = 1;

				while (uset.count(currentNum + 1))
				{
					currentNum += 1;
					currentLen += 1;
				}

				maxLen = max(maxLen, currentLen);
			}
		}

		return maxLen;
	}
};

int main()
{
	Solution sol;
	vector<int> nums = {100, 4, 200, 1, 3, 2};
	vector<int> nums1 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
	int result = sol.longestConsecutive(nums1);
	cout << "result = " << result << endl;

	return 0;
}

/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9

示例 3：
输入：nums = [1,0,1,2]
输出：3

*/
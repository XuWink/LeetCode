#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        if (nums.empty()) return answer;

        int size = nums.size();

        vector<int> left(size, 0);
        vector<int> right(size, 0);

        left[0] = 1;
        for (int i = 1; i < size; ++i) {
            left[i] = left[i - 1] * nums[i-1];
        }

        right[size - 1] = 1;
        for (int i = size - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < size; ++i) {
            answer.push_back(left[i] * right[i]);
        }
        return answer;

    }
};

/*
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

示例 1:
输入: nums = [1,2,3,4]
输出: [24,12,8,6]

示例 2:
输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]
 

*/
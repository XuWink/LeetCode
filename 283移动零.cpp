#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int currentIndex = 0;
		int fastIndex = 0;
		int len = nums.size();
		
		for(int i=0; i<len; ++i){
			
			if(nums[fastIndex] != 0){
				nums[currentIndex] = nums[fastIndex];
				fastIndex++;
				currentIndex++;
			}else{
				fastIndex++;
			}
		}
		for(int i=currentIndex; i<len; ++i){
			nums[i] = 0;
		}
		
    }
};

int main(){
	
	Solution sol;
	vector<int> nums = {0,1,0,3,12};
	sol.moveZeroes(nums);
	for(const int& num : nums){
		std::cout<<num<<std::endl;
		
	}
}

/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0]
 
*/
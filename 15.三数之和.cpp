#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	
	// 暴力解法 时间复杂度O(n^3)
	vector<vector<int>> threeSum1(vector<int>& nums) {
        set<vector<int>> result_set;
		for(int i = 0; i < nums.size()-2; ++i){
			for(int j = i+1; j < nums.size()-1; ++j){
				for(int k = j+1; k < nums.size(); ++k){
					if(nums[i] + nums[j] + nums[k] == 0){
						vector<int> temp = {nums[i] , nums[j] , nums[k]};
						sort(temp.begin(), temp.end());
						result_set.insert(temp);
					}
				}
			}
		}
		
		vector<vector<int>> result;
		for(const auto& item : result_set){
			result.push_back(item);
		}
		return result;
    }

	/*
	排序：首先对数组进行排序，以便使用双指针技术。
	遍历数组：固定一个数 nums[i]，然后在 i+1 到 nums.size()-1 	的范围内使用双指针寻找另外两个数。
	双指针：
		初始化两个指针 left 和 right，分别指向当前固定数的下一个位置和数组的末尾。
		计算三个数的和 sum。
		如果 sum 等于 0，则找到一个三元组，并将其加入结果集。同时跳过重复的元素。
		如果 sum 小于 0，移动左指针以增加和。
		如果 sum 大于 0，移动右指针以减少和。
		跳过重复元素：在固定数和找到三元组时，跳过重复的元素以避免重复的三元组。
	*/
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		
		if(nums[0] > 0) return result;
		
		for(int i = 0; i < nums.size(); ++i){
			
			if(i > 0 && nums[i] == nums[i-1]) continue;
			
			int left = i+1;
			int right = nums.size()-1;
			
			while(left < right){
				int sum = nums[i] + nums[left] + nums[right];
				if(sum == 0){
					result.push_back({nums[i], nums[left], nums[right]});
					while(left < right && nums[left] == nums[left+1]){
						++left;
					}
					while(left < right && nums[right] == nums[right-1]){
						--right;
					}
					++left;
					--right;
				}else if(sum < 0){
					++left;
				}else{
					--right;
				}
			}
			
			if(left >= right) break;
			
		}
		
		return result;
    }
};

int main(){
	
	Solution sol;
	vector<int> nums = {-1,0,1,2,-1,-4};
	vector<vector<int>> result = sol.threeSum(nums);
	
	for(auto item : result){
		for(int it : item){
			std::cout << it << " ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}

/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。

*/
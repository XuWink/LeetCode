#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
		
		for(int i = 0; i < nums.size(); ++i){
			int temp = target - nums[i];
			if(umap.find(temp) != umap.end()){
				return {i, umap[i]};
			}
			umap.insert({nums[i], i});
			// umap[nums[i]] = i;
		}
		return {};
    }
};

int main(){
	
	Solution sol;
	vector<int> sums = {2,7,11,15};
	int target = 9;
	vector<int> result = sol.twoSum(sums, target);
	
	for(int item : result){
		std::cout<<item<<" ";
	}
	
	return 0;
}

/*
示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
		vector<int> leftMax(n), rightMax(n);
		int water = 0;

		int left = 0, right = height.size() - 1;
		
		leftMax[0] = height[0];
		for(int i = 1; i < height.size(); ++i){
			leftMax[i] = max(leftMax[i - 1], height[i]);			
		}
		
		rightMax[n - 1] = height[n - 1];
		for(int i = n - 2; i >= 0; --i){
			rightMax[i] = max(rightMax[i + 1], height[i]);			
		}
		
		for(int i = 0; i < n; ++i){
			water += min(leftMax[i], rightMax[i]) - height[i];			
		}
		
		return water;
    }
};

int main(){
	Solution sol;
	vector<int> height = {4,2,0,3,2,5};
	int result = sol.trap(height);
	std::cout << "result = " << result << std::endl;
	return 0;
}

/*
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9

*/
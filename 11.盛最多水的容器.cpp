#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 暴力解法
	int maxArea1(vector<int>& height) {
        int max_water = 0;
		for(int i=0; i<height.size()-1; ++i){
			for(int j=1; j<height.size(); ++j){
				
				int temp = (j-i)*min(height[j], height[i]);
				max_water = max(max_water, temp);
			}			
		}
		return max_water;
    }

	/*
	使用两个指针，分别指向数组的左右两端。
	计算当前容器的容量，并更新最大值。
	移动较短的线对应的指针（因为容量由较短的线决定，移动较长的线不会使容量变大）。
	时间复杂度为 O(n)。
	*/
    int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size()-1;
		int max_water = 0;
		
		while(left < right){
			int temp = (right - left) * min(height[left], height[right]);
			max_water = max(max_water, temp);
			
			if(height[left] <= height[right]){
				left += 1;
			}else{
				right -= 1;
			}
		}
		
        return max_water;
    }
};

int main(){
	
	Solution sol;
	vector<int> height = {1,8,6,2,5,4,8,3,7};
	int result = sol.maxArea(height);
	
	std::cout<<"result = " <<result<<std::endl;	
	return 0;
}

/*
https://leetcode.cn/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-100-liked
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
说明：你不能倾斜容器。

输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
*/
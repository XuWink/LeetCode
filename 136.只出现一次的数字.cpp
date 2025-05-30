#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /* 异或，0^A=A, A^A=0, B^A^B=A */
    int singleNumber(vector<int>& nums) {
       int sing = 0;
       for(int item : nums){
            sing ^= item;
            std::cout << "item = " << item << ", sing = " << sing << std::endl;
       }
       return sing;
    }

    // 第二种方式
    int singleNumber1(vector<int>& nums){
        unordered_map<int, int> umap;
        for(int num : nums){
            umap[num]++;
        }
        for(auto item : umap){
            if(item.second == 1){
                return item.first;
            }
        }
        return -1;
    }

};

int main(){
    vector<int> nums = {2,2,1};
    
    Solution sol;
    int result = sol.singleNumber1(nums);
    std::cout << "result = " << result << std::endl;
    return 0;
}


/*
给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了
一次的元素。你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

示例 1 ：
输入：nums = [2,2,1]
输出：1

示例 2 ：
输入：nums = [4,1,2,1,2]
输出：4

示例 3 ：
输入：nums = [1]
输出：1
*/
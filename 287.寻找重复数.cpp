#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     std::unordered_map<int, int> umap;
    //     for (const int& num : nums) {
    //         if (umap.find(num) != umap.end()) {
    //             umap[num] += 1;
    //         } else {
    //             umap.insert({num, 1})
    //         }
    //     }
    //     int result = -1;
    //     for (auto item : umap) {
    //         if (item.second == 2) {
    //             result = item.first;
    //             break;
    //         }
    //     }
    //     return  result;
    // }

    int findDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for(int num : nums){
            if(uset.find(num) != uset.end()){
                return num;
            }else{
                uset.insert(num);
            }
        }

        return -1;
    }
};

int main(){

    return 0;
}

/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个
重复的整数。假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

示例 1：
输入：nums = [1,3,4,2,2]
输出：2

示例 2：
输入：nums = [3,1,3,4,2]
输出：3

示例 3 :
输入：nums = [3,3,3,3,3]
输出：3
*/
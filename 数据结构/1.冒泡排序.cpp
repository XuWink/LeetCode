#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void bubbleSort(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            // 如果没有交换发生，说明数组已经有序
            if (!swapped) break;
        }
    }

};

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    sol.bubbleSort(nums);
    for (int i=0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i) {
            // 初始化当前行（i+1个元素）
            result.push_back(vector<int>(i + 1, 1));  // 所有元素初始化为1
            
            // 计算中间元素（跳过首尾的1）
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        return result;
    }
};

int main() 
{
    int numRows = 10;
    Solution sol;
    vector<vector<int>> result = sol.generate(numRows);

    for (int i=0; i<numRows; ++i) {
        for (int j=0; j<i; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
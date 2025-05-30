#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> que;
        que.push(root);

        bool flag = false; // false正向，true反向
        while(!que.empty()) {
            int size = que.size();
            vector<int> temp(size); // 预分配空间

            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();

                int index = flag ? (size - 1 - i) : i;
                temp[index] = node->val;

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right); 
            }
            flag = !flag;
            result.emplace_back(temp);
        }
        return result;
    }
};

/*
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[20,9],[15,7]]

输入：root = [1]
输出：[[1]]

输入：root = []
输出：[]

*/

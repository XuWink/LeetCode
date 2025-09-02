#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int        val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    bool isSymmetric(TreeNode * root) {
        if (root == nullptr) {
            return true;
        }

        std::queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty()) {
            TreeNode * left_node = que.front();
            que.pop();
            TreeNode * right_node = que.front();
            que.pop();

            if (left_node == nullptr && right_node == nullptr) {
                continue;
            }

            if (left_node == nullptr || right_node == nullptr || left_node->val != right_node->val) {
                return false;
            }

            que.push(left_node->left);
            que.push(right_node->right);
            que.push(left_node->right);
            que.push(right_node->left);
        }

        return true;
    }
};

/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。

输入：root = [1,2,2,3,4,4,3]
输出：true

输入：root = [1,2,2,null,3,null,3]
输出：false
*/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
}

class Solution {
public:

    // 递归
    void helper1(TreeNode *root, vector<int> &result) {

        if (root == nullptr) return;

        helper1(root->left, result);
        result.push_back(root->val);
        helper1(root->right, result);
    }

    // 迭代
    vector<int> helper2(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<int> st;
        TreeNode *node = root;
        while(node != nullptr || !st.empty()) {
            // 一直走到最左子结点
            while(node != nullptr) {
                st.push(node);
                node = node->left;
            }

            TreeNode *temp = st.top();
            st.pop();
            result.push_back(temp->val);
            if (temp->right) {
                st.push(temp->right);
            }

        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        return helper1(root);

        // return helper2(root);
    }
};

// 根据层次遍历向量构建二叉树
TreeNode* buildSampleTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] < -100) return nullptr; // 假设小于 -100 表示空节点
 
    queue<TreeNode*> q;
    TreeNode *root = new TreeNode(nodes[0]);
    q.push(root);
 
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode *curr = q.front();
        q.pop();
 
        // 处理左子节点
        if (i < nodes.size() && nodes[i] >= -100) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
 
        // 处理右子节点
        if (i < nodes.size() && nodes[i] >= -100) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
 
    return root;
}

void printTreeNode(TreeNode *root) {

}

// 析构二叉树函数
void destroyTree(TreeNode *root) {
    if (root == nullptr) return;
 
    // 递归删除左子树
    destroyTree(root->left);
    // 递归删除右子树
    destroyTree(root->right);
    // 删除当前节点
    delete root;
}

int main() 
{
    vector<int> nums = {1,-111,2,3};
    Solution sol;

    TreeNode *root = buildSampleTree(nums);
    sol.inorderTraversal(root);

    destroyTree(root);
    
    return 0;
}

/*
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

输入：root = [1,null,2,3]
输出：[1,3,2]

输入：root = []
输出：[]

输入：root = [1]
输出：[1]
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 析构二叉树函数
void destroyTree(TreeNode *root) {
    if (root == nullptr) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

// 根据层次遍历向量构建二叉树
TreeNode* buildSampleTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr; // 假设 -1 表示空节点

    queue<TreeNode*> q;
    TreeNode *root = new TreeNode(nodes[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode *curr = q.front();
        q.pop();

        // 处理左子节点
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        // 处理右子节点
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// 迭代法先序遍历
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == nullptr) return result;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode *node = s.top();
        s.pop();
        result.push_back(node->val);

        // 先压入右子节点，再压入左子节点
        if (node->right != nullptr) s.push(node->right);
        if (node->left != nullptr) s.push(node->left);
    }

    return result;
}

// 迭代法中序遍历
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode *curr = root;

    while (curr != nullptr || !s.empty()) {
        // 遍历到最左子节点
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        // 访问节点
        curr = s.top();
        s.pop();
        result.push_back(curr->val);

        // 转向右子树
        curr = curr->right;
    }

    return result;
}

// 迭代法后序遍历
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == nullptr) return result;

    stack<TreeNode*> s;
    s.push(root);
    stack<int> output; // 用于反转输出顺序

    while (!s.empty()) {
        TreeNode *node = s.top();
        s.pop();
        output.push(node->val);

        // 先压入左子节点，再压入右子节点
        if (node->left != nullptr) s.push(node->left);
        if (node->right != nullptr) s.push(node->right);
    }

    // 反转输出顺序
    while (!output.empty()) {
        result.push_back(output.top());
        output.pop();
    }

    return result;
}

int main() {
    // 示例向量，假设 -1 表示空节点
    vector<int> nodes = {1, 2, 3, 4, 5, -1, -1};

    // 构建二叉树
    TreeNode *root = buildSampleTree(nodes);

    // 迭代法先序遍历
    vector<int> preorder = preorderTraversal(root);
    cout << "Preorder Traversal: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    // 迭代法中序遍历
    vector<int> inorder = inorderTraversal(root);
    cout << "Inorder Traversal: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    // 迭代法后序遍历
    vector<int> postorder = postorderTraversal(root);
    cout << "Postorder Traversal: ";
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    // 析构二叉树
    destroyTree(root);

    return 0;
}
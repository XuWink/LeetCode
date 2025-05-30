#include <iostream>
#include <vector>
#include <queue>

struct NTree {
    int val;
    std::vector<NTree*> children;
    NTree(int _val) : val(_val) {}
};

class Solution {
public:
    std::vector<std::vector<int>> test_N_tree(NTree* head) {
        std::vector<std::vector<int>> result;
        if (head == nullptr) return result;

        std::queue<NTree*> que;
        que.push(head);

        while (!que.empty()) {
            int size = que.size();
            std::vector<int> temp;  // 动态调整大小，无需初始化固定大小

            for (int i = 0; i < size; ++i) {
                NTree* node = que.front();
                que.pop();
                temp.push_back(node->val);  // 使用 push_back 添加节点值

                for (NTree* child : node->children) {
                    if (child != nullptr) {
                        que.push(child);
                    }
                }
            }

            result.push_back(temp);
        }

        return result;
    }
};

int main()
{
	// 构建多叉树
    NTree* root = new NTree(1);
    NTree* child1 = new NTree(3);
    NTree* child2 = new NTree(2);
    NTree* child3 = new NTree(4);
    root->children = {child1, child2, child3};
 
    NTree* grandchild1 = new NTree(5);
    NTree* grandchild2 = new NTree(6);
    child1->children = {grandchild1, grandchild2};
 
    // 调用层序遍历
    Solution sol;
    auto result = sol.test_N_tree(root);
 
    // 打印结果
    for (const auto& level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
 
    // 释放内存（实际项目中建议使用智能指针）
    delete grandchild1;
    delete grandchild2;
    delete child1;
    delete child2;
    delete child3;
    delete root;
 
    return 0;

}

/*
1 
3 2 4 
5 6
*/
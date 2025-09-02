#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int        val;
    ListNode * next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

class Solution {
  public:
    struct comp {
        bool operator()(ListNode * p1, ListNode * p2) { return p1->val > p2->val; }
    };

    ListNode * mergeKLists(vector<ListNode *> & lists) {
        if (lists.empty()) {
            return nullptr;
        }

        priority_queue<ListNode *, vector<ListNode *>, comp> pque;

        for (const auto & node : lists) {
            if (node != nullptr) {
                pque.push(node);
            }
        }

        ListNode * dummy = new ListNode(0, nullptr);
        ListNode * p     = dummy;
        while (!pque.empty()) {
            ListNode * temp = pque.top();
            pque.pop();

            p->next = temp;

            if (temp->next) {
                pque.push(temp->next);
            }

            temp->next = nullptr;
            p          = temp;
        }

        p = dummy->next;
        delete dummy;
        return p;
    }
};

ListNode * createListNode(const vector<int> & nums) {
    if (nums.empty()) {
        return nullptr;
    }
    ListNode * list = new ListNode(-1);
    ListNode * p1   = list;
    for (const int num : nums) {
        ListNode * node = new ListNode(num, nullptr);
        p1->next        = node;
        p1              = node;
    }
    ListNode * result = list->next;
    delete list;
    return result;
}

void printListNode(ListNode * list) {
    ListNode * node = list;
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
}

int main() {
    vector<ListNode *>  lists;
    vector<vector<int>> nums = {
        { 1, 4, 5 },
        { 1, 3, 4 },
        { 2, 6 }
    };
    for (const vector<int> & num : nums) {
        lists.push_back(createListNode(num));
    }

    Solution   sol;
    ListNode * result = sol.mergeKLists(lists);
    printListNode(result);

    return 0;
}

/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

输入：lists = []
输出：[]

输入：lists = [[]]
输出：[]

*/

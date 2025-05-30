#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        // 必须等于n，后续second才能走到要删除结点的前驱结点
        for (int i=0; i<=n; ++i) {
            if(first == nullptr) return nullptr;
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }

        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        ListNode* result = dummy->next;
        delete dummy;
        return result;        
    }
};

ListNode* createListNode(vector<int> nums) {
    if(nums.empty()) {
        return nullptr;
    }
    ListNode* list = new ListNode(-1);
    ListNode* p1 = list;
    for(int num : nums) {
        ListNode* node = new ListNode(num, nullptr);
        p1->next = node;
        p1 = node;
    }
    ListNode* result = list->next;
    delete list;
    return result;
}

void printListNode(ListNode* list) {
    ListNode* node = list;
    while(node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode* head = createListNode(nums);

    Solution sol;
    ListNode* result = sol.removeNthFromEnd(head, n);
    printListNode(result);

    return 0;
}

/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

输入：head = [1], n = 1
输出：[]

输入：head = [1,2], n = 1
输出：[1]
*/
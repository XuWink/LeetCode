#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* newList = dummy;

        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                newList->next = p1;
                p1 = p1->next;
                newList = newList->next;
            } else {
                newList->next = p2;
                p2 = p2->next;
                newList = newList->next;
            }
        }
        if (p1 != nullptr) {
            newList->next = p1;
        }
        if (p2 != nullptr) {
            newList->next = p2;
        }

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

int main(){
    vector<int> nums1 = {1, 2, 4};
    vector<int> nums2 = {1, 3, 4};

    ListNode* list1 = createListNode(nums1);
    ListNode* list2 = createListNode(nums2);

    Solution sol;
    ListNode* result = sol.mergeTwoLists(list1, list2);
    printListNode(result);

    return 0;
}

/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

输入：l1 = [], l2 = []
输出：[]

输入：l1 = [], l2 = [0]
输出：[0]
*/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next; // 指针类型
    ListNode() : val(0), next(nullptr) {} // 默认构造函数
    ListNode(int x) : val(x), next(nullptr) {} // 单参数构造函数
    ListNode(int x, ListNode* next) : val(x), next(next) {} // 带指针的构造函数
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* p = dummy;

        while(p->next && p->next->next) {
            ListNode* p1 = p->next;
            ListNode* p2 = p->next->next;

            // 交换
            p1->next = p2->next;
            p2->next = p1;
            p->next = p2;

            p = p1;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

    // 反转链表
    ListNode* reverseList(ListNode* list){
        ListNode* pre = nullptr;
        ListNode* current = list;
        while(current){
            ListNode* next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        return pre;
    }
};

/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

输入: head = [1,2,3,4]
输出：[2,1,4,3]

输入: head = []
输出：[]

输入: head = [1]
输出：[1]

*/
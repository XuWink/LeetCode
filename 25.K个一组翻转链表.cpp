#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1) return head;
        ListNode* dummy = new ListNode(0, head);
        // pre指向当前要翻转的k个节点的前一个节点
        ListNode* pre = dummy;
        // end指向当前要翻转的k个节点的最后一个节点
        ListNode* end = dummy;

        while (end->next) {
            // 找到每组的末尾结点
            for (int i = 0; i < k; ++i) {
                if (end == nullptr) break;
                end = end->next;
            }

            if (end == nullptr) break;

            // 保存该组的起点
            ListNode* start = pre->next;

            // 保存下一组的起点
            ListNode* nextStart = end->next;

            end->next = nullptr;

            ListNode* reverseStart = reverseList(start);
            
            pre->next = reverseStart;

            // 连起来
            start->next = nextStart;

            pre = start;
            end = pre;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;           
    }

    ListNode* reverseList(ListNode* list) {
        // 如果链表为空，直接返回 nullptr
        if (list == nullptr) return nullptr;
        
        ListNode* pre = nullptr;       // 前一个节点，初始为 nullptr
        ListNode* current = list;      // 当前节点，初始为链表头

        while (current) {
            ListNode* next = current->next; // 保存下一个节点
            current->next = pre;           // 反转当前节点的指针
            pre = current;                 // 更新前一个节点为当前节点
            current = next;                // 移动到下一个节点
        }

        return pre; // 返回新的头节点
    }
};

/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]

输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]

*/
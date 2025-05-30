#include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* newList = new ListNode(0);
        ListNode* dummy = newList;

        int carry = 0; // 进位
        while(p1 != nullptr && p2 != nullptr) {
            int t1 = p1->val;
            int t2 = p2->val;

            int temp = t1 + t2 + carry;
            carry = temp/10;
            int value = temp%10;
            ListNode* node = new ListNode(value, nullptr);
            dummy->next = node;
            dummy = node;

            p1 = p1->next;
            p2 = p2->next;

        }
        if(p1 != nullptr) {
            while(p1 != nullptr) {
                int temp = p1->val + carry;
                carry = temp/10;
                int value = temp%10;
                ListNode* node = new ListNode(value, nullptr);
                dummy->next = node;
                dummy = node;
                p1 = p1->next;
            }
        }

        if(p2 != nullptr) {
            while(p2 != nullptr) {
                int temp = p2->val + carry;
                carry = temp/10;
                int value = temp%10;
                ListNode* node = new ListNode(value, nullptr);
                dummy->next = node;
                dummy = node;
                p2 = p2->next;
            }
        }

        if(carry != 0) {
            ListNode* node = new ListNode(carry, nullptr);
            dummy->next = node;
            dummy = node;
        }

        ListNode* result = newList->next;
        delete newList;
        return result;
    }

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // 虚拟头节点
        ListNode* current = dummy;         // 当前节点指针
        int carry = 0;                     // 进位
 
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0; // 获取l1当前节点的值
            int val2 = (l2 != nullptr) ? l2->val : 0; // 获取l2当前节点的值
 
            int sum = val1 + val2 + carry; // 当前位的和
            carry = sum / 10;              // 计算新的进位
            current->next = new ListNode(sum % 10); // 创建新节点存储当前位的值
 
            current = current->next; // 移动到下一个节点
            if (l1 != nullptr) l1 = l1->next; // 移动l1指针
            if (l2 != nullptr) l2 = l2->next; // 移动l2指针
        }
 
        ListNode* result = dummy->next; // 获取结果链表的头节点
        delete dummy; // 释放虚拟头节点
        return result;
    }
};

/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

输入：l1 = [0], l2 = [0]
输出：[0]

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]

*/
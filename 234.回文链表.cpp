#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        ListNode* p1 = head;
        ListNode* p2 = head;

        while (p2 != nullptr && p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode* reverseHead = reverseList(p2);
        p1 = head;
        while(reverseHead != nullptr) {
            if (p1->val != reverseHead->val) {
                return false;
            }
            p1 = p1->next;
            reverseHead = reverseHead->next;
        }
        return true;

    }

    // 反转链表
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* pre = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};

int main() {

    return 0;
}

/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

输入：head = [1,2,2,1]
输出：true

输入：head = [1,2]
输出：false
*/
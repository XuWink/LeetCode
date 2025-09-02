#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int        val;
    ListNode * next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode * reverseBetween(ListNode * head, int left, int right) {
        if (head == nullptr) {
            return nullptr;
        }

        if (left == right) {
            return head;
        }

        ListNode * p1 = head;
        ListNode * p2 = head;

        // 找到left的前驱节点
        for (int i = 0; i < left - 1; i++) {
            p1 = p1->next;
        }

        ListNode * start = p1->next;
        p1->next         = nullptr;

        // 找到right节点
        for (int i = 0; i < right; ++i) {
            p2 = p2->next;
        }

        // 保存right后面的
        ListNode * end = p2->next;
        p2->next       = nullptr;

        ListNode * rev = reverse(start);

        p1->next    = rev;
        start->next = end;

        return head;
    }

  private:
    ListNode * reverse(ListNode * head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode * p    = nullptr;
        ListNode * curr = head;

        while (curr) {
            ListNode * next = curr->next;
            curr->next      = p;
            p               = curr;
            curr            = next;
        }
        return p;
    }
};

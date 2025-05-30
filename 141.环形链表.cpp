#include <iostream>

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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return true;
        }

        unordered_set<ListNode*> uset;
        ListNode* p = head;
        while (p != nullptr) {
            if (uset.find(p) != uset.end()) {
                return true;
            }

            uset.insert(p);
            p = p->next;
        }
        return false;
    }

    // Floyd算法（又称为龟兔赛跑算法）
    bool hasCycle2(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

/*
给你一个链表的头节点 head ，判断链表中是否有环。如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。如果链表中存在环 ，则返回 true 。 否则，返回 false 。

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
*/
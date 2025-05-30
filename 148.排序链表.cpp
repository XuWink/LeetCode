#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    struct comp
    {
        bool operator()(ListNode *p1, ListNode *p2)
        {
            return p1->val > p2->val;
        }
    };

    // 可以使用小顶堆
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        // 小顶堆
        priority_queue<ListNode *, vector<ListNode *>, comp> pque;
        ListNode *p = head;
        while (p != nullptr)
        {
            pque.push(p);
            p = p->next;
        }
        ListNode *dummy = new ListNode(0);
        p = dummy;
        while (!pque.empty())
        {
            ListNode *temp = pque.top();
            pque.pop();
            p->next = temp;
            temp->next = nullptr;
            p = temp;
        }

        p = dummy->next;
        delete dummy;
        return p;
    }
};

int main()
{
}

/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

输入：head = [4,2,1,3]
输出：[1,2,3,4]

输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]

输入：head = []
输出：[]

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗
*/
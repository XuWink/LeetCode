#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr){}
	ListNode(int x) : val(x), next(nullptr){}
	ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(head == nullptr){
		   return head;
	   }
	   
	   ListNode* p = head;
	   ListNode* pre = nullptr;
	   
	   while(p != nullptr){
		   ListNode* nextNode = p->next;
		   p->next = pre;
		   pre = p;
		   p = nextNode;
	   }
	   return pre;
    }
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
	Solution sol;

	vector<int> nums = {1,2,3,4,5};
	ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
 
    for (int i = 1; i < nums.size(); ++i) {

        current->next = new ListNode(nums[i]);
        current = current->next;
    }
	

	ListNode* result = sol.reverseList(head); 
	printList(result);
	
	return 0;
}

/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例2：
输入：head = [1,2]
输出：[2,1]

示例3：
输入：head = []
输出：[]
*/
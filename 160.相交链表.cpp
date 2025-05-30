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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;

        while(pa != pb){

            if(pa == nullptr){
                pa = headB;
            }else{
                pa = pa->next;
            }

            if(pb == nullptr){
                pb = headA;
            }else{
                pb = pb->next;
            }
        }
        return pa;
    }
};

/*


*/
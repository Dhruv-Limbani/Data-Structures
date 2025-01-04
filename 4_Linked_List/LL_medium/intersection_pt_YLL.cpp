#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA, *temp2 = headB;
        while(temp1!=temp2){
            temp1=temp1==NULL?headB:temp1->next;
            temp2=temp2==NULL?headA:temp2->next;
        }
        return temp1;
    }
};

/*
    TC: O(length(l1)+length(l2))
    SC: O(1)
*/
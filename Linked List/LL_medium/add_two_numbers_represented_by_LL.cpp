#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans = new ListNode(0), *temp = ans;
    int carry = 0, dig;
    while(l1!=NULL || l2!=NULL){
        dig = carry;
        if(l1!=NULL){
            dig += l1->val;
            l1 = l1->next;
        }
        if(l2!=NULL){
            dig += l2->val;
            l2 = l2->next;
        }
        temp->next = new ListNode(dig%10);
        temp = temp->next;
        carry = dig/10;
    }
    if(carry) temp->next = new ListNode(carry);
    return ans->next;
}
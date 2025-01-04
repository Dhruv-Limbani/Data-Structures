#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* new_head = reverse(head->next);
    ListNode* prev = head->next;
    prev->next = head;
    head->next = NULL;
    return new_head;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* p1 = head, *p2=head, *p3=head;
    int ct = 0;
    while(p2!=NULL){
        ct++;
        if(ct%k==0){
            ListNode* next = p2->next;
            p2->next=NULL;
            if(ct==k) head = reverse(p1);
            else p3->next = reverse(p1);
            p3 = p1;
            p1 = next;
            p2 = next;
        }
        else p2 = p2->next;
    }
    if(ct%k!=0) p3->next = p1;
    return head;
}
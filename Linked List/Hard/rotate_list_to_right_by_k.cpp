#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL) return head;
    ListNode* pt1=head;
    int len = 1;
    while(pt1->next!=NULL){
        pt1=pt1->next;
        len++;
    }
    k %= len;
    k = len-k;
    pt1->next = head;
    while(k--) pt1 = pt1->next;
    head = pt1->next;
    pt1->next = NULL;
    return head;
}

/*
    We join the end of list to head (make it circular)
    find the last node of the rotated list
    then next node of the node is returned as head
    and we make the next pointer of the last node null
*/
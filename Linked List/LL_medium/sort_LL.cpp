#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLL(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<'null'<<endl;
}

ListNode* get_mid(ListNode* head){
    if(head->next==NULL) return head;
    ListNode* fast=head, *slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* left, ListNode* right){
    ListNode* sorted_ll = new ListNode(-1);
    ListNode* temp = sorted_ll;
    while(left!=NULL && right!=NULL){
        if(left->val <= right->val){
            temp->next = left;
            left = left->next;
        }
        else{
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    if(left!=NULL){
        temp->next = left;
    }
    else{
        temp->next = right;
    }
    return sorted_ll->next;
}

ListNode* mergesort_ll(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* mid = get_mid(head);
    ListNode* right = mid->next;
    mid->next = NULL;
    ListNode* left = head;
    left = mergesort_ll(left);
    right = mergesort_ll(right);
    return merge(left,right);
}
ListNode* sortList(ListNode* head) {
    head = mergesort_ll(head);
    return head;
}


/*
    Time Complexity: O(N log N)where N is the number of nodes in the linked list. 
    Finding the middle node of the linked list requires traversing it linearly taking O(N) time complexity 
    and to reach the individual nodes of the list, it has to be split log N times (continuously halve the 
    list until we have individual elements).

    Space Complexity : O(1) as no additional data structures or space is allocated for storage during the merging process. 
    However, space proportional to O(log N) stack space is required for the recursive calls. 
    The maximum recursion depth of log N height is occupied on the call stack.
*/
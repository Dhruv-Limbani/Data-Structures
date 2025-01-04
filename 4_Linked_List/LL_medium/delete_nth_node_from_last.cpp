#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int x){
            data = x;
            next = nullptr;
        }
        Node(int x, Node* n){
            data = x;
            next = n;
        }
};

Node* removeNthFromEnd(Node* head, int n) {
    int len = 0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    n = len + 1 - n;
    if(n==1) return head->next;
    else{
        Node* temp1=head;
        temp = head;
        while(--n && temp!=NULL){
            temp1=temp;
            temp=temp->next;
        }
        temp1->next = temp->next;
        return head;
    }
}
/*
    TC : O(L) + O(L-n+1)
    SC: O(1)
*/


Node* removeKthNode(Node* head, int n)
{
    Node* fast=head, *slow=head;
    while(n--){
        fast = fast->next;
    }
    Node* temp;
    while(fast!=NULL){
        temp = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if(slow==head) return slow->next;
    temp->next = slow->next;
    return head;
}

/*
    TC : O(L)
    SC : O(1)

    using fast and slow pointer, when fast pointer reaches end and the distace between fast and slow is n then slow is the
    node to be deleted
*/
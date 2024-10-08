#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* deleteMiddle(Node* head){
    Node* fast=head, *slow=head, *temp=head;
    while(fast!=NULL && fast->next!=NULL){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow==head) return slow->next;
    temp->next = slow->next;
    return head;
}

/*
    TC: O(n/2)
    SC: O(1)
*/
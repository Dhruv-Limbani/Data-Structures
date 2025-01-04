#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node * removeDuplicates(struct Node *head)
{
    Node *temp = head;
    while(temp->next!=NULL){
        while(temp->next!=NULL && temp->data==temp->next->data){
            temp->next = temp->next->next;
        }
        if(temp->next==NULL) break;
        temp->next->prev = temp;
        temp = temp->next;
    }
    return head;
}
#include<bits/stdc++.h>
using namespace std;

// a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

void deleteAllOccurOfX(struct Node** head_ref, int x) {
    Node *temp = *head_ref, *head = *head_ref;
    while(temp!=NULL){
        if(temp->data==x){
            if(temp->prev==NULL) *head_ref = temp->next;
            else temp->prev->next = temp->next;
            if(temp->next!=NULL){
                temp->next->prev = temp->prev;
            }
        }
        temp = temp->next;
    }
}
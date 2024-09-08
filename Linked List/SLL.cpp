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

Node* insert(Node* head, int x, int p){ // p is position based on 1-based indexing
    if(p==1){
        Node* temp = new Node(x,head);
        head = temp;
    }
    else{
        Node *temp = head, *temp1 = nullptr, *temp2 = new Node(x);
        while(--p && temp->next!=NULL){
            temp1 = temp;
            temp = temp->next;
        }
        if(temp->next!=NULL || (p==0 && temp->next==NULL)) {
            temp2->next = temp;
            temp1->next = temp2;
            return head;
        }
        else{
            temp->next = temp2;
            return head;
        }
    }
    return head;
}

/*
    DELETING A NODE IN LL
*/

Node* delete_node(Node* head, int p){ // p is position based on 1-based indexing
    if(head==NULL) return NULL;
    Node* temp = head;
    if(p==1) head = head->next;
    else{
        Node *temp1 = nullptr;
        while(--p && temp->next!=NULL){
            temp1 = temp;
            temp = temp->next;
        }
        if(temp->next!=NULL) temp1->next = temp->next;
        else temp1->next = nullptr;
    }
    delete temp;
    return head;
}

Node* delete_node_2(Node* head, int p){ // p is position based on 1-based indexing
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head, *temp1 = nullptr, *temp2 = nullptr;
    while(--p && temp->next!=NULL) temp = temp->next;
    if(temp->next!=NULL) {
        temp->data = temp->next->data;
        temp->next = temp->next->next;
    }
    else delete temp;
    return head;
}

// the above approch doesn't empty the memory unlike the previous one but it takes one less temporary variable.

/*
    PRINTING LL AND IT'S LENGTH
*/

void print_length(Node* head){
    int ct=0;
    while(head!=NULL){
        ct++;
        head = head->next;
    }
    cout<<ct<<endl;
}
void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    
    print_length(head);
    printLL(head);
    head = insert(head, 0, 2);
    printLL(head);
    head = insert(head, 3, 4);
    printLL(head);
    head = insert(head, 6, 5);
    printLL(head);

    print_length(head);
    head = delete_node_2(head, 1);
    printLL(head);
    delete_node_2(head, 3);
    printLL(head);
    delete_node_2(head, 4); // if p >= length of LL, last ele will be deleted
    printLL(head);
    print_length(head);
    return 0;
    
}
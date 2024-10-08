#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = NULL;
        }
        Node(int d, Node* n){
            data = d;
            next = n;
        }
};

Node* sort_0_1_2(Node* head) {
    int ct[3] = {0};
    Node* temp = head;
    while(temp!=NULL){
        ct[temp->data]++;
        temp = temp->next;
    }
    temp = head;
    for(int i=0; i<3; i++){
        while(ct[i]--){
            temp->data = i;
            temp = temp->next;
        }
    }
    return head;
}

/*
    TC: O(2n) requires two passes
    SC: O(1)
*/

Node* sort_0_1_2(Node* head) {
    Node *zero = new Node(-1), *one = new Node(-1), *two = new Node(-1);
    Node *temp = head, *temp0 = zero, *temp1 = one, *temp2 = two;
    while(temp!=NULL){
        if(temp->data==0){
            temp0->next = temp;
            temp0 = temp0->next;
        }
        else if(temp->data==1){
            temp1->next = temp;
            temp1 = temp1->next;
        }
        else {
            temp2->next = temp;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    temp2->next=NULL;    // to avoid loop
    temp1->next = two->next;
    temp0->next = one->next;
    return zero->next;
}

/*
    TC: O(n)
    SC: O(1)  // since we are using the same nodes
*/
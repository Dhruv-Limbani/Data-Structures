#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next, *prev;
        Node(){
            data = 0;
            next = nullptr;
            prev = nullptr;
        }
        Node(int x){
            data = x;
            next = nullptr;
            prev = nullptr;
        }
        Node(int x, Node* n, Node* p){
            data = x;
            next = n;
            prev = p;
        }
};

/*
    Constructing DLL from given array
*/

Node* construct_dll(vector<int> arr){
    Node* head = new Node(), *temp = head;
    for(int i=0; i<arr.size(); i++){
        if(i==0) temp->data = arr[i];
        else{
            Node* temp1 = new Node(arr[i],nullptr,temp);
            temp->next = temp1;
            temp = temp1;
        }
    }
    return head;
}

/*
    Insert a node in DLL
*/

Node* insert(Node* head, int x, int p){
    if(head==NULL) return new Node(x);
    if(p==1){
        Node* temp = new Node(x,head,nullptr);
        head->prev = temp;
        return temp;
    }
    Node *temp = head;
    while(--p && temp->next!=NULL) temp = temp->next;
    if(temp->next!=NULL || (p==0 && temp->next==NULL)){
        Node *temp1 = new Node(x, temp, temp->prev);
        temp->prev->next = temp1;
        temp->prev = temp1;
    }
    else{
        Node *temp1 = new Node(x, nullptr, temp);
        temp->next = temp1;
    }
    return head;
}

Node* delete_node(Node* head, int p){
    if(head==NULL || head->next==NULL){
        delete head;
        return NULL;
    }
    Node *temp = head;
    if(p==1){
        temp->next->prev = NULL;
        head = temp->next;
    }
    else{
        while(--p && temp->next!=NULL) temp = temp->next;
        if(temp->next!=NULL){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        else temp->prev->next = NULL;
    }
    delete temp;
    return head;
}

void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void print_length(Node* head){
    int ct=0;
    while(head!=NULL){
        ct++;
        head = head->next;
    }
    cout<<ct<<endl;
}

Node* reverseDLL(Node* head)
{   
    Node* temp = head;
    while(temp!=NULL){
        Node *temp1 = temp->prev;
        temp->prev = temp->next;
        temp->next = temp1;
        head = temp;
        temp = temp->prev;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,4,5};
    Node* head = construct_dll(arr);
    print_length(head);
    printLL(head);

    head = insert(head, 0, 2);
    printLL(head);
    head = insert(head, 3, 4);
    printLL(head);
    head = insert(head, 6, 6);
    printLL(head);

    print_length(head);
    head = delete_node(head, 1);
    printLL(head);
    delete_node(head, 3);
    printLL(head);
    delete_node(head, 4); // if p >= length of LL, last ele will be deleted
    printLL(head);
    print_length(head);

    // cout<<is_present(head, 5)<<endl;
    // cout<<is_present(head, 1)<<endl;

    return 0;
    
}
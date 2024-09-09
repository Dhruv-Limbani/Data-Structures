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


/*
    INSERT A NODE IN LL
*/

// Dhruv#Herc@0703
Node* insert(Node* head, int x, int p){ // p is position based on 1-based indexing
    if(head==NULL) return new Node(x);
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
    Time Complexity: O(1) for inserting the new head of the linked list and O(N) for printing the linked list.

    Space Complexity: O(1), as we have not used any extra space.
*/

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
    Time Complexity: O(N) for traversing the linked list and updating the tail.

    Space Complexity: O(1), as we have not used any extra space.
*/


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

/*
    Time Complexity: Since we are iterating over the entire list,  time complexity is O(N).

    Space Complexity: We are not using any extra space, thus space complexity is O(1) or constant.
*/

/*
    SEARCH AN ELEMENT IN LL
*/

bool is_present(Node* head, int x){
    while(head!=NULL){
        if(head->data==x) return true;
        head = head->next;
    }
    return false;
}
/*
    Time Complexity: O(N) in the worst case if the element is not found. 
    O(1) in the best case if the element is the first element. 

    Space Complexity: O(1) as we did not use any extra space.
*/

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

    cout<<is_present(head, 5)<<endl;
    cout<<is_present(head, 1)<<endl;

    return 0;
    
}
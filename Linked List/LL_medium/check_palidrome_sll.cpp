#include<bits/stdc++.h>
using namespace std;

// Check is given LL is a Palindrome

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


bool isPalindrome_brute_force(Node *head)
{
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    while(head!=NULL){
        if (head->data != st.top()) {
            return false;
        }
        head=head->next;
        st.pop();
    }
    return true;
}
/*
    TC : O(n) + O(n) = O(n)
    SC : O(n) 
*/


// Optimal Approach : Reverse the second half and compare it with the first half
Node* reverseLL(Node *head){
    Node* prev=NULL;
    while(head!=NULL){
        Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    Node* slow = head, *fast=head;
    while(fast->next!=NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = reverseLL(slow->next);
    fast = head;
    slow = temp;
    while(slow!=NULL){
        if(slow->data!=fast->data){
            reverseLL(temp);
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    reverseLL(temp);
    return true;
}

/*
    TC : O(n/2) + O(n/2) + O(n/2) + O(n/2) = O(2*n) = O(n)
    SC : O(1)
*/
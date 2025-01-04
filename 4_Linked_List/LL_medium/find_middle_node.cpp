#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given the head of a linked list of integers, determine the middle node 
    of the linked list. However, if the linked list has an even number of nodes, return the second middle node.
*/

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

// Find the length of ll and then reduce it to half + 1 and return the node at half+1 position
Node *brute_force(Node *head) {
    int len = 0;
    Node *temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    len = len/2 + 1;
    temp = head;
    while(temp!=NULL){
        len--;
        if(len==0) return temp;
        temp = temp->next;
    }
    return temp;
}
/*
    TC: O(n) + O(n/2)
    SC: O(1)
*/

// slow pointer advances by one and fast pointer advances by 2, by the time fast reaches end, the slow pointer will be pointing at middle node.
Node *optimal(Node *head) {
    int len = 0;
    Node* slow = head, *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
/*
    TC: O(n/2)
    SC: O(1)
*/
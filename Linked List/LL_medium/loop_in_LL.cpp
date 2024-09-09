#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given the head of a linked list of integers, return true if there is a loop or else false
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

// brute_force approach = store each traversed node in a map and checking if it has already been visited or not 
bool detectCycle(Node *head)
{
    unordered_map<Node*,int> m;
    while(head!=NULL){
        if(m.find(head)!=m.end()) return true;
        else m[head]=1;
        head=head->next;
    }
    return false;
}

// to return the start point of the loop
Node *firstNode(Node *head)
{
    unordered_map<Node*,int> m;
    while(head!=NULL){
        if(m.find(head)!=m.end()) break;
        else m[head]=1;
        head=head->next;
    }
    return head;
}

/*
    TC: O(n*2logn)
    SC: O(n)
*/
        
/*
    Optimal Approach 1 - replace all the data elements by a constant 'c' (here -1) as you traverse. If you find a node with 'c' already then return true.
    Only works if none of the elements are eqaul to 'c'. 
*/ 

bool detectCycle(Node *head)
{
    while(head!=NULL){
        if(head->data==-1) return true;
        else head->data = -1;
        head = head->next;
    }
    return false;
}

/*
    Time Complexity: O(N) 

    Space Complexity: O(1) 
*/


// Optimal Approach 2
/*
    Use slow and fast pointer, if at any point fast ptr == slow then return true else if fast == NULL or fast->next==NULL return fast

*/
bool detectCycle(Node *head)
{
    Node* slow = head, *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}

/*
    TC: O(N)
    SC: O(1)
*/

// to return the start point of the loop

Node *firstNode(Node *head)
{
    Node* slow = head, *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            slow = head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        };
    }
    return NULL;
}

/* 
    lets say that when slow is at start point of loop (which we won't know), fast would have already been in the loop.
    if L1 is the distance of slow from head then 2*L1 will be the distance covered by fast. 
    let the remaining length of loop be d which will also be equal to the distance between slow and fast ptr if we visually imagine
    then total length of loop will be d+l1. Now since slow advances by 1 and fast by 2 net relative speed of fast will be 1
    therefore it will take d steps for fast to reach slow. At the same time slow would also have travelled d steps from the start of the loop
    now the remaining distance in the loop will be d+L1 - d = L1 which is equal to distace from head to start point.

    Hence when both ptrs meet, we set slow ptr at head and then increment both ptr by 1 and the node where they meet is the start point
    of the loop.

    TC: O(n)
    SC: O(1)  
*/
#include<bits/stdc++.h>
using namespace std;

 
class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
 

int brute_force_1(Node *head) {
    int lt = 0;
    while(head!=NULL){
        if(head->data==0){
            while(head->data==0){
                lt++;
                head->data=-1;
                head = head->next;
            }
            return lt;
        }
        head->data=0;
        head = head->next;
    }
    return lt;
}


int brute_force_2(Node *head) {
    int lt = 0;
    unordered_map<Node*, int> m;
    while(head!=NULL){
        if(m.find(head)!=m.end()){
            return (lt - m[head]+1);
        }
        else{
            lt++;
            m[head] = lt;
        }
        head = head->next;
    }
    return 0;
}

int optimal(Node *head) {
    int lt=0,a=0,b=0;
    Node *slow = head, *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            lt=1;
            fast=fast->next;
            while(slow!=fast){
                lt++;
                fast = fast->next;
            }
            return lt;
        }
    }
    return 0;
}
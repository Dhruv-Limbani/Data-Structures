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

void printLL(Node *head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"null";
}

Node* constructSLL(vector<int> a){
    Node* head = new Node(0), *prev=head;
    for(int i=0; i<a.size(); i++){
        if(i==0) head->data=a[i];
        else{
            prev -> next = new Node(a[i],NULL);
            prev = prev->next;
        }
    }
    return head;
}

Node* segregate_even_odd(Node *head){
    Node *even = new Node(0), *odd=new Node(0), *temp1=even, *temp2=odd;
    while(head!=NULL){
        Node* temp = head->next;
        head->next = NULL;
        if(head->data%2==0){
            temp1 -> next = head;
            temp1 = head;
        }
        else{
            temp2 -> next = head;
            temp2 = head;
        }
        head = temp;
    }
    temp1->next = odd->next;
    head = even->next;
    return head;
}
/*
    TC: O(N)
    SC: O(1)
*/

int main(){
    vector<int> a = {1,2,3,4,5,6,7};
    Node *head = constructSLL(a);
    head = segregate_even_odd(head);
    printLL(head);
}
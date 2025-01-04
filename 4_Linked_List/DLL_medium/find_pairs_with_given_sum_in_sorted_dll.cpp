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

// brute force -> try all pairs p1 from head to tail, p2 from p1->next to tail

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> ans;
    Node* p1 = head, *p2=head;
    while(p2->next!=NULL) p2 = p2->next;
    while(p1->data<p2->data){
        if(p1->data + p2->data == target){
            ans.push_back({p1->data, p2->data});
            p1 = p1->next;
            p2 = p2->prev;
        }
        else if(p1->data+p2->data<target) p1 = p1->next;
        else p2 = p2->prev;
    }
    return ans;
}
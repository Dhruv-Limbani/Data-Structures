#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if(root==NULL) return root;
    Node* curr = root;
    while(curr->left){
        Node* temp = curr->left;
        curr->left->next = curr->right;
        while(curr->next){
            curr->right->next = curr->next->left;
            curr = curr->next;
            curr->left->next = curr->right;
        }
        curr = temp;
    }

    // queue<Node*> q;
    // q.push(root);
    // while(!q.empty()){
    //     int len = q.size();
    //     while(len--){
    //         if(q.front()->left!=NULL) q.push(q.front()->left);
    //         if(q.front()->right!=NULL) q.push(q.front()->right);
    //         Node* temp = q.front();
    //         q.pop();
    //         if(len!=0) temp->next = q.front();
    //     }    
    // }
    return root;
}
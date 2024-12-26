#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//recursive
void findCeil(Node* root, int x, int &c){
    if(root==NULL) return;
    if(root->data==x){
        c=x;
    }
    else if(root->data<x) findCeil(root->right, x, c);
    else{
        c = root->data;
        findCeil(root->left, x, c);
    }
    return;
}

//iterative
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int c=-1;
    // findCeil(root, input, c);
    while(root!=NULL){
        if(root->data==input) {
            c=root->data;
            break;
        }
        else if(root->data<input) root = root->right;
        else{
            c = root->data;
            root = root->left;
        }
    }
    return c;
}
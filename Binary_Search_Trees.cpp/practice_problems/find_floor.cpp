#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// recursive
void findFloor(Node* root, int x, int &c){
    if(root==NULL) return;
    if(root->data==x){
        c=x;
    }
    else if(root->data>x) findFloor(root->left, x, c);
    else{
        c = root->data;
        findFloor(root->right, x, c);
    }
    return;
}

// iterative
int floor(Node* root, int x) {
    if (root == NULL) return -1;
    int c=-1;
    // findFloor(root, x, c);
    while(root!=NULL){
        if(root->data==x) {
            c=root->data;
            break;
        }
        else if(root->data>x) root = root->left;
        else{
            c = root->data;
            root = root->right;
        }
    }
    return c;
}
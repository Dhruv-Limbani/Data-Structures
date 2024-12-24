#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int minValue(Node* root) {
    while(root->left!=NULL) root = root->left;
    return root->data;
}

int maxValue(Node* root) {
    while(root->right!=NULL) root = root->right;
    return root->data;
}
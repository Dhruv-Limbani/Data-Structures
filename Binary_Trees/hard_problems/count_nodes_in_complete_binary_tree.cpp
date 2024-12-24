#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

int left_height(TreeNode* root)
{
    int h=0;
    while(root!=NULL){
        h++;
        root = root->left;
    }
    return h;
}

int right_height(TreeNode* root)
{
    int h=0;
    while(root!=NULL){
        h++;
        root = root->right;
    }
    return h;
}

int countNodes(TreeNode* root) {
    if(root==NULL) return 0;
    int lh = left_height(root);
    int rh = right_height(root);
    if(lh==rh) return pow(2,lh)-1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
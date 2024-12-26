#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root==NULL) return new TreeNode(val);
    TreeNode* temp = root, *parent;
    while(root!=NULL){
        parent = root;
        if(val<root->val) root = root->left;
        else root = root->right;
    }
    if(val<parent->val) parent->left = new TreeNode(val);
    else parent->right = new TreeNode(val);
    return temp;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root==NULL) return new TreeNode(val);
    TreeNode* temp = root;
    while(true){
        if(val<root->val){
            if(root->left==NULL){
                root->left = new TreeNode(val);
                break;
            }
            root = root->left;
        }
        else{
            if(root->right==NULL){
                root->right = new TreeNode(val);
                break;
            }
            root = root->right;
        }
    }
    return temp;
}
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

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL) return NULL;
    TreeNode* temp=root, *parent=root;
    while(temp!=NULL){
        if(key>temp->val) {
            parent = temp;
            temp = temp->right;
        }
        else if(key<temp->val) {
            parent = temp;
            temp = temp->left;
        }
        else{
            if(temp->left==NULL && temp->right!=NULL){
                if(temp==root) return temp->right;
                if(key<parent->val) parent->left = temp->right;
                else parent->right = temp->right;
                delete temp;
            }
            else if(temp->left!=NULL && temp->right==NULL){
                if(temp==root) return temp->left;
                if(key<parent->val) parent->left = temp->left;
                else parent->right = temp->left;
                delete temp;
            }
            else if(temp->left==NULL && temp->right==NULL){
                if(temp==root) return NULL;
                if(key<parent->val) parent->left = NULL;
                else parent->right = NULL;
                delete temp;
            }
            else{
                TreeNode* temp1 = temp->right;
                parent = temp;
                while(temp1->left!=NULL){
                    parent = temp1;
                    temp1 = temp1->left;
                }
                if(parent==temp) parent->right = temp1->right;
                else parent->left = temp1->right;
                temp->val = temp1->val;
                delete temp1;
            }
            break;
        }
    }
    return root;
}
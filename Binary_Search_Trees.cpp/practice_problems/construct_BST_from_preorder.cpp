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

// brute force: O(n^2)
void insert(TreeNode* root, TreeNode* node){
    while(root){
        if(node->val<root->val){
            if(root->left==NULL) {
                root->left = node;
                break;
            }
            root = root->left;
        } 
        else{
            if(root->right==NULL) {
                root->right = node;
                break;
            }
            root = root->right;
        } 
    }
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = NULL;
    for(auto it: preorder){
        if(root==NULL) root = new TreeNode(it);
        else{
            TreeNode* node = new TreeNode(it);
            insert(root, node);
        }
    }
    return root;
}

/*
better solution: sort the preorder to get inorder and construct unique bst from preorder and inorder
O(nlogn) time and O(n) space
*/

// optimal: O(n)
TreeNode* bstFromPreorder(vector<int>& preorder, int &i, int ub){
    if(i == preorder.size() || preorder[i]>ub) return NULL;
    TreeNode* root = new TreeNode(preorder[i]);
    i++;
    root->left = bstFromPreorder(preorder, i, root->val);
    root->right = bstFromPreorder(preorder, i, ub);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    if(!preorder.size()) return NULL;
    int i=0;
    return bstFromPreorder(preorder, i, INT_MAX);
}
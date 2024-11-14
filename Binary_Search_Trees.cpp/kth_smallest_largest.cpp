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

void kthSmallest(TreeNode* root, int &k, int &ans){
    if(root!=NULL){
        kthSmallest(root->left, k, ans);
        k--;
        if(k==0) ans = root->val;
        kthSmallest(root->right, k, ans);
    }
}
int kthSmallest(TreeNode* root, int k) {
    int ans;
    kthSmallest(root, k, ans);
    return ans;
}

void kthLargest(TreeNode* root, int &k, int &ans){
    if(root!=NULL){
        kthLargest(root->right, k, ans);
        k--;
        if(k==0) ans = root->val;
        kthLargest(root->left, k, ans);
    }
}
int kthLargest(TreeNode* root, int k) {
    int ans;
    kthLargest(root, k, ans);
    return ans;
}

// can also be done using morris inorder traversal
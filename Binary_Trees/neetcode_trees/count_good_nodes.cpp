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

// keep track of maximum value so far in path
int goodNodes(TreeNode* root, int mx){
    if(root!=NULL){
        mx = max(mx, root->val);
        return 1*(mx==root->val) + goodNodes(root->left, mx) + goodNodes(root->right, mx); 
    }
    return 0;
}
int goodNodes(TreeNode* root) {
    if(root!=NULL) return goodNodes(root, root->val);
    return 0;
}
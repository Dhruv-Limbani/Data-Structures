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

bool isValid(TreeNode* root, long left, long right){
    if(root!=NULL){
        if (!(left < root->val && root->val < right)) return false;
        return isValid(root->left, left, root->val) && isValid(root->right, root->val, right); 
    }
    return true;
}
bool isValidBST(TreeNode* root) {
    return isValid(root, LONG_MIN, LONG_MAX);
}
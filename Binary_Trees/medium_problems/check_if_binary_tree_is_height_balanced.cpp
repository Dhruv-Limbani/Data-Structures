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

int height(TreeNode* root){
    if(root!=NULL){
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh==-1 || rh==-1 || (abs(lh-rh)>=2)) return -1;
        return 1+max(lh,rh);
    }
    return 0;
}
bool isBalanced(TreeNode* root) {
    return height(root)!=-1;
}
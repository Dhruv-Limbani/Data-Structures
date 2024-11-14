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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || root==p || root==q) return root;
    TreeNode* root1 = lowestCommonAncestor(root->left, p, q);
    TreeNode* root2 = lowestCommonAncestor(root->right, p, q);
    if(root1==NULL) return root2;
    if(root2==NULL) return root1;
    return root;
}
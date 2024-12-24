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

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int post_s, int post_e, int in_s, int in_e) {
    if(post_s>post_e && in_s>in_e) return nullptr;
    else if(post_s == post_e || in_s == in_e) return new TreeNode(inorder[in_s]);
    int i=in_s, parent = postorder[post_e];
    while(inorder[i]!=parent && i<=in_e) i++;
    TreeNode* left_child = buildTree(postorder, inorder, post_s, post_s+(i-in_s)-1, in_s, i-1);
    TreeNode* right_child = buildTree(postorder, inorder, post_s+(i-in_s), post_e-1, i+1, in_e);
    return new TreeNode(parent, left_child, right_child);
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTree(postorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1);
}
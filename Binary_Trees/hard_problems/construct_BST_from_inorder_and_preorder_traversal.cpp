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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre_s, int pre_e, int in_s, int in_e) {
    if(pre_s>pre_e && in_s>in_e) return nullptr;
    else if(pre_s == pre_e || in_s == in_e) return new TreeNode(inorder[in_s]);
    int i=in_s, parent = preorder[pre_s];
    while(inorder[i]!=parent && i<=in_e) i++;
    TreeNode* left_child = buildTree(preorder, inorder, pre_s+1, pre_s+(i-in_s), in_s, i-1);
    TreeNode* right_child = buildTree(preorder, inorder, pre_s+(i-in_s)+1, pre_e, i+1, in_e);
    return new TreeNode(parent, left_child, right_child);
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}
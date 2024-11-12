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

int maxDepth(TreeNode* root, int &diameter) {
    if(root!=NULL){
        int left_height = maxDepth(root->left, diameter);
        int right_height = maxDepth(root->right, diameter);
        diameter = max(diameter, left_height + right_height);
        return 1 + max(left_height, right_height);
    }
    return 0;
}
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    maxDepth(root, diameter);
    return diameter;
}

/*
    the length of diameter passing through a node will be a max_depth(node's left subtree) + max_depth(node's right subtree)
    there for diameter = max(for every node: max_depth(node's left subtree) + max_depth(node's right subtree))
*/

/*
    TC: O(n)
    SC: O(1)
*/
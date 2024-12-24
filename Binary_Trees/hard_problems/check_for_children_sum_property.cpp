#include<bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    
    void changeTree(TreeNode* root){
        if(root==NULL) return;
        int sum=0;
        if(root->left!=NULL) sum+=root->left->val;
        if(root->right!=NULL) sum+=root->right->val;
        if(root->val<sum) root->val = sum;
        else if(root->val>sum) {
            if(root->left!=NULL) root->left->val += root->val-sum;
            else if(root->right!=NULL) root->right->val += root->val-sum;
        }
        changeTree(root->left);
        changeTree(root->right);
        sum=0;
        if(root->left!=NULL) sum+=root->left->val;
        if(root->right!=NULL) sum+=root->right->val;
        if(root->val<sum) root->val = sum;
        return;
    }
};

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    // Print the inorder traversal
    // of tree before modification
    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    // Call the changeTree function
    // to modify the binary tree
    sol.changeTree(root);

    // Print the inorder traversal
    // after modification
    cout << "Binary Tree after Children Sum Property: " ;
    inorderTraversal(root);
    cout << endl;

    return 0;
}
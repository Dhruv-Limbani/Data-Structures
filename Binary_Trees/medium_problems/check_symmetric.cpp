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

bool isSame(TreeNode* n1, TreeNode* n2){
    if(n1==NULL && n2==NULL) return true;
    else if(n1!=NULL && n2!=NULL){
        return n1->val==n2->val && isSame(n1->left, n2->right) && isSame(n1->right, n2->left);
    }
    return false;
}
bool isSymmetric(TreeNode* root) {
    return root==NULL || isSame(root->left, root->right);
}
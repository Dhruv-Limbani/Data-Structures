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

bool isSame(TreeNode* root1, TreeNode* root2){
    if(root1==NULL && root2==NULL) return true;
    if(root1!=NULL && root2!=NULL && root1->val==root2->val){
        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
    }
    return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(subRoot==NULL) return true; // a null tree is always a subtree of any tree
    if(root!=NULL){     // if subtree not a null
        if(isSame(root, subRoot)) return true;
        else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    return false;  // subtree not null and main tree null
}
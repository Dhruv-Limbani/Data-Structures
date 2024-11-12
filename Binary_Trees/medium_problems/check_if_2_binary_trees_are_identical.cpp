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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL && q==NULL) return true;
    else if(p!=NULL && q!=NULL){
        if(p->val!=q->val) return false;
        if(!isSameTree(p->left, q->left)) return false;
        if(!isSameTree(p->right, q->right)) return false;
        return true;
    }
    return false;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL && q==NULL) return true;
    else if(p!=NULL && q!=NULL){
        return (p->val==q->val)*isSameTree(p->left, q->left)*isSameTree(p->right, q->right);
    }
    return false;
}
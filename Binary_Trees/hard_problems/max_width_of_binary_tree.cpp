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

int widthOfBinaryTree(TreeNode* root) {
    if(root==NULL) return 0;
    queue<pair<TreeNode*, long>> q;
    q.push({root, 0});
    long mx_wd = 0;
    while(!q.empty()){
        long s=q.size(), mn = q.front().second;
        while(s--){
            long idx = q.front().second-mn;
            mx_wd = max(mx_wd, idx+1);
            if(q.front().first->left!=NULL) q.push({q.front().first->left, 2*idx+1});
            if(q.front().first->right!=NULL) q.push({q.front().first->right, 2*idx+2});
            q.pop();
        }
    }
    return (int)mx_wd;
}
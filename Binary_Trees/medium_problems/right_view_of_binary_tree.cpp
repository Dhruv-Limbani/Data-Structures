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

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    queue<TreeNode*> q;
    if(root==NULL) return ans;
    q.push(root);
    int n = q.size();
    while(n){
        
        // after storing each level of level order traversal, we print its back for right view and front for its left view
        ans.push_back(q.back()->val); 
        for(int i=0; i<n; i++){
            if(q.front()->left != NULL) q.push(q.front()->left);
            if(q.front()->right != NULL) q.push(q.front()->right);
            q.pop();
        }
        n = q.size();

    }
    return ans;
}

void rightView(TreeNode* root, vector<int> &ans, int level){
    if(root==NULL) return;
    if(level==ans.size()) ans.push_back(root->val);
    rightView(root->right, ans, level+1);
    rightView(root->left, ans, level+1);
}

void leftView(TreeNode* root, vector<int> &ans, int level){
    if(root==NULL) return;
    if(level==ans.size()) ans.push_back(root->val);
    leftView(root->left, ans, level+1);
    leftView(root->right, ans, level+1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    rightView(root, ans, 0);
    return ans;
}
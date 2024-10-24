#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        TreeNode *left, *right;
        int data;

        TreeNode(int val){
            data = val;
            left = NULL;
            right = NULL;
        }

        TreeNode(TreeNode* l, TreeNode* r, int val){
            left = l;
            right = r;
            data = val;
        }

};

void preorder(TreeNode* root, vector<int> &arr){
    if(root!=NULL){
        arr.push_back(root->data);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }
}

void inorder(TreeNode* root, vector<int> &arr){
    if(root!=NULL){
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
}

void postorder(TreeNode* root, vector<int> &arr){
    if(root!=NULL){
        postorder(root->left, arr);
        postorder(root->right, arr);
        arr.push_back(root->data);
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans = {};
    if(root==NULL) return ans; 
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> lvl;
        for(int i=0; i<size; i++){
            lvl.push_back(q.front()->data);
            if(q.front()->left != NULL)
                q.push(q.front()->left);
            if(q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        ans.push_back(lvl);
    }
    return ans;
}
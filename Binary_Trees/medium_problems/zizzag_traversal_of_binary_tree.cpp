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

// queue method
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    int LtoR = 1;
    while(!q.empty()){
        int s = q.size();
        vector<int> lvl(s);
        for(int i=0; i<s; i++){
            TreeNode* node = q.front();
            int index = LtoR?i:s-i-1;
            lvl[index] = node->val;
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            q.pop();
        }
        LtoR = !LtoR;
        ans.push_back(lvl);
    }
    return ans;
}

// two stacks method
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    stack<TreeNode*> s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        vector<int> lvl;
        if(s1.empty()){
            while(!s2.empty()){
                TreeNode* node = s2.top();
                lvl.push_back(node->val);
                if(node->right!=NULL) s1.push(node->right);
                if(node->left!=NULL) s1.push(node->left);
                s2.pop();
            }
            ans.push_back(lvl);
        }
        else{
            while(!s1.empty()){
                TreeNode* node = s1.top();
                lvl.push_back(node->val);
                if(node->left!=NULL) s2.push(node->left);
                if(node->right!=NULL) s2.push(node->right);
                s1.pop();
            }
            ans.push_back(lvl);
        }
    }
    return ans;
}
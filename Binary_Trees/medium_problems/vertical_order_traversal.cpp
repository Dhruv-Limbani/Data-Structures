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

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> mp;
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<pair<TreeNode*, pair<int,int>>> q;
    q.push({root,{0, 0}});
    while(!q.empty()){
        int row = q.front().second.first, col = q.front().second.second;
        TreeNode* node = q.front().first;
        mp[col][row].insert(node->val);
        if(node->left!=NULL) q.push({node->left,{row+1, col-1}});
        if(node->right!=NULL) q.push({node->right,{row+1, col+1}});
        q.pop();
    }
    for(auto it: mp) {
        vector<int> temp;
        for(auto it2: it.second){
            temp.insert(temp.end(), it2.second.begin(), it2.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}
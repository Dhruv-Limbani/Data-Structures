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

// solution 1
void distanceK(TreeNode* root, vector<int> &nodes,  unordered_map<TreeNode*, TreeNode*> &p, unordered_map<TreeNode*, int> &visited, int k){
    if(root==NULL || visited[root]) return;
    visited[root] = 1;
    if(k==0){
        nodes.push_back(root->val);
        return;
    }
    distanceK(p[root], nodes, p, visited, k-1);
    distanceK(root->left, nodes, p, visited, k-1);
    distanceK(root->right, nodes, p, visited, k-1);
}
void find_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp, unordered_map<TreeNode*, int> &visited){
    visited[root] = 0;
    if(root->left != NULL){
        mp[root->left] = root;
        find_parents(root->left, mp, visited);
    }
    if(root->right != NULL) {
        mp[root->right] = root;
        find_parents(root->right, mp, visited);
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if(root==NULL) return {};
    vector<int> nodes;
    unordered_map<TreeNode*, TreeNode*> p;
    unordered_map<TreeNode*, int> visited;
    find_parents(root, p, visited);
    distanceK(target, nodes, p, visited, k);
    return nodes;
}

// solution 2


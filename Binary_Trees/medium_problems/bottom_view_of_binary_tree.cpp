#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// same as top view but, here we overwrite value if key already exisits in the map
vector <int> bottomView(Node *root) {
    map<int, int> mp;
    vector<int> ans;
    if(root==NULL) return ans;
    queue<pair<Node*, int>> q;
    q.push({root,0});
    while(!q.empty()){
        int lvl = q.front().second;
        Node* node = q.front().first;
        mp[lvl] = node->data;
        if(node->left!=NULL) q.push({node->left,lvl-1});
        if(node->right!=NULL) q.push({node->right,lvl+1});
        q.pop();
    }
    for(auto it: mp) ans.push_back(it.second);
    return ans;
}
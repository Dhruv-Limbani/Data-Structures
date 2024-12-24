#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    //path from root to all leaf nodes from left to right
    void Paths(TreeNode* root, vector<vector<int>> &paths, vector<int> &current_path){
        current_path.push_back(root->data);
        if(root->left==NULL && root->right==NULL) paths.push_back(current_path);
        if(root->left!=NULL) Paths(root->left, paths, current_path);
        if(root->right!=NULL) Paths(root->right, paths, current_path);
        current_path.pop_back();
    }
    //path from root to node with target value
    bool Path(TreeNode* root, vector<int> &path, int target){
        if(root==NULL) return false;
        path.push_back(root->data);
        if(root->data==target) return true;
        else if (Path(root->left, path, target) || Path(root->right, path, target)) return true;
        path.pop_back();
        return false;
    }

    vector<int> solve(TreeNode* root, int target) {
        vector<int> path;
        vector<int> cp;
        Path(root, path, target);
        return path;
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    int targetLeafValue = 7;

    vector<int> path = sol.solve(root, targetLeafValue);

    cout << "Path from root to leaf with value " <<
        targetLeafValue << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    return 0;
}
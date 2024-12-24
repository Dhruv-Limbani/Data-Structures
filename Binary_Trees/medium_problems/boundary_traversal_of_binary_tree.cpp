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


class Solution{
    public:
        void get_leaves(TreeNode* root, vector<int> &boundary){
            if(root==NULL) return;
            get_leaves(root->left, boundary);
            get_leaves(root->right, boundary);
            if(root->left==NULL && root->right==NULL) boundary.push_back(root->val);
        }

        void left_boundary(TreeNode* root, vector<int> &boundary){
            while(root!=NULL){
                if(root->left!=NULL || root->right!=NULL){
                    boundary.push_back(root->val);
                }
                if(root->left!=NULL) root = root->left;
                else root = root->right;
            }
        }

        void right_boundary(TreeNode* root, vector<int> &boundary){
            while(root!=NULL){
                if(root->left!=NULL || root->right!=NULL){
                    boundary.push_back(root->val);
                }
                if(root->right!=NULL) root = root->right;
                else root = root->left;
            }
        }

        vector<int> printBoundary(TreeNode* root) {
            vector<int> boundary;
            left_boundary(root, boundary);
            get_leaves(root, boundary);
            vector<int> r_boundary;
            right_boundary(root->right, r_boundary);
            reverse(r_boundary.begin(), r_boundary.end());
            boundary.insert(boundary.end(), r_boundary.begin(), r_boundary.end());
            return boundary;
        }
};

void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}
                            





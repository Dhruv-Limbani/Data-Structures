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

int maxPathSum(TreeNode* root, int &mx){
    if(root!=NULL){
        int left_max = max(0, maxPathSum(root->left, mx));
        int right_max = max(0, maxPathSum(root->right, mx));
        mx = max(mx, root->val+right_max+left_max);
        return root->val+max(right_max,left_max);
    }
    return 0;
}
int maxPathSum(TreeNode* root) {
    int max_path_sum = INT_MIN;
    maxPathSum(root, max_path_sum);
    return max_path_sum;
}
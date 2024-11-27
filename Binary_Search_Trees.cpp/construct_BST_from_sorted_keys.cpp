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

TreeNode* BST(vector<int>& nums, int start, int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    TreeNode* left = BST(nums, start, mid-1);
    TreeNode* right = BST(nums, mid+1, end);
    return new TreeNode(nums[mid], left, right);
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return BST(nums, 0, nums.size()-1);
}
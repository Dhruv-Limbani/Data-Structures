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


// morris inorder
class BSTIterator {
public:
    TreeNode* root;
    BSTIterator(TreeNode* root) {
        this->root = root;
    }
    
    int next() {
        int a = 0;
        if(root->left==NULL){
            a = root->val;
            root = root->right;
            return a;
        }
        else{
            TreeNode* temp = root->left;
            while(temp->right!=NULL && temp->right!=root) temp = temp->right;
            if(temp->right==NULL){
                temp->right = root;
                root = root->left;
                return next();
            }
            else if(temp->right==root){
                a = root->val;
                temp->right=NULL;
                root = root->right;
                return a;
            }
        }
        return a;
    }
    
    bool hasNext() {
        return root!=NULL;
    }
};

// iterative inorder
class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode* node;
    BSTIterator(TreeNode* root) {
        this->node = root;
        push_all_left(node);
    }
    void push_all_left(TreeNode* node){
        if(node==NULL) return;
        st.push(node);
        while(st.top()->left!=NULL) st.push(st.top()->left);
    }
    int next() {
        TreeNode* top = st.top();
        int val = top->val;
        st.pop();
        if(top->right!=NULL) push_all_left(top->right);
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
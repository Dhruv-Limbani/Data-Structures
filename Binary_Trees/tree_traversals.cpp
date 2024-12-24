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

void all_order_traversals(TreeNode* root, vector<int> &pre, vector<int> &in, vector<int> &post){
    if(root!=NULL){
        pre.push_back(root->data);
        all_order_traversals(root->left, pre, in, post);
        in.push_back(root->data);
        all_order_traversals(root->right, pre, in, post);
        post.push_back(root->data);
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

vector<int> preorderTraversal_iterative(TreeNode* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* top = s.top();
        s.pop();
        ans.push_back(top->data);
        if(top->right != NULL) s.push(top->right);
        if(top->left != NULL) s.push(top->left);
    }
    return ans;
}

vector<int> inorderTraversal_iterative(TreeNode* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    stack<TreeNode*> s;
    TreeNode* node = root;
    while(true){
        if(node!=NULL) {
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty()) break;
            ans.push_back(s.top()->data);
            node = s.top()->right;
            s.pop();
        }
    }
    return ans;
}

vector<int> postorderTraversal_iterative_using_one_stack(TreeNode* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    stack<TreeNode*> s;
    TreeNode* top = root;
    s.push(root);
    while(!s.empty()){
        if((s.top()->left == top || s.top()->right == top) || (s.top()->left==NULL && s.top()->right==NULL)){
            top = s.top();
            ans.push_back(top->data);
            s.pop();
        }
        else{
            TreeNode* temp = s.top();
            if(temp->right!=NULL) s.push(temp->right);
            if(temp->left!=NULL) s.push(temp->left);
        }
    }
    return ans;
}

vector<int> morris_inorder(TreeNode* root){
    vector<int> in;
    TreeNode* curr;
    while(curr!=NULL){
        if(curr->left==NULL){
            in.push_back(curr->data);
            curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr) prev = prev->right;
            if(prev->right==NULL){
                prev->right=curr;
                curr = curr->left;
            }
            else{
                prev->right==NULL;
                in.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return in;
}

vector<int> morris_preorder(TreeNode* root){
    vector<int> pre;
    TreeNode* curr;
    while(curr!=NULL){
        if(curr->left==NULL){
            pre.push_back(curr->data);
            curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr) prev = prev->right;
            if(prev->right==NULL){
                prev->right=curr;
                pre.push_back(curr->data);     // only this is shifted from else block to if
                curr = curr->left;
            }
            else{
                prev->right==NULL;
                curr = curr->right;
            }
        }
    }
    return pre;
}

vector<vector<int>> preInPostTraversal(TreeNode * root){
    vector<int> pre, in, post;
    if(root==NULL) return {pre, in, post};
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    while(!st.empty()){
        TreeNode* node = st.top().first;
        if(st.top().second==1){
            st.top().second++;
            pre.push_back(node->data);
            if(node->left!=NULL) st.push({node->left, 1});
        }
        else if(st.top().second==2){
            st.top().second++;
            in.push_back(node->data);
            if(node->right!=NULL) st.push({node->right, 1});
        }
        else{
            post.push_back(node->data);
            st.pop();
        }
    }
    return {pre, in, post};
}

// Main function
int main()
{
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
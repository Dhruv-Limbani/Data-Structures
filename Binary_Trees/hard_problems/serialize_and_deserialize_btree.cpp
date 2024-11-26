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

class Codec {
public:

    // Encodes a tree to a single string.
    int get_data(string s, int i, int j){
        string t = "";
        while(i<j) t += s[i++];
        return stoi(t);
    }

    string serialize(TreeNode* root) {
        if(root==NULL) return "n";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            if(q.front()==NULL) s+="n,";
            else{
                q.push(q.front()->left);
                q.push(q.front()->right);
                if(s.length()) s+= to_string(q.front()->val) + ",";
                else s+=to_string(q.front()->val) + ",";
            }
            q.pop();
        }
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s=="n") return NULL;
        int len = s.length(), i=0;
        while(s[i]!=',') i++;
        TreeNode* root = new TreeNode(get_data(s,0,i));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            TreeNode* temp = q.front();
            if(s[i+1]!='n'){
                int j=++i;
                while(i<s.length() && s[i]!=',') i++;
                q.front()->left = new TreeNode(get_data(s,j,i));
                q.push(q.front()->left);
            }
            else i += 2;
            if(s[i+1]!='n'){
                int j=++i;
                while(i<s.length() && s[i]!=',') i++;
                q.front()->right = new TreeNode(get_data(s,j,i));
                q.push(q.front()->right);
            }
            else i += 2;
            q.pop();
        }
        return root;
    }
};
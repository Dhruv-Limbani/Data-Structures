#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int count_time(Node* root, unordered_map<int, Node*> &p, unordered_map<int, int> &visited){
    if(root==NULL || visited[root->data]) return 0;
    visited[root->data] = 1;
    int time = 0;
    if(p.find(root->data) != p.end()) time = max(time, count_time(p[root->data], p, visited));
    time = max(time, count_time(root->left, p, visited));
    time = max(time, count_time(root->right, p, visited));
    return 1+time;
}
void find_parents(Node* root, unordered_map<int, Node*> &mp, unordered_map<int, int> &visited){
    visited[root->data] = 0;
    if(root->left != NULL){
        mp[root->left->data] = root;
        find_parents(root->left, mp, visited);
    }
    if(root->right != NULL) {
        mp[root->right->data] = root;
        find_parents(root->right, mp, visited);
    }
}
int minTime(Node* root, int target) {
    if(root==NULL) return 0;
    unordered_map<int, Node*> p;
    unordered_map<int, int> visited;
    find_parents(root, p, visited);
    if(root->data==target) return count_time(root, p, visited)-1;
    Node* t;
    if(p[target]->left!=NULL && p[target]->left->data == target) t = p[target]->left;
    else t = p[target]->right;
    return count_time(t, p, visited)-1;
}
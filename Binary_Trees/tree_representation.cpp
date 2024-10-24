#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *left, *right;
        int data;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }

        Node(Node* l, Node* r, int val){
            left = l;
            right = r;
            data = val;
        }

};
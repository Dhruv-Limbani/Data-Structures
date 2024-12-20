#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key, val;
    Node* prev, *next;
    Node(){
        key = -1;
        val = 0;
        prev = NULL;
        next = NULL;
    }
    Node(int k, int v){
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
    Node(int k, int v, Node* p, Node* n){
        key = k;
        val = v;
        prev = p;
        next = n;
    }
};

class LRUCache {
public:
    int cap, size;
    Node *head, *tail;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node();
        tail = new Node(-1, 0, head, NULL);
        head->next = tail;
    }
    void addNode(int key, int value){
        Node* temp = new Node(key, value, head, head->next);
        head->next->prev = temp;
        head->next = temp;
        mp[key] = temp;
    }
    void deleteNode(Node* temp){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        mp.erase(temp->key);
        delete temp;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        int val = mp[key]->val;
        deleteNode(mp[key]);
        addNode(key, val);
        return val;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            addNode(key, value);
            return;
        }
        if(size<cap){
            size++;
            addNode(key, value);
        }
        else{
            Node *temp = tail->prev;
            deleteNode(temp);
            addNode(key, value);
        }
    }
};
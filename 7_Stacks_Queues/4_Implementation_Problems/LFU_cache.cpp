#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key, val, freq;
    Node* prev, *next;
    Node(){
        key = -1;
        val = 0;
        freq = 0;
        prev = NULL;
        next = NULL;
    }
    Node(int k, int v, int f){
        key = k;
        val = v;
        freq = f;
        prev = NULL;
        next = NULL;
    }
    Node(int k, int v, int f, Node* p, Node* n){
        key = k;
        val = v;
        freq = f;
        prev = p;
        next = n;
    }
};
class lst{
    public:
    Node* head, *tail;
    lst(){
        head = new Node(); 
        tail = new Node(-1,0,0,head,NULL);
        head->next = tail;
    }
};
class LFUCache {
public:
    unordered_map<int, lst> freq_list;
    unordered_map<int, Node*> key_info;
    int size = 0, cap = 0, lf=1;
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    void addNode(int key, int val, int freq){
        Node* temp = new Node(key, val, freq, freq_list[freq].head, freq_list[freq].head->next);
        freq_list[freq].head->next->prev = temp;
        freq_list[freq].head->next = temp;
        key_info[key] = temp;
    }
    void deleteNode(Node* temp){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        key_info.erase(temp->key);
        delete temp;
    }
    bool isempty(int freq){
        return freq_list[freq].head->next==freq_list[freq].tail;
    }
    int get(int key) {
        if(key_info.find(key)==key_info.end()) return -1;
        int freq = key_info[key]->freq, val = key_info[key]->val;
        deleteNode(key_info[key]);
        if(freq==lf && isempty(freq)) lf++;
        addNode(key, val, freq+1);
        return val;
    }
    void put(int key, int value) {
        if(key_info.find(key)!=key_info.end()){
            int freq = key_info[key]->freq;
            deleteNode(key_info[key]);
            if(freq==lf && isempty(freq)) lf++;
            addNode(key, value, freq+1);
            return;
        }
        if(size==cap) deleteNode(freq_list[lf].tail->prev);
        else size++;
        addNode(key, value, 1);
        lf = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
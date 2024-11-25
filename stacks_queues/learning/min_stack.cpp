#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    long long int *arr, size, tp, min;
    MinStack() {
        arr = new long long int[30001];
        size = 0;
        tp = -1;
        min = long(INT_MAX);
    }
    
    void push(long long int val) {
        if(val<min){
            arr[++tp] = 2*val - min;
            min = val;
        }
        else arr[++tp] = val;
        size++;
    }
    void pop() {
        if(size==0) return;
        if(arr[tp]<min){
            min = 2*min-arr[tp];
        }
        tp--;
        size--;
    }
    
    int top() {
        if(tp>=0){
            if(arr[tp]<min) return min;
            else return arr[tp];
        } 
        return -1;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
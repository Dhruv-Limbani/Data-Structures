#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    long long int size,arr[30000],tp,min_val;
    MinStack() {
        size=0;
        tp=-1;
        min_val=0;
    }
    void push(long long int val) {
        if(size==0) min_val = val;
        if(val<min_val){
            long long int temp = min_val;
            min_val = val;
            val = 2*val - temp;
        }
        arr[++tp] = val;
        size++;
    }
    void pop() {
        if(size==0) return;
        else{
            if(arr[tp] < min_val) min_val = 2*min_val-arr[tp];
            tp--;
            size--;
            if(size==0) min_val=0;
        }
    }
    int top() {
        if(arr[tp] < min_val) return min_val;
        return arr[tp];
    }
    
    int getMin() {
        return min_val;
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
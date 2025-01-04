#include<bits/stdc++.h>
using namespace std;

// stack
vector<int> nextGreaterElements(vector<int>& nums) {
    int len = nums.size();
    stack<int> st;
    vector<int> ans(len, -1);
    int mx_ind = 0;
    for(int i=0; i<len; i++){
        if(nums[i]>nums[mx_ind]) mx_ind = i;
    }
    int i = (mx_ind+1)%len, j=len;
    while(j--){
        while(!st.empty() && nums[st.top()]<nums[i]){
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
        i = (i+1)%len;
    }
    return ans;
}

// monotonic stack
vector<int> nextGreaterElements(vector<int>& nums) {
    int len = nums.size();
    stack<int> st;
    vector<int> ans(len, -1);
    for(int i=2*len-1; i>=0; i--){
        while(!st.empty() && st.top()<=nums[i%len]) st.pop();
        if(!st.empty() && i<len) ans[i%len] = st.top();
        st.push(nums[i%len]);
    }
    return ans;
}
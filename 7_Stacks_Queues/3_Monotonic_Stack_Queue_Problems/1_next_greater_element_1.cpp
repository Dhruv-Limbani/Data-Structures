#include<bits/stdc++.h>
using namespace std;

// stack
vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    vector<int> ans(nums.size(),-1);
    for(int i=0; i<nums.size(); i++){
        while(!st.empty() && nums[st.top()]<nums[i]){
            ans[st.top()] = nums[i];
            st.pop();
        } 
        st.push(i);
    }
    return ans;
}

// monotonic stack
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    vector<int> ans(nums2.size(),-1);
    for(int i=nums2.size()-1; i>=0; i--){
        while(!st.empty() && st.top()<=nums2[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(nums2[i]);
    }
    return ans;
}


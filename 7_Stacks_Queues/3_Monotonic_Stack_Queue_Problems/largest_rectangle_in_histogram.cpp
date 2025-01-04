#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> ls(n,-1);
    stack<int> st;
    int mx = 0;
    for(int i=0; i<n; i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
            int h = heights[st.top()], w = i - ls[st.top()] - 1;
            st.pop();
            mx = max(mx, h*w);
        }
        if(!st.empty()) ls[i] = st.top();
        st.push(i);
    }
    while(!st.empty()){
        int h = heights[st.top()], w = n - ls[st.top()] - 1;
        st.pop();
        mx = max(mx, h*w);
    }
    return mx;
}
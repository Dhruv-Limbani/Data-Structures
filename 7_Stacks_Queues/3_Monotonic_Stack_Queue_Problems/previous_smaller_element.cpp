#include<bits/stdc++.h>
using namespace std;

// similar to Next Greater Element-1
// Monotonic Stack
vector<int> PSE(vector<int>& A) {
    stack<int> st;
    vector<int> ans(A.size(),-1);
    for(int i=0; i<A.size(); i++){
        while(!st.empty() && st.top()>=A[i]) st.pop();
        ans[i] = !st.empty()?st.top():-1;
        st.push(A[i]);
    }
    return ans;
}
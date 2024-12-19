#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dist_from_lse_nse(vector<int>& arr){
    stack<int> st1,st2;
    vector<pair<int,int>> ans(arr.size(), {-1,-1});
    for(int i=0; i<arr.size(); i++){
        while(!st1.empty() && arr[st1.top()]>=arr[i]) st1.pop();  // >= to avoid duplicates (next smaller element)
        if(!st1.empty()) ans[i].first = i-st1.top();
        else ans[i].first = i+1;
        st1.push(i);
    }
    for(int i=arr.size()-1; i>=0; i--){
        while(!st2.empty() && arr[st2.top()]>arr[i]) st2.pop();   // > to avoid duplicates (previous smaller or equal element)
        if(!st2.empty()) ans[i].second = st2.top()-i;
        else ans[i].second = (arr.size()-i);
        st2.push(i);
    }
    return ans;
}
int sumSubarrayMins(vector<int>& arr) {
    vector<pair<int,int>> dist = dist_from_lse_nse(arr);
    long sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += (long)dist[i].first*dist[i].second*arr[i];
    }
    return (int)(sum%(long)(1e9 + 7));
}
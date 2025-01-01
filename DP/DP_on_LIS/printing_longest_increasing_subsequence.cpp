#include<bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
    vector<int> dp(n, 1), prev(n,-1);
    for(int i=0; i<n; i++){
        for(int p=0; p<=i-1; p++){
            if(arr[p]<arr[i] && dp[i]<1+dp[p]){
                dp[i] = 1+dp[p];
                prev[i] = p;
            }
        }
    }
    int mx = 1, last_ind=0;
    for(int i=0; i<n; i++){
        if(dp[i]>mx){
            mx = dp[i];
            last_ind = i;
        }
    }
    vector<int> ans = {arr[last_ind]};
    while(prev[last_ind]!=-1){
        last_ind = prev[last_ind];
        ans.push_back(arr[last_ind]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
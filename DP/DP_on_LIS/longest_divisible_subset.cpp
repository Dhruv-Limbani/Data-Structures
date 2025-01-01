#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1), prev(n,-1);
    for(int i=0; i<n; i++){
        for(int p=0; p<=i-1; p++){
            if(arr[i]%arr[p]==0 && dp[i]<1+dp[p]) {
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
    return ans;
}
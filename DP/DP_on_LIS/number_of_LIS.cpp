#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& arr) {
    int n = arr.size(), mx = 1, ans=0;
    vector<int> dp(n, 1), ct(n,1);
    for(int i=0; i<n; i++){
        for(int p=0; p<=i-1; p++){
            if(arr[p]<arr[i]){
                if(dp[i]<1+dp[p]){
                    dp[i] = 1+dp[p];
                    ct[i] = ct[p];
                }
                else if(dp[i]==1+dp[p]) ct[i]+=ct[p];
            }
        }
        mx = max(mx, dp[i]);
    }
    for(int i=0; i<n; i++) if(dp[i]==mx) ans+=ct[i];
    return ans;
}
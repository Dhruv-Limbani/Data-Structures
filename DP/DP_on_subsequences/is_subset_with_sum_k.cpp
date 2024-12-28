#include<bits/stdc++.h>
using namespace std;

// memiozation
bool isSubsetSum(vector<int>& arr, vector<vector<int>>& dp, int i, int target){
    if(target==0) return true;
    if(i==0) return arr[i]==target;
    if(dp[i][target]!=-1) return dp[i][target];
    bool taken=false, not_taken;
    if(target>=arr[i]) taken = isSubsetSum(arr, dp, i-1, target-arr[i]);
    not_taken = isSubsetSum(arr, dp, i-1, target);
    return dp[i][target] = taken || not_taken;
}

// tabulation
bool isSubsetSum(vector<int>& arr, int target) {
    vector<vector<int>> dp(arr.size(), vector<int>(target+1,0));
    int n = arr.size();
    if(arr[0]<=target) dp[0][arr[0]] = 1;
    dp[0][0] = 1;
    for(int i=1; i<n; i++){
        dp[i][0]=1;
        for(int t=1; t<=target; t++){
            if(t-arr[i]>=0) dp[i][t] = dp[i-1][t-arr[i]];
            dp[i][t] = dp[i][t] || dp[i-1][t];
        }
    }
    return dp[n-1][target];
}

// space optimized
bool isSubsetSum(vector<int>& arr, int target) {
    vector<int> prev(target+1,0);
    int n = arr.size();
    if(arr[0]<=target) prev[arr[0]] = 1;
    prev[0] = 1;
    for(int i=1; i<n; i++){
        vector<int> curr(target+1,0);
        curr[0] = 1;
        for(int t=1; t<=target; t++){
            if(t-arr[i]>=0) curr[t] = prev[t-arr[i]];
            curr[t] = curr[t] || prev[t];
        }
        prev = curr;
    }
    return prev[target];
}

/*
    DP recurrence relation:
    SS[i][target] = SS[i-1][target] || SS[i-1][target-arr[i]] (if(target-arr[i]>=0))
*/
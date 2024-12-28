#include<bits/stdc++.h>
using namespace std;

int isSubsetSum(vector<int>& arr, vector<vector<int>>& dp, int i, int target){
    if(i==0){
        if(target==0 && arr[i]==0) return 2;
        if(target==0 || target==arr[i]) return 1;
        return 0;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int taken=0, not_taken=0;
    if(target>=arr[i]) taken = isSubsetSum(arr, dp, i-1, target-arr[i]);
    not_taken = isSubsetSum(arr, dp, i-1, target);
    return dp[i][target] = taken + not_taken;
}

int perfectSum(vector<int>& arr, int target) {
    vector<vector<int>> dp(arr.size(), vector<int>(target+1,-1));
    return isSubsetSum(arr, dp, arr.size()-1, target);
}
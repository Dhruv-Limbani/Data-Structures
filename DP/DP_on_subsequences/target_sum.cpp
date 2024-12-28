#include<bits/stdc++.h>
using namespace std;

int ways(vector<int>& arr, vector<vector<int>>& dp, int i, int target){
    if(i==0) {
        if(target==0 && arr[i]==0) return dp[i][target]=2;
        return dp[i][abs(target)] = (target-arr[i]==0) || (target+arr[i]==0);
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int plus=0, minus=0;
    plus = ways(arr, dp, i-1, abs(target-arr[i]));
    minus = ways(arr, dp, i-1, abs(target+arr[i]));
    return dp[i][target] = plus + minus;
}
int findTargetSumWays(vector<int>& nums, int target) {
    target = abs(target);
    int ct=0;
    for(auto it: nums) ct+=it;
    vector<vector<int>> dp(nums.size(), vector<int>(target+ct+1, -1));
    for(int i=0; i<nums.size(); i++){
        for(int t=0; t<=target+ct-nums[i]; t++){
            if(i==0) {
                if(t==0 && nums[i]==0) dp[i][t]=2;
                else dp[i][t] = (t-nums[i]==0) || (t+nums[i]==0);
                continue;
            }
            int plus=0, minus=0;
            plus = dp[i-1][abs(t-nums[i])];
            minus = dp[i-1][t+nums[i]];
            dp[i][t] = plus + minus;
        }
    }
    return dp[nums.size()-1][target];
}
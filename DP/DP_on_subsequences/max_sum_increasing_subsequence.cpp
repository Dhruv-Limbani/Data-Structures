#include<bits/stdc++.h>
using namespace std;

// same as longest increasing subsequence, the only change is take = arr[ind] + recursive call, instead of take = 1 + recursive call

// memiozation
int maxSumIS(vector<int>& arr, vector<vector<int>>& dp, int ind, int prev){
    if(ind>=arr.size()) return 0;
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    int not_take = maxSumIS(arr, dp, ind+1, prev), take=0;
    if(prev==-1 || arr[ind]>arr[prev]){
        take = arr[ind] + maxSumIS(arr, dp, ind+1, ind);
    }
    return dp[ind][prev+1] = max(take, not_take);
}
int maxSumIS(vector<int>& arr) {
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size()+1, -1));
    return maxSumIS(arr, dp, 0, -1);
}

// tabulation
int maxSumIS(vector<int>& nums) {
    vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1,0));
    for(int ind=nums.size()-1; ind>=0; ind--){
        for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
            int not_take = dp[ind+1][prev_ind+1], take = 0;
            if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                take = nums[ind] + dp[ind+1][ind+1];
            }
            dp[ind][prev_ind+1] = max(take, not_take);
        }
    }
    return dp[0][0];
}

// space optimized
int maxSumIS(vector<int>& nums) {
    vector<int> prev(nums.size()+1,0);
    for(int ind=nums.size()-1; ind>=0; ind--){
        vector<int> curr=prev;
        for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
            int not_take = prev[prev_ind+1], take = 0;
            if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                take = nums[ind] + prev[ind+1];
            }
            curr[prev_ind+1] = max(take, not_take);
        }
        prev = curr;
    }
    return prev[0];
}

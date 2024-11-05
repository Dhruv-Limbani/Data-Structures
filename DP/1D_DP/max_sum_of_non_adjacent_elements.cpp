#include<bits/stdc++.h>
using namespace std;

// recursive
int amt(vector<int>& nums, int n){
    if(n<0) return 0;
    return max(nums[n] + amt(nums, n-2), amt(nums, n-1));
}
int rob(vector<int>& nums) {
    return amt(nums, nums.size()-1);
}

//DP

// recursion + Memiozation/Tabulation

int amt(vector<int>& nums, int n, vector<int> &dp){
    if(n<1) return 0;
    if(dp[n]!=-1) return dp[n];
    dp[n] = max(nums[n-1] + amt(nums, n-2, dp), amt(nums, n-1, dp));
    return dp[n];
}
int rob(vector<int>& nums) {
    vector<int> dp(nums.size()+1,-1);
    return amt(nums, nums.size(), dp);
}

// iterative + Memiozation/Tabulation

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1,0);
    for(int i=1; i<=n; i++){
        dp[i] = max(nums[i-1],dp[i-1]);
        if(i>2) dp[i] = max(dp[i], nums[i-1] + dp[i-2]);
    }
    return dp[n];
}

// space optimized

int rob(vector<int>& nums) {
    int n = nums.size();
    int last=nums[0], secondLast=0;
    for(int i=1; i<n; i++){
        int temp = max(last, nums[i] + secondLast);
        secondLast = last;
        last = temp;
    }
    return last;
}

/*
    DP relation
    dp[i] = maximum sum till ith element
    dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
*/
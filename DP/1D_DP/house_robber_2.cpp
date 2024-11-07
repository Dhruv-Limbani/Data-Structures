#include<bits/stdc++.h>
using namespace std;

// recursive + memiozation/tabulation
int amt(vector<int>& nums, vector<int> &dp, int s, int i){
    if(i<s) return 0;
    if(dp[i]!=-1) return dp[i];
    dp[i] = max(nums[i] + amt(nums, dp, s, i-2), amt(nums, dp, s, i-1));
    return dp[i];
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,-1);
    if(n==1) return nums[0];
    int a = amt(nums,dp,0,n-2);
    for(int i=0; i<n; i++) dp[i] = -1;
    int b = amt(nums,dp,1,n-1);
    return max(a,b);
}

// iterative + memiozation/tabulation

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> dp(n+1,0);
    for(int i=1; i<=n-1; i++){
        int pick = nums[i-1];
        if(i>2) pick += dp[i-2];
        int notpick = dp[i-1];
        dp[i] = max(pick,notpick);
    }
    int a = dp[n-1];
    for(int i=0; i<=n; i++) dp[i] = 0;
    for(int i=2; i<=n; i++){
        int pick = nums[i-1];
        if(i>3) pick += dp[i-2];
        int notpick = dp[i-1];
        dp[i] = max(pick,notpick);
    }
    int b = dp[n];
    return max(a,b);
}

// space optimized

int rob(vector<int>& nums) {
    int n = nums.size();
    int last = nums[0], second_last = 0;
    for(int i=1; i<n-1; i++){
        int temp = max(nums[i] + second_last,last);
        second_last = last;
        last = temp;
    }
    if(n<2) return last;
    int a=last;
    last = nums[1], second_last = 0;
    for(int i=2; i<n; i++){
        int temp = max(nums[i] + second_last,last);
        second_last = last;
        last = temp;
    }
    int b = last;
    return max(a,b);
}

/*
    DP recurrence relation
    dp[i] = maximum sum till ith element
    dp[i] = max(nums[i] + dp[i-2], dp[i-1]);

    ans1 = run algo from 1st element to second last element;
    ans2 = run algo from 2nd element to last element;
    final ans = max(ans1,ans2);
*/
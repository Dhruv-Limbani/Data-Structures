#include <bits/stdc++.h>
using namespace std;

// memiozation
int max_profit(vector<int>& val, vector<int>& wt, vector<vector<int>> &dp, int i, int capacity){
    if(i==0){
        if(wt[0]<=capacity) return dp[i][capacity] = val[0]*(capacity/wt[0]);
        return dp[i][capacity] = 0;
    }
    if(dp[i][capacity]!=-1) return dp[i][capacity];
    int take=0, not_take = max_profit(val, wt, dp, i-1, capacity);
    if(capacity>=wt[i]) take = val[i] + max_profit(val, wt, dp, i, capacity-wt[i]);
    return dp[i][capacity] = max(take, not_take);
}

// tabulation
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<vector<int>> dp(wt.size(), vector<int>(capacity+1,-1));
    // return max_profit(val, wt, dp, wt.size()-1, capacity);
    int n = wt.size();
    for(int i=0; i<n; i++){
        for(int c=0; c<=capacity; c++){
            if(i==0){
                if(wt[0]<=c) dp[i][c] = val[0]*(c/wt[0]);
                else dp[i][c] = 0;
                continue;
            }
            int take=0, not_take = dp[i-1][c];
            if(c>=wt[i]) take = val[i] + dp[i][c-wt[i]];
            dp[i][c] = max(take, not_take);
        }
    }
    return dp[n-1][capacity];
}

// space optimized
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<int> prev(capacity+1,-1);
    int n = wt.size();
    for(int i=0; i<n; i++){
        vector<int> curr(capacity+1,-1);
        for(int c=0; c<=capacity; c++){
            if(i==0){
                if(wt[0]<=c) curr[c] = val[0]*(c/wt[0]);
                else curr[c] = 0;
                continue;
            }
            int take=0, not_take = prev[c];
            if(c>=wt[i]) take = val[i] + curr[c-wt[i]];
            curr[c] = max(take, not_take);
        }
        prev = curr;
    }
    return prev[capacity];
}
#include<bits/stdc++.h>
using namespace std;

// memiozation
int ways(vector<int>& arr, vector<vector<int>>& dp, int i, int target){
    if(i==0) return dp[i][target] = (target%arr[i] == 0);
    if(dp[i][target]!=-1) return dp[i][target];
    int taken=0, not_taken=0;
    if(target>=arr[i]) taken = ways(arr, dp, i, target-arr[i]);
    not_taken = ways(arr, dp, i-1, target);
    return dp[i][target] = taken + not_taken;
}

// tabulation
int change(int amount, vector<int>& coins) {
    vector<vector<long double>> dp(coins.size(), vector<long double>(amount+1,-1));
    for(int i=0; i<coins.size(); i++){
        for(int a=0; a<=amount; a++){
            if(i==0){
                dp[i][a] = (a%coins[i]==0);
                continue;
            }
            long double taken=0, not_taken=0;
            if(a>=coins[i]) taken = dp[i][a-coins[i]];
            not_taken = dp[i-1][a];
            dp[i][a] = taken + not_taken;
        }
    }
    return (int)dp[coins.size()-1][amount];
}

// space optimization
int change(int amount, vector<int>& coins) {
    vector<long double> prev(amount+1,-1);
    for(int i=0; i<coins.size(); i++){
        vector<long double> curr(amount+1,-1);
        for(int a=0; a<=amount; a++){
            if(i==0){
                curr[a] = (a%coins[i]==0);
                continue;
            }
            long double taken=0, not_taken=0;
            if(a>=coins[i]) taken = curr[a-coins[i]];
            not_taken = prev[a];
            curr[a] = taken + not_taken;
        }
        prev = curr;
    }
    return (int)prev[amount];
}
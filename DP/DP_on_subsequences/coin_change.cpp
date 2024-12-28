#include <bits/stdc++.h>
using namespace std;

// 1D DP
// memiozation
int min_coins(vector<int>& coins, vector<int>& dp, int amount){
    if(dp[amount]!=-1) return dp[amount];
    dp[amount] = INT_MAX;
    for(auto it: coins){
        if(amount==it) return dp[amount]=1;
        if(amount>it) dp[amount] = min(dp[amount], min_coins(coins, dp, amount-it));
    }
    if(dp[amount]==INT_MAX) return dp[amount];
    return dp[amount]+=1;
}
//tabulation
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=amount; i++){
        dp[i] = INT_MAX;
        for(auto it: coins){
            if(i==it){
                dp[i]=0;
                break;
            }
            else if(i>it) dp[i] = min(dp[i],dp[i-it]);
        }
        if(dp[i]!=INT_MAX) dp[i]+=1;
    }
    if(dp[amount]==INT_MAX) return -1;
    return dp[amount];
}

/*
dp relation: min_coins(amount) = min(min_coins(amount-coins[i])) for all i such that amount>coins[i]
                               = 1 if any i such that coins[i]==amount
*/                              

//using subset sum

//memiozation
int min_coins(vector<int>& coins, vector<vector<int>>& dp, int i, int amount){
    if(i==0){
        if(amount%coins[i]==0) return dp[i][amount] = amount/coins[i];
        else return dp[i][amount] = INT_MAX;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int taken=INT_MAX, not_taken = min_coins(coins, dp, i-1, amount);
    if(amount>=coins[i]) taken = min_coins(coins, dp, i, amount-coins[i]);
    if(taken!=INT_MAX) taken+=1;
    return dp[i][amount] = min(taken, not_taken);
}

//tabulation
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(coins.size(), vector<int>(amount+1,INT_MAX));
    for(int i=0; i<coins.size(); i++){
        for(int a=0; a<=amount; a++){
            if(i==0){
                if(a%coins[i]==0) dp[i][a] = a/coins[i];
                else dp[i][a] = INT_MAX;
                continue;
            }
            int taken=INT_MAX, not_taken = dp[i-1][a];
            if(a>=coins[i]) taken = dp[i][a-coins[i]];
            if(taken!=INT_MAX) taken+=1;
            dp[i][a] = min(taken, not_taken);
        }
    }
    if(dp[n-1][amount]==INT_MAX) return -1;
    return dp[n-1][amount];
}

// space optimized
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prev(amount+1,INT_MAX);
    for(int i=0; i<coins.size(); i++){
        vector<int> curr(amount+1,INT_MAX);
        for(int a=0; a<=amount; a++){
            if(i==0){
                if(a%coins[i]==0) curr[a] = a/coins[i];
                else curr[a] = INT_MAX;
                continue;
            }
            int taken=INT_MAX, not_taken = prev[a];
            if(a>=coins[i]) taken = curr[a-coins[i]];
            if(taken!=INT_MAX) taken+=1;
            curr[a] = min(taken, not_taken);
        }
        prev=curr;
    }
    if(prev[amount]==INT_MAX) return -1;
    return prev[amount];
}
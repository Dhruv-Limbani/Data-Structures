#include <bits/stdc++.h>
using namespace std;

// memiozation
int mp(vector<int>& prices, vector<vector<int>> &dp, int i, int s){
    if(i==prices.size()) return 0;
    if(dp[i][s]!=-1) return dp[i][s];
    int ignore = mp(prices, dp, i+1, s), buy = 0, sell = 0;
    if(s) sell = prices[i] + mp(prices, dp, i+1, 0);
    else buy = -prices[i] + mp(prices, dp, i+1, 1);
    dp[i][s] = max(ignore, max(buy, sell));
    return dp[i][s];
}
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
    return mp(prices, dp, 0, 0);
}

// tabulation
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    // return mp(prices, dp, 0, 0);
    int n = prices.size();
    dp[n-1][0] = 0;
    dp[n-1][1] = prices[n-1];
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=1; j++){
            int ignore = dp[i+1][j], buy = 0, sell = 0;
            if(j) sell = prices[i] + dp[i+1][0];
            else buy = -prices[i] + dp[i+1][1];
            dp[i][j] = max(ignore, max(buy, sell));
        }
    }
    return dp[0][0];
}

// space optimized
int maxProfit(vector<int>& prices) {
    vector<int> prev(2, 0);
    // return mp(prices, dp, 0, 0);
    int n = prices.size();
    prev[0] = 0;
    prev[1] = prices[n-1];
    for(int i=n-2; i>=0; i--){
        vector<int> curr(2, 0);
        for(int j=0; j<=1; j++){
            int ignore = prev[j], buy = 0, sell = 0;
            if(j) sell = prices[i] + prev[0];
            else buy = -prices[i] + prev[1];
            curr[j] = max(ignore, max(buy, sell));
        }
        prev = curr;
    }
    return prev[0];
}
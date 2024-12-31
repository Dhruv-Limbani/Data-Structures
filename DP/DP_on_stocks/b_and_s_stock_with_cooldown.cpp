#include <bits/stdc++.h>
using namespace std;

// memiozation
int mp(vector<int>& prices, vector<vector<int>> &dp, int i, int s){
    if(i>=prices.size()) return 0;
    if(dp[i][s]!=-1) return dp[i][s];
    int ignore = mp(prices, dp, i+1, s), buy = 0, sell = 0;
    if(s) sell = prices[i] + mp(prices, dp, i+2, 0);
    else buy = -prices[i] + mp(prices, dp, i+1, 1);
    dp[i][s] = max(ignore, max(buy, sell));
    return dp[i][s];
}
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
    return mp(prices, dp, 0, 0);
}
#include <bits/stdc++.h>
using namespace std;

// memiozation
int mp(vector<int>& prices, vector<vector<int>> &dp, int i, int s, int fee){
    if(i==prices.size()) return 0;
    if(dp[i][s]!=-1) return dp[i][s];
    int ignore = mp(prices, dp, i+1, s, fee), buy = 0, sell = 0;
    if(s) sell = prices[i] - fee + mp(prices, dp, i+1, 0, fee);
    else buy = -prices[i] + mp(prices, dp, i+1, 1, fee);
    dp[i][s] = max(ignore, max(buy, sell));
    return dp[i][s];
}
int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
    return mp(prices, dp, 0, 0, fee);
}
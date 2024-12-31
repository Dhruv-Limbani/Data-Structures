#include <bits/stdc++.h>
using namespace std;

// memiozation
int mp(vector<int>& prices, vector<vector<vector<int>>> &dp, int i, int s, int t){
    if(i==prices.size()) return 0;
    if(dp[i][s][t]!=-1) return dp[i][s][t];
    if(t==0) return dp[i][s][t] = 0;
    int ignore = mp(prices, dp, i+1, s, t), buy = 0, sell = 0;
    if(s) sell = prices[i] + mp(prices, dp, i+1, 0, t-1);
    else buy = -prices[i] + mp(prices, dp, i+1, 1, t);
    dp[i][s][t] = max(ignore, max(buy, sell));
    return dp[i][s][t];
}
int maxProfit(vector<int>& prices) {
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
    return mp(prices, dp, 0, 0, 2);
}
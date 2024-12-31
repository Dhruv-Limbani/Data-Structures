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

// tabulation
int maxProfit(vector<int>& prices) {
    vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));
    int n = prices.size();
    for(int i=n-1; i>=0; i--){
        for(int b=0; b<=1; b++){
            for(int t=1; t<=2; t++){
                int ignore = dp[i+1][b][t], buy = 0, sell = 0;
                if(b) sell = prices[i] +  dp[i+1][0][t-1];
                else buy = -prices[i] + dp[i+1][1][t];
                dp[i][b][t] = max(ignore, max(buy, sell));
            }
        }
    }
    return dp[0][0][2];
}

// space optimized
int maxProfit(vector<int>& prices) {
    vector<vector<int>> prev(2, vector<int>(3, 0));
    int n = prices.size();
    for(int i=n-1; i>=0; i--){
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for(int b=0; b<=1; b++){
            for(int t=1; t<=2; t++){
                int ignore = prev[b][t], buy = 0, sell = 0;
                if(b) sell = prices[i] +  prev[0][t-1];
                else buy = -prices[i] + prev[1][t];
                curr[b][t] = max(ignore, max(buy, sell));
            }
        }
        prev = curr;
    }
    // return mp(prices, dp, 0, 0, 2);
    return prev[0][2];
}
#include <bits/stdc++.h>
using namespace std;

// expressed as unbounded knapsack, 2D DP Array approach
// memiozation
int max_val(vector<int> &price, vector<vector<int>> &dp, int i, int len){
    if(i-1==0){
        if(i<=len) return dp[i][len] = price[i-1]*(len/i);
        return dp[i][len] = 0;
    }
    if(dp[i][len]!=-1) return dp[i][len];
    int cut = 0, not_cut = max_val(price, dp, i-1, len);
    if(i<=len) cut = price[i-1] + max_val(price, dp, i, len-i);
    return dp[i][len] = max(cut, not_cut);
}
int cutRod(vector<int> &price) {
    int n = price.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    return max_val(price, dp, n, n);
}

// 1D dp approach

// memiozation
int max_val(vector<int> &price, vector<int> &dp, int len){
    if(dp[len]!=-1) return dp[len];
    dp[len] = price[len-1];
    for(int i=len-1; i>=len/2 + len%2; i--){
        dp[len] = max(dp[len], max_val(price, dp, len-i) + max_val(price, dp, i));
    }
    return dp[len];
}

// tabulation
int cutRod(vector<int> &price) {
    int n = price.size();
    vector<int> dp(n+1,-1);
    for(int i=1; i<=n; i++){
        dp[i] = price[i-1];
        for(int j=i-1; j>=i/2 + i%2; j--){
            dp[i] = max(dp[i], dp[i-j] + dp[j]);
        }
    }
    return dp[n];
}

#include<bits/stdc++.h>
using namespace std;

// recursive + memiozation

int solve(vector<vector<int>> &dp, int m, int n){
    if(m==0) return 1;
    if(n==0) return 1;
    if(dp[m][n]!=-1) return dp[m][n];
    dp[m][n] = solve(dp, m, n-1) + solve(dp, m-1, n);
    return dp[m][n];
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return solve(dp, m-1, n-1);
}

// iterative + memiozation

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n, 1));
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}

// space optimized

int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    while(--m){
        for(int i=1; i<n; i++){
            if(i==1) dp[i] = dp[i] + 1;
            else dp[i] += dp[i-1];
        }
    }
    return dp[n-1];
}

/*
    DP recurrence relation:
    ways[i][j] = ways[i-1][j] (coming from top) + ways[i][j-1] (coming from right);
*/
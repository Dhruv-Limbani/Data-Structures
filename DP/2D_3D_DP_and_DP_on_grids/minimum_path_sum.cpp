#include<bits/stdc++.h>
using namespace std;


// memiozation
int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
    if(i<0 || j<0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0 && j==0) return dp[i][j] = grid[i][j];
    return dp[i][j] = grid[i][j] + min(solve(grid, dp, i-1, j), solve(grid, dp, i, j-1)); 
}
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return solve(grid, dp, m-1, n-1);
}

// tabulation
int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size(), n = grid[0].size();
       vector<vector<int>> dp(m,vector<int>(n,-1)); 
       for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                int temp = INT_MAX;
                if(i!=0) temp = min(temp, dp[i-1][j]);
                if(j!=0) temp = min(temp, dp[i][j-1]);
                dp[i][j] = grid[i][j] + temp;
            }
        }
       }
       return dp[m-1][n-1];
}

// space optimized
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n,0);
    for(int i=0; i<m; i++){
    dp[0] += grid[i][0];
    for(int j=1; j<n; j++){
        if(i==0){
            dp[j] = (grid[i][j] + dp[j-1]);  
        }
        else{
            dp[j] = (grid[i][j] + min(dp[j-1],dp[j]));
        }
    }
    }
    return dp[n-1];
}

/*
    DP recurrence relation : sum(i,j) = grid(i,j) + min(sum(i-1,j), sum(i,j-1))
*/
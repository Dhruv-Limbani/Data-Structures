#include<bits/stdc++.h>
using namespace std;

// recursive + memiozation

int solve(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j){
    if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0 && j==0) return 1;
    dp[i][j] = solve(obstacleGrid, dp, i, j-1) + solve(obstacleGrid, dp, i-1, j);
    return dp[i][j];
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return solve(obstacleGrid, dp, m-1, n-1);
}

// iterative + memiozation

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    dp[0][0] = 1*(!obstacleGrid[0][0]);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(obstacleGrid[i][j]==1) continue;
            if(j!=0) dp[i][j] += dp[i][j-1]*(!obstacleGrid[i][j-1]);
            if(i!=0) dp[i][j] += dp[i-1][j]*(!obstacleGrid[i-1][j]);
        }
    }
    return dp[m-1][n-1];
}

// space optimized

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> dp(n,0);
    dp[0] = 1*(!obstacleGrid[0][0]);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(obstacleGrid[i][j]==1){
                dp[j]=0;
                continue;
            }
            if(j!=0) dp[j] += dp[j-1];
        }
    }
    return dp[n-1];
}

/*
    Key idea:
    ways[i][j] = ways[i-1][j] (coming from top, if (i-1,j) is not an obstacle) 
                + ways[i][j-1] (coming from right, if (i,j-1) is not an obstacle);
*/
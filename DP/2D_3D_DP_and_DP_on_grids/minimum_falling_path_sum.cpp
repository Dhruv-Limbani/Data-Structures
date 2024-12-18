#include<bits/stdc++.h>
using namespace std;


// memiozation - 1
int min_sum(vector<vector<int>>& matrix, vector<vector<int>>& dp, int n, int i, int j){
    if(j<0 || j>=n) return INT_MAX;
    if(i==0) return dp[i][j] = matrix[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==n-1){
        int mn = INT_MAX;
        for(int k=0; k<n; k++){
            dp[i][k] = matrix[i][k] + min(min_sum(matrix, dp, n, i-1, k), min(min_sum(matrix, dp, n, i-1, k-1),min_sum(matrix, dp, n, i-1, k+1)));
            mn = min(dp[i][k], mn);
        }
        return mn;
    }
    else return dp[i][j] = matrix[i][j] + min(min_sum(matrix, dp, n, i-1, j), min(min_sum(matrix, dp, n, i-1, j-1),min_sum(matrix, dp, n, i-1, j+1)));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(), mn = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n,-1));
    return min_sum(matrix, dp, n, n-1, n-1);
}


// memiozation - 2

int min_sum(vector<vector<int>>& matrix, vector<vector<int>>& dp, int n, int i, int j){
    if(j<0 || j>=n) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0) return dp[i][j] = matrix[i][j];
    int up = min_sum(matrix, dp, n, i-1, j);
    int left_diagonal = min_sum(matrix, dp, n, i-1, j-1);
    int right_diagonal = min_sum(matrix, dp, n, i-1, j+1);
    return dp[i][j] = matrix[i][j] + min(up, min(left_diagonal, right_diagonal));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(), mn = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n,-1));
    for(int k=0; k<n; k++){
        mn = min(mn, min_sum(matrix, dp, n, n-1, k));
    }
    return mn;
}

// tabulation
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(), mn = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0) dp[i][j] = matrix[i][j];
            else{
                dp[i][j] = dp[i-1][j];
                if(j!=0) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                if(j!=n-1) dp[i][j] = min(dp[i][j],dp[i-1][j+1]);
                dp[i][j] += matrix[i][j];
            }
            if(i==n-1) mn = min(dp[i][j], mn);
        }
    }
    return mn;
}

// space optimized
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(), mn = INT_MAX;
    vector<int> prev(n,-1);
    for(int i=0; i<n; i++){
        vector<int> curr(n,-1);
        for(int j=0; j<n; j++){
            if(i==0) curr[j] = matrix[i][j];
            else{
                curr[j] = prev[j];
                if(j!=0) curr[j] = min(curr[j], prev[j-1]);
                if(j!=n-1) curr[j] = min(curr[j], prev[j+1]);
                curr[j] += matrix[i][j];
            }
            if(i==n-1) mn = min(mn, curr[j]);
        }
        prev = curr;
    }
    return mn;
}

/*
    DP Recurrence Relation:
    min_sum(i,j) = matrix(i,j) + min(min_sum(i-1, j-1), min_sum(i-1,j), min(sum(i-1,j+1)));
    min_sum_last = min(min_sum(i,j)) for i = n-1 and j = 0 to n-1
*/
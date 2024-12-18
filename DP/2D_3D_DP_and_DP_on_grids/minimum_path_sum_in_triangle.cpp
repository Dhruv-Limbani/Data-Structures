#include<bits/stdc++.h>
using namespace std;

// memiozation
int solve(vector<vector<int>>& triangle, vector<vector<int>> &dp, int i, int j){
    if(i==0 && j==0) return dp[i][j] = triangle[i][j];
    if(i<j || j<0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==triangle.size()-1){
        int mn = INT_MAX;
        for(int k=0; k<=i; k++){
            dp[i][k] = triangle[i][k] + min(solve(triangle, dp, i-1, k-1), solve(triangle, dp, i-1, k));
            mn = min(mn, dp[i][k]);
        }
        return mn;
    }
    else return dp[i][j] = triangle[i][j] + min(solve(triangle, dp, i-1, j-1), solve(triangle, dp, i-1, j));
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solve(triangle, dp, n-1, n-1);
}

// tabulation
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size(), mn = INT_MAX;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(i==0 && j==0) dp[i][j] = triangle[0][0];
            else if(i==j) dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            else{
                int temp = dp[i-1][j];
                if(j!=0) temp = min(temp, dp[i-1][j-1]);
                dp[i][j] = triangle[i][j] + temp;
            } 
            if(i==n-1) mn = min(mn, dp[i][j]);
        }
    }
    return mn;
}

// space optimized
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size(), mn = INT_MAX;
    vector<int> dp(n,0);
    for(int i=0; i<n; i++){
        vector<int>dp1(n,0);
        for(int j=0; j<=i; j++){
            if(i+j==0) dp1[j] = triangle[i][j];
            else if(i==j) dp1[j] = triangle[i][j] + dp[j-1];
            else{
                int temp = dp[j];
                if(j!=0) temp = min(temp, dp[j-1]);
                dp1[j] = triangle[i][j] + temp;
            }
            if(i==n-1) mn = min(mn, dp1[j]);
        }
        dp = dp1;
    }
    return mn;
}

/*
    DP Recurrence Relation:
    min_sum(i,j) = triangle(i,j) + min(min_sum(i-1, j-1), min_sum(i-1,j));
    min_sum_last = min(min_sum(i,j)) for i = n-1 and j = 0 to n-1
*/
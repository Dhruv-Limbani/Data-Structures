#include<bits/stdc++.h>
using namespace std;

// recursive + memiozation
int solve(vector<vector<int>> &points, vector<vector<int>> &dp, int n, int i)
{
    if(n<0) return 0;
    if(dp[n][i]!=-1) return dp[n][i];
    dp[n][0] = points[n][0] + max(solve(points, dp, n-1, 1), solve(points, dp, n-1, 2));
    dp[n][1] = points[n][1] + max(solve(points, dp, n-1, 0), solve(points, dp, n-1, 2));
    dp[n][2] = points[n][2] + max(solve(points, dp, n-1, 0), solve(points, dp, n-1, 1));
    return dp[n][i];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(3,-1));
    return max(solve(points, dp, n-1, 0), max(solve(points, dp, n-1, 1), solve(points, dp, n-1, 2)));
}


// iterative + memiozation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(3,-1));
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    for(int i=1; i<n; i++){
        dp[i][0] = points[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = points[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = points[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }
    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}

// space optimized
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int l0 = points[0][0], l1 = points[0][1], l2 = points[0][2];
    for(int i=1; i<n; i++){
        int temp0=l0, temp1=l1, temp2=l2;
        l0 = points[i][0] + max(temp1, temp2);
        l1 = points[i][1] + max(temp0, temp2);
        l2 = points[i][2] + max(temp0, temp1);
    }
    return max(l0, max(l1, l2));
}

/*
    Key Idea : max(day n) = max(
                                0th activity(day n) + max(1st activity(day n-1), 2nd activity(day n-1)),
                                1st activity(day n) + max(0th activity(day n-1), 2nd activity(day n-1)),
                                2nd activity(day n) + max(0th activity(day n-1), 1st activity(day n-1))
                            )

    TC: O(n)
    SC: O(1)
*/
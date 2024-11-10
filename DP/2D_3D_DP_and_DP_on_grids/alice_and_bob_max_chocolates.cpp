#include <bits/stdc++.h> 
using namespace std;

// memorization
int max_chocos(int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>>& dp, int i, int j1, int j2){
    if(j1<0 || j2<0 || j1>=c || j2>=c) return INT_MIN;
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    if(i==r-1){
        if(j1==j2) return dp[i][j1][j2] = grid[i][j1];
        else return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
    }
    int ans = INT_MIN;
    for(int a=-1; a<=1; a++){
        for(int b=-1; b<=1; b++){
            ans = max(ans, max_chocos(r, c, grid, dp, i+1, j1+a, j2+b));
        }
    }
    if(j1==j2) return dp[i][j1][j2] = grid[i][j1] + ans;
    else return dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + ans;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) { 
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return max_chocos(r, c, grid, dp, 0, 0, c-1);
}

// tabulation
int maximumChocolates(int r, int c, vector<vector<int>> &grid) { 
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    for(int i=r-1; i>=0; i--){
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){
                if(i==r-1){
                    if(j1==j2) dp[i][j1][j2] = grid[i][j1];
                    else dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                }
                else{
                    int temp = INT_MIN;
                    for(int a=-1; a<=1; a++){
                        for(int b=-1; b<=1; b++){
                            if(j1+a<0 || j1+a>=c || j2+b<0 || j2+b>=c) continue;
                            temp = max(temp, dp[i+1][j1+a][j2+b]);
                        }
                    }
                    if(j1==j2) dp[i][j1][j2] = temp + grid[i][j1];
                    else dp[i][j1][j2] = temp + grid[i][j1] + grid[i][j2];
                }
            }
        }
    }
    return dp[0][0][c-1];
}

// space optimized
int maximumChocolates(int r, int c, vector<vector<int>> &grid) { 
    vector<vector<int>> prev(c, vector<int>(c, -1));
    for(int i=r-1; i>=0; i--){
        vector<vector<int>> curr(c, vector<int>(c, -1));
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){
                if(i==r-1){
                    if(j1==j2) curr[j1][j2] = grid[i][j1];
                    else curr[j1][j2] = grid[i][j1] + grid[i][j2];
                }
                else{
                    int temp = INT_MIN;
                    for(int a=-1; a<=1; a++){
                        for(int b=-1; b<=1; b++){
                            if(j1+a<0 || j1+a>=c || j2+b<0 || j2+b>=c) continue;
                            temp = max(temp, prev[j1+a][j2+b]);
                        }
                    }
                    if(j1==j2) curr[j1][j2] = temp + grid[i][j1];
                    else curr[j1][j2] = temp + grid[i][j1] + grid[i][j2];
                }
            }
        }
        prev = curr;
    }
    return prev[0][c-1];
}

/*
    Recurrence Relation
    max_chocos(i,j1,j2) : max chocolates collected from ith row till the end, when alice starts at position j1 and bob starts at j2
    = 3 options for alice to move, and 3 options for bob to move, (in total 9 combinations)
    = (i+1,j1-1,j2-1) + (i+1,j1-1,j2) + (i+1, j1-1, j2+1), (i+1,j1,j2-1) + (i+1,j1,j2) + (i+1, j1, j2+1), (i+1,j1+1,j2-1) + (i+1,j1+1,j2) + (i+1, j1+1, j2+1)

    at any case, if j1==j2, we only return grid[i][j1] since chocolates can be picked up by only one person
    
*/
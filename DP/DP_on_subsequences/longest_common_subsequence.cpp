#include<bits/stdc++.h>
using namespace std;

// memiozation
int LCS(string text1, string text2, vector<vector<int>> &dp, int ind1, int ind2){
    if(ind1<0 || ind2<0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(text1[ind1]==text2[ind2]) return dp[ind1][ind2] = 1 + LCS(text1, text2, dp, ind1-1, ind2-1);
    else return dp[ind1][ind2] = max(LCS(text1, text2,dp, ind1, ind2-1), LCS(text1, text2,dp, ind1-1, ind2));
}

// tabulation
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
    // return LCS(text1, text2, dp, text1.size()-1, text2.size()-1);
    int n1 = text1.size(), n2 = text2.size();
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            int c=0, u=0, l=0;
            if(i>0 && j>0) c = dp[i-1][j-1];
            if(i>0) u = dp[i-1][j];
            if(j>0) l = dp[i][j-1];
            if(text1[i]==text2[j]) dp[i][j] = 1 + c;
            else dp[i][j] = max(u,l);
        }
    }
    return dp[n1-1][n2-1];
}

// space optimized
int longestCommonSubsequence(string text1, string text2) {
    vector<int> prev(text2.size(), 0);
    // return LCS(text1, text2, dp, text1.size()-1, text2.size()-1);
    int n1 = text1.size(), n2 = text2.size();
    for(int i=0; i<n1; i++){
        vector<int> curr = prev;
        for(int j=0; j<n2; j++){
            int c=0, u=0, l=0;
            if(i>0 && j>0) c = prev[j-1];
            if(i>0) u = prev[j];
            if(j>0) l = curr[j-1];
            if(text1[i]==text2[j]) curr[j] = 1 + c;
            else curr[j] = max(u,l);
        }
        prev = curr;
    }
    return prev[n2-1];
}

/*
    Recurrence relation:
    LCS(s1(0..i), s2(0..j)) = 1 + LCS(s1(0..i-1), s2(0..j-1)) if(s1[i]==s2[j])
                            = max(LCS(s1(0..i-1), s2(0..j)), LCS(s1(0..i), s2(0..j-1)))
*/
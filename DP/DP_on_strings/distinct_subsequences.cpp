#include <bits/stdc++.h>
using namespace std;

// memiozation
int numDistinct(string s, string t, vector<vector<double long>> &dp, int idxs, int idxt){
    if(idxt<0) return 1;
    if(idxs<0) return 0;
    if(dp[idxs][idxt]!=-1) return dp[idxs][idxt];
    dp[idxs][idxt] = numDistinct(s, t, dp, idxs-1,idxt);
    if(s[idxs]==t[idxt]) dp[idxs][idxt] += numDistinct(s, t, dp, idxs-1, idxt-1);
    return dp[idxs][idxt];
}

// tabulation
int numDistinct(string s, string t) {
    int n1 = s.size(), n2 = t.size();
    vector<vector<double long>> dp(n1+1, vector<double long>(n2+1, 0));
    for(int i=0; i<=n1; i++) dp[i][0] = 1;
    for(int j=1; j<=n2; j++) dp[0][j] = 0;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            dp[i][j] = dp[i-1][j];
            if(s[i-1]==t[j-1]) dp[i][j] += dp[i-1][j-1];
        }
    }
    return (int)dp[n1][n2];
}

// space optimized
int numDistinct(string s, string t) {
    int n1 = s.size(), n2 = t.size(), mod = 1e9+7;
    vector<int> prev(n2+1, 0);
    prev[0] = 1;
    for(int i=1; i<=n1; i++){
        vector<int> curr(n2+1, 0);
        curr[0] = 1;
        for(int j=1; j<=n2; j++){
            curr[j] = prev[j] % mod;
            if(s[i-1]==t[j-1]) curr[j] += prev[j-1] % mod;
        }
        prev = curr;
    }
    return prev[n2];
}

/*
    recurrence relation:
    If the characters match, consider two options: either leave one character in s1 and s2 or leave one character in s1 and continue matching s2
    dp[i][j] = dp[i-1][j] + dp[i-1][j-1] if(s[i]==t[j])

    // If characters don't match, just leave one character in s1 and continue matching s2
    dp[i][j] = dp[i-1][j]

    base case: if j<0, all the characters of t matched with t so return 1
    if i<0 and j>=0, then some characters of j didn't match so return 0
*/
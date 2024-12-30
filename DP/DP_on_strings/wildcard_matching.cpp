#include <bits/stdc++.h>
using namespace std;

// memiozation
bool isMatch(string s, string p, vector<vector<int>> &dp, int i, int j){
    if(i<0){
        while(j>=0 && p[j]=='*') j--;
        if(j<0) return 1;
        else return 0;
    }
    if(j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==p[j] || p[j]=='?') return dp[i][j] = isMatch(s,p,dp,i-1,j-1);
    else if(p[j]=='*') return dp[i][j] = isMatch(s,p,dp,i-1, j) || isMatch(s,p,dp,i,j-1);
    else return dp[i][j] = 0;
}

// tabulation
bool isMatch(string s, string p) {
    int n1 = s.size(), n2 = p.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
    dp[0][0] = 1;
    int j=1;
    while(j<=n2 && p[j-1]=='*') dp[0][j++]=1;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
            else if(p[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
        }
    }
    return dp[n1][n2];
}

// space optimized
bool isMatch(string s, string p) {
    int n1 = s.size(), n2 = p.size();
    vector<int> prev(n2+1,0);
    prev[0] = 1;
    int j=1;
    while(j<=n2 && p[j-1]=='*') prev[j++]=1;
    for(int i=1; i<=n1; i++){
        vector<int> curr(n2+1,0);
        for(int j=1; j<=n2; j++){
            if(s[i-1]==p[j-1] || p[j-1]=='?') curr[j] = prev[j-1];
            else if(p[j-1]=='*') curr[j] = prev[j] || curr[j-1];
        }
        prev = curr;
    }
    return prev[n2];
}

/*
    dp relation:
    
    if(s[i]==p[j] || p[j]=='?') dp[i][j] = dp[i-1][j-1];
    else if(p[j]=='*') then:
        Call f(i,j-1). i.e replace ‘*’ with nothing and act as if it was not present.
        Call f(i-1,j). i.e replace ‘*’ with a single character at index i and make the j pointer to still point at index j. 
        dp[i][j] = logical OR of above two calls, i.e. dp[i-1][j] || dp[i][j-1];
    else dp[i][j] = 0;
*/
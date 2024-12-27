#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    vector<vector<char>> lps(n,vector<char>(n,'0'));
    vector<int> in_out(n,0);
    for(int i=0; i<n; i++) dp[i][i] = 1;
    for(int l=2; l<=n; l++){
        for(int i=0; i<=n-l; i++){
            int j=i+l-1;
            if(s[i]==s[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
                lps[i][j] = 'c';
            }
            else {
                if (dp[i][j-1] >= dp[i+1][j]){
                    dp[i][j] = dp[i][j-1];
                    lps[i][j] = 'l';
                }
                else{
                    dp[i][j] = dp[i+1][j];
                    lps[i][j] = 'd';
                }
            }
        }
    }
    int i = 0, j = n-1;
    while(lps[i][j]!='0'){
        if(lps[i][j]=='c'){
            in_out[i] = 1;
            in_out[j] = 1;
            i++;
            j--;
        }
        else if(lps[i][j]=='l') {
            in_out[i] = 1;
            j--;
        }
        else{
            in_out[j] = 1;
            i++;
        }
    }
    string LPS;
    for(int i=0; i<n; i++){
        if(in_out[i]) LPS += s[i];
    }
    cout<<LPS;
    return dp[0][n-1];
}
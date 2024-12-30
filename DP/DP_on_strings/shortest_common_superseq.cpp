#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();

    // LCS
    vector<vector<int>> dp(n1, vector<int>(n2,0));
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(str1[i]==str2[j]){
                dp[i][j] = 1;
                if(i!=0 && j!=0) dp[i][j] += dp[i-1][j-1]; 
            }
            else{
                if(i!=0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j!=0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }
    string ans;

    // printing LCS modified
    int i=n1-1, j=n2-1;
    while(i>=0 && j>=0){
        if(str1[i]==str2[j]){
            ans = str1[i] + ans;
            i--;
            j--;
        }
        else{
            int l=0,u=0;
            if(i!=0) u = dp[i-1][j];
            if(j!=0) l = dp[i][j-1];
            if(l>u){
                ans = str2[j] + ans;
                j--;
            }
            else{
                ans = str1[i] + ans;
                i--;
            }
        }
    }
    while(i>=0){
        ans = str1[i] + ans;
        i--;
    }
    while(j>=0){
        ans = str2[j] + ans;
        j--;
    }
    return ans;
}
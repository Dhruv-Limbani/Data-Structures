#include<bits/stdc++.h>
using namespace std;

// tabulation
int longestCommonSubstr(string& s1, string& s2) {
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(),-1));
    int mx = 0;
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if(s1[i]==s2[j]){
                dp[i][j]=1;
                if(i!=0 && j!=0) dp[i][j]+=dp[i-1][j-1];
            }
            else dp[i][j]=0;
            mx = max(dp[i][j],mx);
        }
    }
    return mx;
}

//space optimized
int longestCommonSubstr(string& s1, string& s2) {
    vector<int> prev(s2.size(),-1);
    int mx = 0;
    for(int i=0; i<s1.size(); i++){
        vector<int> curr(s2.size(),-1);
        for(int j=0; j<s2.size(); j++){
            if(s1[i]==s2[j]){
                curr[j]=1;
                if(i!=0 && j!=0) curr[j]+=prev[j-1];
            }
            else curr[j]=0;
            mx = max(curr[j],mx);
        }
        prev = curr;
    }
    return mx;
}
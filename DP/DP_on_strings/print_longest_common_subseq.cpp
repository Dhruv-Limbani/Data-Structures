#include<bits/stdc++.h>
using namespace std;

// tabulation
string lcs(string text1, string text2) {
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
    string ans="";
    int i=text1.size()-1, j=text2.size()-1;
    while(i>=0 && j>=0){
        if(text1[i]==text2[j]){
            ans = text1[i] + ans;
            i--;
            j--;
        }
        else{
            int t=0,l=0;
            if(i!=0) t = dp[i-1][j];
            if(j!=0) l = dp[i][j-1];
            if(l>=t) j--;
            else i--;
        }
    }
    return ans;
}

int main() {

  string s1 = "abcde";
  string s2 = "bdgek";

  cout << "The Longest Common Subsequence is "<<lcs(s1, s2);
}
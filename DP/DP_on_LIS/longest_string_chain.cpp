#include <bits/stdc++.h>
using namespace std;

bool comp(string &s1, string &s2){
    return s1.size()<s2.size();
}

bool is_valid(string s1, string s2){
    if(s1.size()!=s2.size()+1) return false;
    int n1 = s1.size(); int n2 = s2.size();
    int i=0, j=0;
    while(i<n1){
        if(s1[i]==s2[j]) j++;
        i++;
    }
    return (i==j+1);
}

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), comp);
    int n = words.size(), mx=1;
    vector<int> dp(n, 1);
    for(int i=1; i<n; i++){
        for(int p=0; p<=i-1; p++){
            if(is_valid(words[i], words[p]) && dp[i]<1+dp[p]) dp[i] = 1+dp[p];
        }
        mx = max(mx, dp[i]);
    }
    return mx;
}
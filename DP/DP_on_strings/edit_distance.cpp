#include<bits/stdc++.h>
using namespace std;

// memiozation
int minDistance(string word1, string word2, vector<vector<int>>& dp, int ind1, int ind2){
    if(ind1<0 || ind2<0) return INT_MAX;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(ind1==0) return dp[ind1][ind2] = ind2;
    if(ind2==0) return dp[ind1][ind2] = ind1;
    return dp[ind1][ind2] = min(minDistance(word1, word2, dp, ind1-1, ind2-1) + 1*(word2[ind1-1]!=word1[ind2-1]), 1 +
                            min(minDistance(word1, word2, dp, ind1, ind2-1), minDistance(word1, word2, dp, ind1-1, ind2)));
}
int minDistance(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    vector<vector<int>> dp(n2+1, vector<int>(n1+1, -1));
    return minDistance(word1, word2, dp, n2, n1);
}

// tabulation
int minDistance(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    vector<vector<int>> dp(n2+1, vector<int>(n1+1, -1));
    for(int i=0; i<=n2; i++){
        for(int j=0; j<=n1; j++){
            if(i==0) dp[i][j] = j;
            else if (j==0) dp[i][j] = i;
            else dp[i][j] = min(dp[i-1][j-1] + 1*(word1[j-1]!=word2[i-1]), 1 + min(dp[i][j-1], dp[i-1][j]));
        }
    }
    return dp[n2][n1];
}

// space optimization
int minDistance(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    vector<int> prev(n1+1, -1);
    for(int i=0; i<=n2; i++){
        vector<int> curr = prev;
        for(int j=0; j<=n1; j++){
            if(i==0) curr[j] = j;
            else if (j==0) curr[j] = i;
            else curr[j] = min(prev[j-1] + 1*(word1[j-1]!=word2[i-1]), 1 + min(curr[j-1], prev[j]));
        }
        prev = curr;
    }
    return prev[n1];
}

/*
    dp relation:
    dp[i][j] represents minimum edit distance for word1[0..j] and word2[0..i]
    dp[i][j] = min(dp[i-1][j-1] + 1(if word1[j]!=word2[i])-> this 1 is for replacing, dp[i][j-1] + 1(for deleting word1[j]), dp[i-1][j] + 1(for deleting word2[i]))
*/
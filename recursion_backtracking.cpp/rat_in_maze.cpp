#include<bits/stdc++.h>
using namespace std;

void paths(vector<vector<int>> &mat, vector<string> &ans, string s, int i, int j, int n){
    if(i==n-1 && j==n-1) ans.push_back(s);
    else if(i<0 || i>=n || j<0 || j>=n) return;
    else if(mat[i][j]){
        mat[i][j] = 0;
        paths(mat,ans,s+"D",i+1,j,n);
        paths(mat,ans,s+"L",i,j-1,n);
        paths(mat,ans,s+"R",i,j+1,n);
        paths(mat,ans,s+"U",i-1,j,n);
        mat[i][j] = 1;
    }
    
}
vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    paths(mat, ans, "", 0, 0, mat.size());
    return ans;
}   
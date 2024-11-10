#include<bits/stdc++.h>
using namespace std;

void paths(vector<vector<int>> &mat, vector<string> &ans, string s, int i, int j, int n){
    if(i==n-1 && j==n-1) ans.push_back(s);
    else if(mat[i][j]){
        if(i+1<n && mat[i+1][j]==1){
            mat[i][j] = 0;
            paths(mat,ans,s+"D",i+1,j,n);
            mat[i][j] = 1;
        } 
        if(j-1>=0 && mat[i][j-1]==1){
            mat[i][j] = 0;
            paths(mat,ans,s+"L",i,j-1,n);
            mat[i][j] = 1;
        }
        if(j+1<n && mat[i][j+1]==1){
            mat[i][j] = 0;
            paths(mat,ans,s+"R",i,j+1,n);
            mat[i][j] = 1;
        }
        if(i-1>=0 && mat[i-1][j]==1){
            mat[i][j] = 0;
            paths(mat,ans,s+"U",i-1,j,n);
            mat[i][j] = 1;
        }
    }
    
}
vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    paths(mat, ans, "", 0, 0, mat.size());
    return ans;
}
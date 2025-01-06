#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& mat) {
    int i=0, j = mat.size()-1;
    while(i<j){
        if(mat[i][j] || mat[j][i]){
            if(mat[i][j]) i++;
            if(mat[j][i]) j--;
        }
        else{
            i++;
            j--;
        }
    }
    if(i>j) return -1;
    for(int k=0; k<mat.size(); k++){
        if((k!=i && mat[k][i]==0) || mat[i][k]==1) return -1;
    }
    return i;
}
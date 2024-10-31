#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> map, int n, int i, int j){
    int row = i, col = j;
    // check up
    while(row>=0) if(map[row--][col] == 'Q') return false;
    // check in top left direction
    row = i;
    while(row>=0 && col>=0) if(map[row--][col--] == 'Q') return false;
    // check in top right direction
    row = i;
    col = j;
    while(row>=0 && col<n) if(map[row--][col++] == 'Q') return false;
    return true;
}
void nqueens(vector<vector<string>> &ans, vector<string> &map, int curr_row, int n){
    if(curr_row==n) ans.push_back(map);
    else{
        for(int curr_col=0; curr_col<n; curr_col++){
            if(isSafe(map, n, curr_row, curr_col)){
                map[curr_row][curr_col] = 'Q';
                nqueens(ans, map, curr_row+1, n);
                map[curr_row][curr_col] = '.';
            }
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    string s(n,'.');
    vector<string> map(n,s);
    nqueens(ans,map,0,n);
    return ans;
}

// time optimized

void nqueens(vector<vector<string>> &ans, vector<string> &map, vector<int> col, vector<int> upper_left, vector<int> upper_right, int curr_row, int n){
    if(curr_row==n) ans.push_back(map);
    else{
        for(int curr_col=0; curr_col<n; curr_col++){
            if(col[curr_col] && upper_left[n - 1 - curr_row + curr_col] && upper_right[curr_row + curr_col]){
                map[curr_row][curr_col] = 'Q';
                col[curr_col] = 0;
                upper_left[n - 1 - curr_row + curr_col] = 0;
                upper_right[curr_row + curr_col] = 0;
                nqueens(ans, map, col, upper_left, upper_right, curr_row+1, n);
                map[curr_row][curr_col] = '.';
                col[curr_col] = 1;
                upper_left[n - 1 - curr_row + curr_col] = 1;
                upper_right[curr_row + curr_col] = 1;
            }
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    string s(n,'.');
    vector<string> map(n,s);
    vector<int> col(n,1), upper_left(2*n-1,1), upper_right(2*n-1,1);
    nqueens(ans, map, col, upper_left, upper_right, 0, n);
    return ans;
}


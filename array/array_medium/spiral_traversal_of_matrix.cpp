#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given a Matrix, print the given matrix in spiral order.

    Examples:

    Example 1:
    Input: Matrix[][] = { { 1, 2, 3, 4 },
                          { 5, 6, 7, 8 },
                          { 9, 10, 11, 12 },
                          { 13, 14, 15, 16 } }

    Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
    Explanation: The output of matrix in spiral form.

    Example 2:
    Input: Matrix[][] = { { 1, 2, 3 },
                          { 4, 5, 6 },
                          { 7, 8, 9 } }
                    
    Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
    Explanation: The output of matrix in spiral form.
*/


vector<int> spiralMatrix(vector<vector<int>>&m) {
    int mt=m[0].size(), n=m.size();
    int t = 0, b = n-1, l = 0, r=mt-1, ct=0;
    vector<int> ans;
    while(t<=b && l<=r){
        if(ct%4==0){
            for(int j=l; j<=r; j++){
                ans.push_back(m[t][j]);
            }
            t++;
        }
        else if(ct%4==1){
            for(int i=t; i<=b; i++){
                ans.push_back(m[i][r]);
            }
            r--;
        }
        else if(ct%4==2){
            for(int j=r; j>=l; j--){
                ans.push_back(m[b][j]);
            }
            b--;
        }
        else if(ct%4==3){
            for(int i=b; i>=t; i--){
                ans.push_back(m[i][l]);
            }
            l++;
        }
        ct++;
    }
    return ans;
}

/*
    TC: O(N*M)
    SC: O(N*M)
*/
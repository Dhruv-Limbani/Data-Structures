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


vector<int> spiralOrder(vector<vector<int>>& m) {
    int mt=m[0].size(), n=m.size();
    int t = 0, b = n-1, l = 0, r=mt-1, ct=0;
    vector<int> ans;
    while(t<=b && l<=r){
        for(int j=l; j<=r; j++){
            ans.push_back(m[t][j]);
        }
        t++;

        for(int i=t; i<=b; i++){
            ans.push_back(m[i][r]);
        }
        r--;

        if(t<=b){
            for(int j=r; j>=l; j--){
                ans.push_back(m[b][j]);
            }
            b--;
        }

        if(l<=r){
            for(int i=b; i>=t; i--){
                ans.push_back(m[i][l]);
            }
            l++;
        }

    }
    return ans;
}

/*
    Create and initialize variables top as starting row index, bottom as ending row index 
    left as starting column index, and right as ending column index.

    In each outer loop traversal print the elements of a square in a clockwise manner.
    
    Print the top row, i.e. Print the elements of the top row from column index left to right 
    and increase the count of the top so that it will move to the next row.

    Print the right column, i.e. Print the rightmost column from row index top to bottom and decrease the count of right.
    Print the bottom row, i.e. if top <= bottom, then print the elements of a bottom row from column right to left
    and decrease the count of bottom
    
    Print the left column, i.e. if left <= right, then print the elements of the left column 
    from the bottom row to the top row and increase the count of left.
    
    Run a loop until all the squares of loops are printed.

    TC: O(N*M)
    SC: O(N*M)
*/
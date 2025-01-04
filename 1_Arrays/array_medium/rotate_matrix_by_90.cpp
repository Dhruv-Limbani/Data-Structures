#include<bits/stdc++.h>
using namespace std;

/*
    You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[7,4,1],[8,5,2],[9,6,3]]
*/

void brute_force(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    vector<vector<int>> m(n,vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            m[j][n-i-1] = matrix[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = m[i][j];
        }
    }
}

/*
    Take first row, put it in last column of dummy matrix
    take second row, put it in 2nd last column and so on
    
    TC: O(N*N + N*N)
    SC: O(N*N)
*/

void optimal(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        int k=0, j = n-1;
        while(k<=j){
            swap(matrix[i][k],matrix[i][j]);
            k++;
            j--;
        }
    }
}

/*
    Take transpose of the matrix and reverse each row of the matrix

    TC: O(N*N/2 + N*N/2) = O(N*N)
    SC: O(1)
*/
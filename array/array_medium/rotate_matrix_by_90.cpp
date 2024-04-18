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
    TC: O(N*N/2 + N*N/2) = O(N*N)
    SC: O(1)
*/
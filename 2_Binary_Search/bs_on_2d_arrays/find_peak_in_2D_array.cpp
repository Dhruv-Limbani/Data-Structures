#include<bits/stdc++.h>
using namespace std;

/*
    A peak element in a 2D grid is an element that is strictly greater than all of its adjacent 
    neighbors to the left, right, top, and bottom.

    Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, 
    find any peak element mat[i][j] and return the length 2 array [i,j].

    You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
*/

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int l=0, h=m-1, mid;
    while(l<=h){
        mid = (l+h)/2;
        int max_idx = 0;
        for(int i=0; i<n; i++){
            if(mat[i][mid]>mat[max_idx][mid]) max_idx=i;
        }
        int left=-1,right=-1;
        if(0<mid) left = mat[max_idx][mid-1];
        if(mid<m-1) right = mat[max_idx][mid+1];
        if(mat[max_idx][mid]<left) h = mid-1;
        else if(mat[max_idx][mid]<right) l = mid+1;
        else return {max_idx,mid};
    }
    return {0,0};
}

/*
    we apply binary search on 0 to m-1 i.e. on column index;
    at each mid we search the maximum element in the column mid;
    then we compare max element to it's left and right if they exist
    if mat[max_eles_row_index][mid] < left we eliminate the right part h = mid-1;
    if mat[max_eles_row_index][mid] < right we eliminate the left part l = mid+1;
    else we return index {max_eles_row_index, mid}

    TC: O(nlogm)
    SC: O(1)
*/
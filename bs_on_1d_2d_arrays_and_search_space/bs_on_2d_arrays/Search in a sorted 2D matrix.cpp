#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' 
    denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. 
    Moreover, the first element of a row is greater than the last element of the previous row (if it exists). 
    You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

    Examples
    Example 1:
    Input Format:
    N = 3, M = 4, target = 8,
    mat[] = 
    1 2 3 4
    5 6 7 8 
    9 10 11 12
    Result:
    true
    Explanation:
    The ‘target’  = 8 exists in the 'mat' at index (1, 3).

    Example 2:
    Input Format:
    N = 3, M = 3, target = 78,
    mat[] = 
    1 2 4
    6 7 8 
    9 10 34
    Result:
    false
    Explanation:
    The ‘target' = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.
*/

/*
    One approach is to apply binary search on the imaginary 1d array representation of 2d array
    index i of 1d array = matrix[i/m (int division)][i%m] where m is the length of row or number of columns
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    // applying upperboud on first column
    int l=0, h=matrix.size()-1, mid, idx;
    while(l<=h){
        mid = (l+h)/2;
        if(matrix[mid][0]==target) return true;
        else if(matrix[mid][0]>target) h = mid - 1;
        else l = mid + 1;
    }
    if(h<0) return false;

    // applying binary search on row at index = idx
    idx = h;
    l = 0, h = matrix[0].size()-1;
    while(l<=h){
        mid = (l+h)/2;
        if(matrix[idx][mid]==target) return true;
        else if(matrix[idx][mid]>target) h = mid - 1;
        else l = mid + 1;
    }
    return false;
}

/*
    Complexity Analysis
    Time Complexity: O(logN + LogM), where N = given row number, M = given column number.

    Space Complexity: O(1) as we are not using any extra space.
*/
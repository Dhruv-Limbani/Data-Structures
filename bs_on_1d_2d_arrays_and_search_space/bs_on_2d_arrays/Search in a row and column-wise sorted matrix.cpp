#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' 
    denote the number of rows and columns, respectively. The elements of each row and each column 
    are sorted in non-decreasing order.
    But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).
    You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

    Pre-requisite: Search in a 2D sorted matrix

    Examples
    Example 1:
    Input Format:
    N = 5, M = 5, target = 14
    mat[] = 

    Result:
    true
    Explanation:
    Target 14 is present in the cell (3, 2)(0-based indexing) of the matrix. So, the answer is true.

    Example 2:
    Input Format:
    N = 3, M = 3, target = 12,
    mat[] = 

    Result:
    false
    Explanation:
    As target 12 is not present in the matrix, the answer is false.
*/

/*
    Approaches:
    1) Linear search O(n*m)
    2) Apply binary search in each row O(n*logm)
    3) Optimal - start from mat(0,m-1) if(cur_ele>target) col--; else if(cur_ele<target) row++ else return true;
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size(), row = 0, col = m-1;
    while(row<n && col>=0){
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]>target) col--;
        else row++;
    }
    return false;
}

/*
    Time Complexity: O(N+M), where N = given row number, M = given column number.
    Reason: We are starting traversal from (0, M-1), and at most, we can end up 
    being in the cell (M-1, 0). So, the total distance can be at most (N+M). 
    So, the time complexity is O(N+M).

    Space Complexity: O(1) as we are not using any extra space.
*/
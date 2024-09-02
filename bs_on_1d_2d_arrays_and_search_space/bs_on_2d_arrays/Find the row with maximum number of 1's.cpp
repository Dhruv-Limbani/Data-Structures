#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' 
    columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
    Your task is to find the index of the row with the maximum number of ones.
    Note: If two rows have the same number of ones, consider the one with a smaller index. 
    If there's no row with at least 1 zero, return -1.

    Example 1:
    Input Format:
    n = 3, m = 3, 
    mat[] = 
    1 1 1
    0 0 1
    0 0 0
    Result:
    0
    Explanation:
    The row with the maximum number of ones is 0 (0 - indexed).

    Example 2:
    Input Format:
    n = 2, m = 2 , 
    mat[] = 
    0 0
    0 0
    Result:
    -1
    Explanation:
    The matrix does not contain any 1. So, -1 is the answer.
*/

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int ct_max=0, idx=-1;
    for(int i=0; i<n; i++){
        int l=0, h=m-1, mid;
        while(l<=h){
            int mid = (l+h)/2;
            if(matrix[i][mid]==1) h = mid-1;
            else l=mid+1;
        }
        if(m-l>ct_max){
            ct_max = m-l;
            idx = i;
        }
    }
    return idx;
}

/*
    For each row we apply lower bound algo for ele=1. 'l' is the index of lower bound. m-l gives the number of 1's.

    Time Complexity: O(n X logm), where n = given row number, m = given column number.
    Reason: We are using a loop running for n times to traverse the rows. Then we are applying binary search on each row with m columns.

    Space Complexity: O(1) as we are not using any extra space.
*/
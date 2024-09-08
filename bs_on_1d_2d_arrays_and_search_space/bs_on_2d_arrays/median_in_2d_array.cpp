#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given a row-wise sorted matrix of size MXN, where M is no. of rows and N is no. of columns, 
    find the median in the given matrix.

    Note: MXN is odd.

    Examples
    Example 1:
    Input Format:M = 3, N = 3, matrix[][] =

                        1 4 9 
                        2 5 6
                        3 8 7
                        
    Result: 5
    Explanation:  If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5
    Example 2:
    Input Format:M = 3, N = 3, matrix[][] =

                        1 3 8 
                        2 3 4
                        1 2 5
                        
    Result: 3
    Explanation:  If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8. So, median = 3

*/

bool is_count_ok(vector<vector<int>> &matrix, int m, int n, int x){
    int ct = 0;
    for(int i=0; i<m; i++){
        int l=0, h=n-1, mid;
        while(l<=h){
            mid = (l+h)/2;
            if(matrix[i][mid]>x) h=mid-1;
            else l=mid+1;
        }
        ct += (h+1);
    }
    if (ct>(n*m/2)) return true;
    else return false;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int l=10^9, h=1, mid;
    for(int i=0; i<m; i++){
        l = min(matrix[i][0],l);
        h = max(matrix[i][n-1],h);
    }

    while(l<=h){
        mid = (l+h)/2;
        if(is_count_ok(matrix, m, n, mid)){
            h = mid-1;
        }
        else l = mid+1;
    }
    return l;
}

/*
    Search space: [min(matrix),max(matrix)]

    Now a property associated with median is that all the elements in the array which are <= median 
    will be more than (n*m/2) -integer division, if n and m both are odd.

    if for a mid, if the number of elements in array which are <= mid are less than n*m/2 then median is on the right part of mid
    so we eliminate the left part
    else, the mid is one of the possible ans and there might be an element < mid for which the same property holds so we eliminate right part.

    To find the number of elements which are <= mid we apply upperbound algo at each row of matrix and update the counter. (as rows are sorted)

    Time Complexity: O(log(10^9)) X O(M(logN)), where M = number of rows in the given matrix, N = number of columns in the given matrix

    Reason: Our search space lies between [0, 10^9] as the min(matrix) can be 0 and the max(matrix) 
    can be 109. We are applying binary search in this search space and it takes O(log(109)) time complexity. 
    Then we call is_count_ok() function for every ‘mid’ and this function takes O(M(logN)) time complexity.

    Space Complexity : O(1) as we are not using any extra space

*/
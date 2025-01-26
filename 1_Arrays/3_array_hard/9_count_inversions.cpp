#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

    What is an inversion of an array? 
    Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

    Example 1:
    Input Format
    : N = 5, array[] = {1,2,3,4,5}
    Result
    : 0
    Explanation
    : we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. 
    More clear example: 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.

    Example 2:
    Input Format
    : N = 5, array[] = {5,4,3,2,1}
    Result
    : 10
    Explanation
    : we have a reverse sorted array and we will get the maximum inversions as for i < j we will always find a pair such that A[j] < A[i]. 
    Example: 5 has index 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2 and 5 > 3 which will satisfy 
    out conditions and for reverse sorted array we will get maximum inversions and that is (n)*(n-1) / 2.
    For above given array there is 4 + 3 + 2 + 1 = 10 inversions.

    Example 3:
    Input Format
    : N = 5, array[] = {5,3,2,1,4}
    Result
    : 7
    Explanation
    : There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and (1,4) 
    as both are not satisfy our condition. 
*/


int brute_force(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++;
        }
    }
    return cnt;
}

/*
    TC: O(n^2)
    SC: O(1)
*/

// optimal approach
void merge(long long *arr, long long int l, long long int m, long long int h, long long int &ct){
    long long int i=l, j=m+1;
    long long int a[h-l+1], k=0;
    while(i<=m && j<=h){
        if(arr[i]<=arr[j]){
            a[k]=arr[i];
            i++;
            k++;
        }
        else{
            a[k]=arr[j];
            ct += (m-i+1);
            j++;
            k++;
        }
    }
    while(i<=m) a[k++]=arr[i++];
    while(j<=h) a[k++]=arr[j++];
    for(long long int k=l; k<=h; k++) arr[k]=a[k-l];
    return;
}
void divide(long long arr[], long long int l, long long int h, long long int &ct){
    if(l==h) return;
    long long int m = (l+h)/2;
    divide(arr, l, m, ct);
    divide(arr, m+1, h, ct);
    merge(arr, l, m, h, ct);
    
}
long long int inversionCount(long long arr[], long long int n) {
    long long int ct=0;
    divide(arr, 0, n-1, ct);
    return ct;
}

/*
    Using merge sort
    TC: O(nlogn)
    SC: O(n)
*/
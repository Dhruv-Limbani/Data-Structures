#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given two sorted arrays of size m and n respectively, 
    you are tasked with finding the element that would be at the kth position of the final sorted array.

    Hint: Uses same concept of median of 2 sorted arrays with minor changes
*/

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    if(n>m) return kthElement(arr2, arr1, m, n, k);
    int l = max(0,k-m), h = n; 
    if(k<n) h=k;
    while(l<=h){
        int mid = (l+h)/2;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if(mid<n) r1=arr1[mid];
        if(k-mid<m) r2=arr2[k-mid];
        if(mid>0) l1 = arr1[mid-1];
        if(k-mid>0) l2 = arr2[k-mid-1];

        if(l1<=r2 && l2<=r1) return max(l1,l2);
        else if(l1>r2) h = mid-1;
        else l=mid+1;
    }
    return 0;
}

/*
    Time Complexity: O(log(min(m, n))), where m and n are the sizes of two given arrays.
    Reason: We are applying binary search on the range [max(0, k-n2), min(k, n1)]. The range length <= min(m, n).

    Space Complexity: O(1), as we are not using any extra space to solve this problem.
*/
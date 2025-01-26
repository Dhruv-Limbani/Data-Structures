#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.
NOTE: Elements in the union should be in ascending order.
*/


void brute_force(int a[], int b[], int n, int m, int *arr){
    for(int i=0; i<n+m; i++) arr[i] = INT_MAX;
    int j=1,isp=0,ct=1;
    arr[0] = a[0];
    for(int i=1; i<n; i++){
        isp=0;
        for(int k=0; k<ct; k++){
            if(arr[k]==a[i]){
                isp=1;
                break;
            }
        }
        if(isp) continue;
        arr[j] = a[i];
        while(arr[j]<arr[j-1] && j>0){
            swap(arr[j],arr[j-1]);
            j--;
        }
        ct++;
        j=ct;

    }
    for(int i=0; i<m; i++){
        isp=0;
        for(int k=0; k<ct; k++){
            if(arr[k]==b[i]){
                isp=1;
                break;
            }
        }
        if(isp) continue;
        arr[j] = b[i];
        while(arr[j]<arr[j-1] && j>0){
            swap(arr[j],arr[j-1]);
            j--;
        }
        ct++;
        j=ct;
    }
}

/*
    TC: O(N) + O(N^2) + O(N^2) + O(M^2) + O(MN)
    SC: O(N+M)
*/


void better_approach(int a[], int b[], int n, int m, int *arr){
    set<int> s;
    for(int i=0; i<n; i++) s.insert(a[i]);
    for(int i=0; i<m; i++) s.insert(b[i]);
    int i=0;
    for(auto it: s){
        arr[i] = it;
        i++;
    }
}

/*
    TC: O(n*log(n+m) + m*log(m+n) + n + m)
    SC: O(2*(N+M))
*/

// Optimal Approach
vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> arr;
    int i=0,j=0,n=a.size(), m=b.size();
    while(i<n && j<m){
        while(i<n && (arr.size() && a[i]<=arr.back())) i++;
        while(j<m && (arr.size() && b[j]<=arr.back())) j++;
        if(i<n && j<m){
            if(a[i]<=b[j]) arr.push_back(a[i++]);
            else arr.push_back(b[j++]);
        }
    }
    while(i<n){
        if(a[i]!=arr.back()) arr.push_back(a[i]);
        i++;
    }
    while(j<m){
        if(b[j]!=arr.back()) arr.push_back(b[j]);
        j++;
    }
    return arr;
}
/*
Two Pointer approach
    TC:O(N+M)
    SC:O(N+M) for worst case i.e. there are no common elements

    Does not work for unsorted arrays
*/

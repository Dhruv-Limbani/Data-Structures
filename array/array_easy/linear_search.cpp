#include<bits/stdc++.h>
using namespace std;

int brute_force_approach(int arr[], int n, int k){
    for(int i=0; i<n; i++) if(arr[i]==k) return i;
    return -1;
}
/*
    TC: O(N)+O(N)
    SC: O(N)
*/

void better_approach(int *arr, int n){
    int i=0, j=0;
    while(i<n && j<n){
        while(arr[j]!=0 && j<n) j++;
        while(arr[i]==0 && i<n) i++;
        if(i>j && i<n && j<n)
            swap(arr[i],arr[j]);
        else if(i<j) i++;
    }
}
/*
    TC: O(N)
    SC: O(1)
*/

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int idx = brute_force_approach(arr,n,k);
    if(idx<0) cout<<"Element Not Found!";
    else cout<<"Element found at index: "<<idx;
    return 0;
}
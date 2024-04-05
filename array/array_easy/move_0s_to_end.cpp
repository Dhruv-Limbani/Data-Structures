#include<bits/stdc++.h>
using namespace std;

void brute_force_approach(int *arr, int n){
    int a[n]={0},j=0;
    for(int i=0; i<n; i++){
        if(arr[i]){
            a[j]=arr[i];
            j++;
        }
    }
    for(int i=0; i<n; i++) arr[i]=a[i];
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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    // brute_force_approach(arr,n);
    better_approach(arr, n);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return 0;
}
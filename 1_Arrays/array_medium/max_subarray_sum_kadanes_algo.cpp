#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
    has the largest sum and returns its sum and prints the subarray.
*/

int brute_force(int *arr, int n){
    int s=0,e=0;
    long long mx_sm=0, sum;
    for(int i=0; i<n; i++){
        sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(sum>mx_sm){
                s=i;
                e=j;
                mx_sm=sum;
            }
        }
    }
    return mx_sm;
}
/*
    TC: O(N^2)
    SC: O(1)
*/

int optimal_approach(int *arr, int n){
    int max_sum=0,sum=0,s=0,fs=0,e=0;
    for(int i=0; i<n; i++){
        if(sum==0){
            s=i;
        }
        sum+=arr[i];
        if(sum>max_sum){
            max_sum=sum;
            fs=s;
            e=i;
        }
        if(sum<0) sum=0;
    }
    cout<<"The Subarray with maximum sum is: "<<endl;
    for(int i=fs; i<=e; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return max_sum;
}
/*
    Kadane's algo

    we start adding elements of array to sum and update the max_sum accordingly
    if at any point i, sum<0 it indicates that sum of whole arr[0..i] is neg
    and the sub array will either exist in the remaining part after i or 
    that before i (if we don't find sum in anywhere from arr[i..n] > maxsum we have from arr[0..i])

    if there is max_subarray, it always starts at sum=0 so we note down that index as start
    if sum>max_sum we note down curr index as last, and start_idx as final_start_idx

    TC: O(N)
    SC: O(1)
*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<optimal_approach(arr, n);
    return 0;
}
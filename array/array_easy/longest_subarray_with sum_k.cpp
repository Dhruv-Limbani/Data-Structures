#include<bits/stdc++.h>
using namespace std;

int brute_force_approach(int arr[], int n, int k){
    int mx=0;
    for(int i=0; i<n; i++){
        for(int t=i; t<n; t++ ){
            int sum = 0;
            for(int j=i; j<=t; j++){
                sum += arr[j];
            }
            if(sum==k){
                mx=max(mx,t-i+1);
            }
        }
    }
    return mx;
}

/*
    considering all the subarrays of array and then calculating the sum
    followed by comparing it with k and updating mx value

    TC: O(N^3)
    SC: O(1)
*/

int better_approach(int arr[], int n, int k){
    int mx=0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int t=i; t<n; t++ ){
            sum+=arr[t];
            if(sum==k){
                mx=max(mx,t-i+1);
            }
        }
    }
    return mx;
}

/*
    considering all the subarrays of array and then calculating the sum
    followed by comparing it with k and updating mx value

    TC: O(N^2)
    SC: O(1)
*/


int optimal_approach(int arr[], int n, int k){
    int i=0,j=-1, mx=0, sum=0;
    while(j<n){
        if(sum==k){
            mx = max(mx,j-i+1);
            while (arr[j+1] == 0 && j < n-1) {
                j++;
                mx++;
            }
            sum-=arr[i];
            i++;
        }
        else if(sum>k && j>=i){
            sum-=arr[i];
            i++;
        } 
        else {
            j++;
            sum += arr[j];
        }
    }
    return mx;
}

/*
    two pointer approach:
    we increment j until we reach point where all the elements
    from i to j sum to k.
    afterwards we check for 0s so we increament j until the last 0 from 0s
    coming right after the point where we found sum=k
    if at any point the sum > k, we remove arr[i] from sum and increament i
    if sum is < k then we increament j by one and sum by arr[j]

    TC: O(N)
    SC: O(1)

    Unlike the above two approaches, this does not work if there are any -ve nums in array
*/

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    return 0;
}
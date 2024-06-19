#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
*/

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

int brute_force_approach_2(int arr[], int n, int k){
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

int better_approach(int arr[], int n, int k){
    map<int, int> m;
    int sum=0,mx=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum==k) mx = i+1;
        int rem = sum-k;
        if(m.find(rem)!=m.end()){
            mx = max(mx,i-m[rem]);
        }
        if(m.find(sum)==m.end()) m[sum]=i;
    }
    return mx;
}

/*
    TC: O(N)
    SC: O(N)
*/

int optimal_approach(int arr[], int n, int k){
    int i=0,j=0, mx=0, sum=arr[0];
    while(j<n){
        while(i<j && sum>k){
            sum-=arr[i];
            i++;
        }
        if(sum==k){
            mx = max(mx,j-i+1);
        }
        j++;
        if(j<n) sum+=arr[j];
    }
    return mx;
}

/*
    The steps are as follows:

    First, we will take two pointers: left and right, initially pointing to the index 0.
    
    The sum is set to a[0] i.e. the first element initially.
    
    Now we will run a while loop until the right pointer crosses the last index i.e. n-1.
    
    Inside the loop, we will do the following:
    
    We will use another while loop and it will run until the sum is lesser or equal to k.
    
    Inside this second loop, from the sum, we will subtract the element that is pointed by the left pointer and increase the left pointer by 1.
    
    After this loop gets completed, we will check if the sum is equal to k. If it is, we will compare the length of the current subarray i.e. (right-left+1) with the existing one and consider the maximum one.
    
    Then we will move forward the right pointer by 1. If the right pointer is pointing to a valid index(< n) after the increment, we will add the element i.e. a[right] to the sum.
    
    Finally, we will return the maximum length.

    Unlike the above two approaches, this does not work if there are any -ve nums in array

    Complexity Analysis
    Time Complexity: O(2*N), where N = size of the given array.
    Reason: The outer while loop i.e. the right pointer can move up to index n-1(the last index). 
    Now, the inner while loop i.e. the left pointer can move up to the right pointer at most. 
    So, every time the inner loop does not run for n times rather it can run for n times in total. 
    So, the time complexity will be O(2*N) instead of O(N2).

    Space Complexity: O(1) as we are not using any extra space.
*/

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    return 0;
}
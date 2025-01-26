#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an array of integers arr[] and an integer target.

    1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

    2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

    Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, 
    then nums[1] + nums[1] = target is not a solution.
*/

pair<int, int> brute_force(int arr[], int n, int k){
    for(int i=0; i<n-1; i++){
        int a = arr[i];
        for (int j = i + 1; j < n; j++) {
          if (a + arr[j] == k){
            return {i,j};
          }
        }
    }
    return {-1,-1};
}

/*
    TC: O(N^2)
    SC: O(1)
*/

pair<int, int> better_approach(int arr[], int n, int k){
    map<int, int> m;
    for(int i=0; i<n; i++){
        if(m.find(k-arr[i]) != m.end()) return {m[k-arr[i]],i};
        if(m.find(arr[i]) == m.end()) m[arr[i]] = i;
    }
    return {-1,-1};
}
/*
    TC: O(NlogN) or O(N) depending of map structure used
    SC: O(N)
*/

string optimized_approach(int arr[], int n, int k){
    unordered_map<int, int> m;
    for(int i=0; i<n; i++) m[arr[i]] = i;
    sort(arr,arr+ n);
    int i=0, j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==k) return "YES";
        else if(arr[i]+arr[j]>k) j--;
        else i++;
    }
    return "NO";
}
/*
    TC: O(N) + O(N), in very rare and worst case O(N^2)
    SC: O(N)
    cannot return indices
*/

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    return 0;
}
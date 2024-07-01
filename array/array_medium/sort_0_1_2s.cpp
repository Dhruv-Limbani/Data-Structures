#include <bits/stdc++.h>
using namespace std;

/*
   Problem Statement: Given an array consisting of only 0s, 1s, and 2s. 
   Write a program to in-place sort the array without using inbuilt sort functions. 
   ( Expected: Single pass-O(N) and constant space)
*/

void brute_force(int *arr, int n){
    // bubble, insertion, selection sort : O(N^2)
    // quick, merge sort : O(NlogN)
    sort(arr,arr+n);
}

void better_approach(int *arr, int n)
{
   int count[3]={0},k=0;
   for(int i=0; i<n; i++){
      count[arr[i]]++;
   }
   for(int i=0; i<=2; i++){
      while(count[i]--){
         arr[k]=i;
         k++;
      }
   }
}
/*
    TC: O(N) + O(N)
    SC: O(N)
*/

void optimal_approach(int *arr, int n)
{
   int i=0,j=0,k=n-1;
   while(j<=k){
      if(arr[j]==0){
         swap(arr[i],arr[j]);
         i++;
         j++;
      }
      else if(arr[j]==1){
         j++;
      }
      else{
         swap(arr[k],arr[j]);
         k--;
      }
   }
}

/*
    Dutch National Flag algo
    arr[0,i) contains all 0s
    arr[i,mid-1) contains all 1s
    arr[high+1,n-1] contains all 2s
    
    TC: O(N)
    SC: O(1)
*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    return 0;
}
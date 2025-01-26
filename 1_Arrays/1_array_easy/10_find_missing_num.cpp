#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. 
    Find the number(between 1 to N), that is not present in the given array.
*/

int brute_force(int arr[],int n){
    int is_mis;
    for(int i=1; i<=n; i++){
        is_mis=1;
        for(int j=0; j<n-1; j++){
            if(i==arr[j]){
                is_mis=0;
                break;
            }
        }
        if(is_mis) return i;
    }
    return 0;
}
/*
    TC: O(N^2)
    SC: O(1)
*/

int better_approach(int arr[], int n){
    int a[n+1] = {0};
    for(int i=0; i<n-1; i++){
        a[arr[i]] = 1;
    }
    for(int i=1; i<n+1; i++) if(!a[i]) return i;
    return 0;
}
/*
    TC: O(2N)
    SC: O(N+1)
*/

int optimal_approach_1(int arr[], int n){
    int sum=n*(n+1)/2;
    for(int i=0; i<n-1; i++) sum-=arr[i];
    return sum;
}
/*
    TC: O(N)
    SC: O(1)
*/

int optimal_approach_2(int arr[], int n){
    int xor1=0,xor2=0;
    for(int i=0; i<n-1; i++){
        xor1^=arr[i];
        xor2^=(i+1);
    }
    xor2^=n;
    return xor1^xor2;
}
/*
    XOR Property:
        a^a = 0
        a^0 = a
    TC: O(N)
    SC: O(1)
*/


int main()
{
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0; i<n-1; i++) cin>>arr[i];
    // cout<<brute_force(arr,n);
    cout<<optimal_approach_1(arr,n);
    return 0;
}
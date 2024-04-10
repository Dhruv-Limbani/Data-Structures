#include<bits/stdc++.h>
using namespace std;

int brute_force(int arr[], int n){
    int mx_p=0, p;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            mx_p = max(mx_p,arr[j]-arr[i]);
        }
    }
    return mx_p;
}
/*
    TC: O(N^2)
    SC: O(1)
*/

int optimal_approach(int arr[], int n){
    int mn=arr[0], mx=0;
    for(int i=0; i<n; i++){
        if(arr[i]<=mn){
            mn = arr[i];
        }
        else{
            mx = max(mx,arr[i]-mn);
        }
    }
    return mx;
}
/*
    TC: O(N)
    SC: O(1)

    we keep the track of the minimum element
    if current element is greater than minimum element then we calculate the differece and update the max
    else we update the min element

    
*/


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    return 0;
}
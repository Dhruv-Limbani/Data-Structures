#include<bits/stdc++.h>
using namespace std;

void brute_force_approach(int *arr, int n){
    int a = arr[0];
    for(int i=1;i<n;i++) arr[i-1]=arr[i];
    arr[n-1] = a;
}
/*
    Time Complexity: O(n), as we iterate through the array only once.
    Space Complexity: O(1) as no extra space is used
*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    brute_force_approach(arr, n);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return 0;
}
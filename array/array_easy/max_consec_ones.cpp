#include<bits/stdc++.h>
using namespace std;

int brute_force(int arr[], int n){
    int sum=0,mx_sum=0;
    for(int i=0; i<n; i++){
        if(!arr[i]) sum=0;
        else sum++;
        mx_sum = max(mx_sum,sum);
    }
    return mx_sum;
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
    cout<<brute_force(arr,n);
    return 0;
}
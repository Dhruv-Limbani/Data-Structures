#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.
*/

int brute_force(int arr[], int n){
    int sum=0,mx_sum=0;
    for(int i=0; i<n; i++){
        if(arr[i]) sum++;
        else{
            cout<<mx_sum<<" "<<sum<<endl;
            mx_sum=max(mx_sum,sum);
            sum=0;
        }
    }
    return max(mx_sum,sum);
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
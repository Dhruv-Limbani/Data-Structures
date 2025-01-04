#include<bits/stdc++.h>
using namespace std;

int brute_force_approach(int arr[], int n){
    sort(arr,arr+n);
    return arr[n-1];
}

/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(1)
*/


int optimal_approach(int arr[], int n){
    int max_elem = arr[0];
    for(int i=0; i<n; i++) if(arr[i]>max_elem) max_elem=arr[i];
    return max_elem;
}

/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<brute_force_approach(arr,n)<<endl;
    cout<<optimal_approach(arr, n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int brute_force_approach(int arr[], int n){
    sort(arr,arr+n);
    int j = n-2;
    while(arr[j]==arr[n-1] && j>=0) j--;
    if(j>=0) return arr[j];
    return arr[n-1];
}

/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(1)
*/

int better_approach(int arr[], int n){
    int max_ele=arr[0];
    for(int i=0; i<n; i++) max_ele = max(max_ele,arr[i]);
    int s_max=arr[0];
    for(int i=0; i<n; i++) if(arr[i]!=max_ele) s_max = max(s_max,arr[i]);
    return s_max;
}

/*
    Time Complexity: O(N) double pass
    Space Complexity: O(1)
*/


int optimal_approach(int arr[], int n){
    int max=arr[0],s_max = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            s_max = max;
            max = arr[i];
        }
        else if(arr[i]>s_max || s_max==max) s_max = arr[i];
    }
    return s_max;
}

/*
    Time Complexity: O(N) single pass
    Space Complexity: O(1)
*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<brute_force_approach(arr,n)<<endl;
    cout<<optimal_approach(arr, n)<<endl;
    cout<<better_approach(arr,n);
    return 0;
}
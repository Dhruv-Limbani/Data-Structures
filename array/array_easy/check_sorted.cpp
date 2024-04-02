#include<bits/stdc++.h>
using namespace std;

bool brute_force(int arr[], int n){
    int i=0, j=0, k=0;
    while(i<n-1){
        if(arr[i]<arr[i+1]) j++;
        else if(arr[i]>arr[i+1]) k++;
        else
        {
            j++;
            k++;
        }
        i++;
    }
    if(j==n-1 || k==n-1)
        return true;
    return false;
}

/*
    Time complexity: O(N) best/avg/worst
    Space complexity: O(1)
*/

bool better_approach(int arr[], int n){
    int last_dir=0, curr_dir=0 ,i=0;
    while(i<n-1){
        last_dir = curr_dir;
        if(arr[i]<arr[i+1]) curr_dir=1;
        else if(arr[i]>arr[i+1]) curr_dir=-1;
        else curr_dir=last_dir;
        if(curr_dir!=last_dir && last_dir!=0) return false;
        i++;
    }
    return true;
}

/*
    Time complexity: O(N) avg/worst(when all the elements are sorted)
    Best case occurs in case where the order is not maintained within inital(3 to 4) elements
    Space complexity: O(1)
*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<brute_force(arr,n)<<endl;
    cout<<better_approach(arr,n)<<endl;
    return 0;
}

// 1 2 3 3 5

// 5 3 3 2 1
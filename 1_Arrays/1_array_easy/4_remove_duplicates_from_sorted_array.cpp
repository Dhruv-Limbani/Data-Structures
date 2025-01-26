#include<bits/stdc++.h>
using namespace std;

void better_approach(int *arr, int& n){
    for(int i=0; i<n-1; i++){
        int key=arr[i];
        while(arr[i+1]==key && i<n-1){
            arr[i+1]=INT_MIN;
            i++;
        }
    }
    int i,j=0;
    for(i=0; i<n; i++){
        while(arr[j]!=INT_MIN && j<n) j++;
        i=j;
        while(arr[i]==INT_MIN && i<n) i++;
        if(i<n)
            swap(arr[i],arr[j]);
    }
    n=j;
}

/*
    Time complexity: O(N) + O(N)
    Space complexity: O(1)
*/

void brute_force_approach(int *arr, int& n){
    set<int> s;
    for(int i=0; i<n; i++) s.insert(arr[i]);
    int i=0;
    for(auto it: s){
        arr[i] = it;
        i++;
    }
    n = i;
}

/*
    Time complexity: O(nlog(n)) + O(n)
    Space complexity: O(n)
*/

void optimal_approach(int *arr, int& n){
    int i=0;
    for(int j=1; j<n; j++){
        if(arr[j]!=arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    n=i+1;
}

/*
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    // brute_force_approach(arr,n);
    // better_approach(arr,n);
    optimal_approach(arr, n);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return 0;
}

// 1 2 3 3 5

// 5 3 3 2 1
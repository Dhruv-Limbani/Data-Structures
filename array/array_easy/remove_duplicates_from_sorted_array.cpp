#include<bits/stdc++.h>
using namespace std;

void brute_force(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int j=i+1;
        while(arr[j]==arr[i] && j<n){
            arr[j]=INT_MIN;
            j++;
        }
    }
    int l=n;
    for(int i=0; i<l; i++){
        int k=i,j=i;
        while(arr[j]==INT_MIN && j<n){
            j++;
        }
        while(j<n){
            arr[k]=arr[j];
            j++;
            k++;
        }
        l=k-1;
        while(k<n) arr[k++] = INT_MIN;
    }
}

/*
    Time complexity: O(N^2) best/avg/worst
    Space complexity: O(1)
*/

void better_approach(int *arr, int& n){
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
    // brute_force(arr,n);
    // for(auto it: arr) if(it!=INT_MIN) cout<<it<<" "; 
    // better_approach(arr,n);
    // for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return 0;
}

// 1 2 3 3 5

// 5 3 3 2 1
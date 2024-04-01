#include<bits/stdc++.h>
using namespace std;

void selection_sort(int *arr, int n){
    int min_idx, temp;
    for(int i=0; i<n-1; i++){
        min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx]) min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
/*
    Time complexity: O(N^2), (where N = size of the array), for the best, worst, and average cases.
    Space Complexity: O(1)
*/



void bubble_sort(int *arr, int n){
    int temp;
    bool swap=true;
    for(int i=n-1; i>=0; i--){
        if(swap){
            swap = false;
            for(int j=0; j<=i-1; j++){
                if(arr[j]>arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swap = true;
                }
            }
        }
        else break;
    }
}
/*
    Time Complexity: O(N^2) for the worst and average cases and O(N) for the best case. 
    Space Complexity: O(1)
*/

void insertion_sort(int *arr, int n){
    int temp,j;
    for(int i=1; i<n; i++){
        j=i;
        while(arr[j]<arr[j-1] && j>0){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    //selection_sort(arr,n);
    // bubble_sort(arr,n);
    insertion_sort(arr, n);
    for(auto it: arr) cout<<it<<" ";
    return 0;
}
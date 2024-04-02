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

void recursive_bubble_sort(int *arr, int n){
    if(n==0) return;
    bool is_swaped=false;
    for(int i=0; i<n; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            is_swaped = true;
        } 
    }
    recursive_bubble_sort(arr, is_swaped*(n-1));
}

/*
    Time Complexity: O(N^2) for the worst and average cases and O(N) for the best case. 
    Here, N = size of the array.
    Space Complexity: O(N) auxiliary stack space.
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

/*
    
    Time complexity: O(N^2), (where N = size of the array), for the worst, and average cases.
    Space Complexity: O(1)
    Best Case Time Complexity: 
    The best case occurs if the given array is already sorted. And if the given array is 
    already sorted, the outer loop will only run and the inner loop will run for 0 times. 
    So, our overall time complexity in the best case will boil down to O(N),where N = size of the array.
*/


void recursive_insertion_sort(int *arr, int s, int n){
    if(s>=n) return;
    for(int j=s; j>0 && arr[j]<arr[j-1]; j--){
        swap(arr[j],arr[j-1]);
    }
    recursive_insertion_sort(arr,s+1,n);
}

/*
    Time Complexity: O(N^2), (where N = size of the array), for the worst, and average cases.
    Space Complexity: O(N) auxiliary stack space.
    Best Case Time Complexity: 
    The best case occurs if the given array is already sorted. And if the given array is already sorted, 
    the recursion calls will only occur and inside the recursive function, the loop will run for 
    0 times(as each element is already present in its correct position). So, our overall time complexity 
    in the best case will boil down to O(N), where N = size of the array.
*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    //selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr, n);
    // recursive_bubble_sort(arr, n-1);
    recursive_insertion_sort(arr, 1, n);
    for(auto it: arr) cout<<it<<" ";
    return 0;
}
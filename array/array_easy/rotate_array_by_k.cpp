#include<bits/stdc++.h>
using namespace std;

void rotate_right_brute_force(int *arr, int n, int k){
    for(int i=1; i<=k; i++){
        int temp = arr[n-1],j;
        for(j=n-1; j>0; j--)
            arr[j]=arr[j-1];
        arr[j] = temp;
    }
}

/*
    Time Complexity: O(N*K)
    Space Complexity: O(1) - no extra space used
*/

void rotate_right_better_approach(int *arr, int n, int k){
    int a[n];
    for(int i=0; i<n; i++){
        a[(i+k)%n] = arr[i];
    }
    for(int i=0; i<n; i++) arr[i]=a[i];
}

/*
    k = 2, n = 6
    0 1 2 3 4 5
    4 5 0 1 2 3

    4-->0 (4+2)%6 = 0
    5-->1 (5+2)%7 = 1
    (i+k)%n = new_idx;
*/

/*
    Time Complexity: O(N) + O(N)
    Space Complexity: O(N)
*/

void reverse(int *arr, int s, int e){
    while(s<=e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

void rotate_right_optimal_approach(int *arr, int n, int k){
    k=k%n;
    reverse(arr, 0, n-k-1);
    reverse(arr, n-k, n-1);
    reverse(arr,0,n-1);
}

/*
    1 2 3 4 5
    k = 2, n = 5
    reversing first n-k elements
    2 1 3 4 5
    reversing last k elements
    2 1 5 4 3
    reversing whole array
    3 4 5 1 2

    Time complexity: O(N) + O(N)
    Space Complexity: O(1)
*/

void rotate_left_optimal_approach(int *arr, int n, int k){
    k =  k%n;
    rotate_right_optimal_approach(arr,n,n-k);
}

/*
    rotating array left by k times is equavalent to rotating array right n-k times;
    Time complexity: O(N) + O(N)
    Space Complexity: O(1)
*/

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    // rotate_right_brute_force(arr,n,k);
    // rotate_right_better_approach(arr,n,k);
    // rotate_right_optimal_approach(arr,n,k);
    rotate_left_optimal_approach(arr,n,k);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";   
    return 0;
}
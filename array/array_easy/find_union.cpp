#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.
NOTE: Elements in the union should be in ascending order.
*/


void brute_force(int a[], int b[], int n, int m, int *arr){
    for(int i=0; i<n+m; i++) arr[i] = INT_MAX;
    int j=1,isp=0,ct=1;
    arr[0] = a[0];
    for(int i=1; i<n; i++){
        isp=0;
        for(int k=0; k<ct; k++){
            if(arr[k]==a[i]){
                isp=1;
                break;
            }
        }
        if(isp) continue;
        arr[j] = a[i];
        while(arr[j]<arr[j-1] && j>0){
            swap(arr[j],arr[j-1]);
            j--;
        }
        ct++;
        j=ct;

    }
    for(int i=0; i<m; i++){
        isp=0;
        for(int k=0; k<ct; k++){
            if(arr[k]==b[i]){
                isp=1;
                break;
            }
        }
        if(isp) continue;
        arr[j] = b[i];
        while(arr[j]<arr[j-1] && j>0){
            swap(arr[j],arr[j-1]);
            j--;
        }
        ct++;
        j=ct;
    }
}

/*
    TC: O(N) + O(N^2) + O(N^2) + O(M^2) + O(MN)
    SC: O(N+M)
*/


void better_approach(int a[], int b[], int n, int m, int *arr){
    set<int> s;
    for(int i=0; i<n; i++) s.insert(a[i]);
    for(int i=0; i<m; i++) s.insert(b[i]);
    int i=0;
    for(auto it: s){
        arr[i] = it;
        i++;
    }
}

/*
    TC: O(n*log(n+m) + m*log(m+n) + n + m)
    SC: O(2*(N+M))
*/


void optimal_approach(int a[], int b[], int n, int m, int* arr){
    int i=0,j=0,k=0;
    if(a[i]<=b[j]){
        arr[k] = a[i];
        k++;
        i++;
    } 
    else{
        arr[k]=b[j];
        k++;
        j++;
    }
    while(i<n && j<m){
        while(a[i]<=arr[k-1] && i<n) i++;
        while(b[j]<=arr[k-1] && j<m) j++;
        if(i<n && j<m){
            if(a[i]<=b[j]){
                arr[k] = a[i];
                k++;
                i++;
            } 
            else{
                arr[k] = b[j];
                k++;
                j++;
            }
        }
        
    }
    while(i<n){
        if(a[i]!=arr[k-1]){
            arr[k]==a[i];
            k++;
        }
        i++;
    }
    while(j<m){
        if(b[j]!=arr[k-1]){
            arr[k]==b[j];
            k++;
        }
        j++;
    }
}
/*
Two Pointer approach
    TC:O(N+M)
    SC:O(N+M) for worst case i.e. there are no common elements

    Does not work for unsorted arrays
*/

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    int arr[n+m];
    for(int i=0; i<n+m; i++) arr[i] = INT_MAX;
    // brute_force(a,b,n,m,arr);
    // better_approach(a,b,n,m,arr);
    optimal_approach(a,b,n,m,arr);
    for(int i=0; i<n+m; i++){
        if(arr[i]==INT_MAX) break;
        cout<<arr[i]<<" ";
    }
    return 0;
}
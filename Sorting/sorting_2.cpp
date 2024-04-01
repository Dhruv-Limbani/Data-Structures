#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int m, int h){
    int i=l, j=m+1, temp[h-l+1], k=0;
    while(i<=m && j<=h){
        if(arr[i]<arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=m){
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j<=h){
        temp[k] = arr[j];
        k++;
        j++;
    }
    for(int t=0; t<=h-l; t++) arr[l+t]=temp[t];
}

void merge_sort(int *arr, int l, int h){
    if(l>=h) return;
    int m = (l+h)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,h);
    merge(arr,l,m,h);
    return;
}

int partition(int *arr, int l, int h){
    int p=arr[h],j=l-1;
    for(int i=l; i<h; i++){
        if(arr[i]<p){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[h]);
    return j+1;
}

int partition_2(int *arr, int l, int h){
    int p=arr[h],i=l,j=h;
    while(i<j){
        while(arr[i]<=p && i<h) i++;
        while(arr[j]>=p && j>l) j--;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[i],arr[h]);
    return i;
}

void quick_sort(int *arr, int l, int h){
    if(l>=h) return;
    int p = partition_2(arr, l, h);
    quick_sort(arr,l,p-1);
    quick_sort(arr,p+1,h);
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    // merge_sort(arr,0,n-1);
    quick_sort(arr,0,n-1);
    for(auto it: arr) cout<<it<<" ";
    return 0;
}

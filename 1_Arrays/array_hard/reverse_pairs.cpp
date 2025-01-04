#include<bits/stdc++.h>
using namespace std;

// brute force

int brute_force(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt;
}
/*
    TC: O(n^2)
    SC: O(n)
*/

// optimal apporach
void merge(vector<int>& nums, int l, int m, int h, int &ct){
    int i=l, j=m+1, k=0;

    // counting pairs from two sorted subarrays(additional part)

    while(i<=m && j<=h){
        if((long long)nums[i]>2*(long long)nums[j]){
            ct+=(m-i+1);
            j++;
        }
        else i++;
    }

    //usual merge algo
    i=l,j=m+1;
    vector<int> arr(h-l+1);
    while(i<=m && j<=h){
        if(nums[i]>nums[j]){
            arr[k++]=nums[j++];
        }
        else{
            arr[k++]=nums[i++];
        }
    }
    while(i<=m) arr[k++]=nums[i++];
    while(j<=h) arr[k++]=nums[j++];
    for(int i=l; i<=h; i++) nums[i]=arr[i-l];
}
void mergesort(vector<int>& nums, int l, int h, int &ct){
    if(l>=h) return;
    int m = (l+h)/2;
    mergesort(nums, l, m, ct);
    mergesort(nums, m+1, h, ct);
    merge(nums, l, m, h, ct);
}
int reversePairs(vector<int>& nums) {
    int n=nums.size(),ct=0;
    mergesort(nums,0,n-1,ct);
    for(auto it: nums) cout<<it<<" ";
    cout<<endl;
    return ct;
}
/*
    Logic of counting pairs from two sorted subarrays(additional part):
    if element an in left subarray is greater than an twice the element in right one 
    then all the elements post it will also be greater than twice the element in right subarray hence all of them will be pairs

    Using merge sort with modification
    TC: O(2nlogn)
    SC: O(n)
*/
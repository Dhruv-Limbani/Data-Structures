#include<bits/stdc++.h>
using namespace std;


/*
    Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). 
    Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 
    Example 1:
    Input Format:
    arr = [4,5,6,7,0,1,2,3]
    Result:
    0
    Explanation:
    Here, the element 0 is the minimum element in the array.

    Example 2:
    Input Format:
    arr = [3,4,5,1,2]
    Result:
    1
    Explanation:
    Here, the element 1 is the minimum element in the array.
*/

// Naive Approach is to find the minimum by traversing the entire array using linear search


int better_approach(vector<int>& nums) {
    int l=0, h=nums.size()-1, mid, mn=INT_MAX;
    while(l<=h){
        mid=(l+h)/2;
        if(nums[l]<=nums[mid]){
            mn = min(mn,nums[l]);
            l=mid+1;
        }
        else if(nums[mid]<=nums[h]){
            mn = min(mn,nums[mid]);
            h = mid-1;
        }
    }
    return mn;
}

/*
    TC: O(logn)
    SC: O(1)
*/

int optimal_approach(vector<int>& nums) {
    int l=0, h=nums.size()-1, mid, mn=INT_MAX;
    while(l<=h){
        mid=(l+h)/2;
        if(nums[l]<=nums[h]) return min(mn,nums[l]);
        else if(nums[l]<=nums[mid]){
            mn = min(mn,nums[l]);
            l=mid+1;
        }
        else if(nums[mid]<=nums[h]){
            mn = min(mn,nums[mid]);
            h = mid-1;
        }
    }
    return mn;
}

/*
    TC: O(logn)
    SC: O(1)
*/
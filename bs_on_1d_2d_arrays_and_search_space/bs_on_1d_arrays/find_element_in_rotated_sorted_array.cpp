#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) 
    and a target value k. Now the array is rotated at some pivot point unknown to you. 
    Find the index at which k is present and if k is not present return -1.

    Examples
    Example 1:
    Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
    Result: 4
    Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. 
    Thus, we get output as 4, which is the index at which 0 is present in the array.

    Example 2:
    Input Format: arr = [4,5,6,7,0,1,2], k = 3
    Result: -1
    Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. 
    Thus, we get the output as -1.
*/

int search(vector<int>& nums, int target) {
    int l=0, h=nums.size()-1, mid;
    while(l<=h){
        mid=(l+h)/2;
        if(nums[mid]==target) return mid;
        else if(nums[l]<=nums[mid]){
            if (target>=nums[l] && target<=nums[mid]) h=mid-1;
            else l=mid+1;
        }
        else if(nums[h]>=nums[mid]){
            if (target>=nums[mid] && target<=nums[h]) l=mid+1;
            else h=mid-1;
        }
    }
    return -1;
}

/*
    TC: O(logn)
    SC: O(1)
*/
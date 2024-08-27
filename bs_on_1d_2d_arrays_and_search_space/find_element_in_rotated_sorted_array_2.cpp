#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) 
    and a target value k. Now the array is rotated at some pivot point unknown to you. 
    Return True if k is present and otherwise, return False. 

    Example 1:
    Input Format:
    arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
    Result:
    True
    Explanation:
    The element 3 is present in the array. So, the answer is True.

    Example 2:
    Input Format:
    arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
    Result:
    False
    Explanation:
    The element 10 is not present in the array. So, the answer is False.

*/

bool search(vector<int>& nums, int target) {
    int l=0, h=nums.size()-1, mid;
    while(l<=h){
        mid = (l+h)/2;
        if(nums[mid]==target) return true;
        else if(nums[l]==nums[mid] && nums[mid]==nums[h]){     // edge case
            l++;
            h--;
        }
        else if(nums[l]<=nums[mid]){
            if(nums[l]<=target && target<=nums[mid]) h=mid-1;
            else l=mid+1;
        }
        else if(nums[mid]<=nums[h]){
            if(nums[mid]<=target && target<=nums[h]) l=mid+1;
            else h=mid-1;
        }
    }
    return false;
}

/*
    TC: O(logn)
    SC: O(1)

    Since there are duplicates in the array, there might be a case like this [3 1 2 3 3 3 3] where target = 1 and arr[l]=arr[mid]=arr[high]
    so we simple increment the low pointer and decrement the high pointer until the condition is no longer satisfied.
*/
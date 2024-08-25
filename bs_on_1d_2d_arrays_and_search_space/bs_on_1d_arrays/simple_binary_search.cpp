#include<bits/stdc++.h>
using namespace std;


// Recursive function
int bs(vector<int>& nums, int l, int h, int target){
    if(l>h) return -1;
    int mid = (l+h)/2;
    if(target<nums[mid]) return bs(nums, l, mid-1, target);
    else if(target>nums[mid]) return bs(nums, mid+1, h, target);
    else return mid;
}
/*
    TC: O(logn)
    SC: 1
*/

// iterative approach
int search(vector<int>& nums, int target) {
    int high=nums.size()-1, low=0, mid;
    while(low<=high){
        mid = (high+low)/2;
        if(target<nums[mid]) high=mid-1;
        else if(target>nums[mid]) low=mid+1;
        else return mid;
    }
    return -1;
    // return bs(nums, 0, nums.size()-1, target);
}
/*
    TC: O(logn)
    SC: 1
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans = {-1,-1};
    int l=0, h=nums.size()-1, mid;
    while(l<=h){
        mid = (l+h)/2;
        if(nums[mid]==target){
            ans[0] = mid;
            h = mid-1;
        }
        else if(nums[mid]>target){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(ans[0]==-1) return {-1,-1}; 
    l=0, h=nums.size()-1, mid;
    while(l<=h){
        mid = (l+h)/2;
        if(nums[mid]>target){
            h = mid-1;
        }
        else if(nums[mid]<target){
            l = mid+1;
        }
        else{
            ans[1]=mid;
            l=mid+1;
        }
    }
    return ans;
}
/*
    TC: O(2*logn)
    SC: O(1)
*/
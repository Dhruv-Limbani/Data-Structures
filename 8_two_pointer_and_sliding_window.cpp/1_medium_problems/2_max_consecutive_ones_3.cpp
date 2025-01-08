#include <bits/stdc++.h>
using namespace std;

// optimal approach - 1
int longestOnes(vector<int>& nums, int k) {
    int left=0, right=0, mx=0;
    while(right<nums.size()){
        if(nums[right]==0 && k) k--;
        else if(nums[right]==0) {
            while(nums[left]) left++;
            left+=1;
        }
        mx = max(mx, right-left+1);
        right++;
    }
    return mx;
}

// optimal approach - 2
int longestOnes(vector<int>& nums, int k) {
    int left=0, right=0, mx=0;
    while(right<nums.size()){
        if(nums[right]==0) k--;
        if(k<0) if(nums[left++]==0) k++;
        if(k>=0) mx = max(mx, right-left+1);
        right++;
    }
    return mx;
}
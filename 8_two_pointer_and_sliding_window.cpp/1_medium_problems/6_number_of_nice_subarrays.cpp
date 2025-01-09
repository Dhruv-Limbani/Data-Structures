#include <bits/stdc++.h>
using namespace std;

int less_than_equal_to_k(vector<int>& nums, int k){
    if(k<0) return 0;
    int left = 0, mx = 0, ct = 0, cto=0;
    for(int right = 0; right<nums.size(); right++){
        cto += nums[right]%2;
        while(cto>k) cto -= nums[left++]%2;
        if(cto==k) ct += (right-left+1);
        cout<<ct<<" ";
    }
    return ct;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    return less_than_equal_to_k(nums, k) - less_than_equal_to_k(nums, k-1);
}
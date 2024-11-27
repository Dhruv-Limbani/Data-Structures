#include<bits/stdc++.h>
using namespace std;

bool is_sum_under_threshold(vector<int>& nums, int threshold, int x){
    int sum = 0;
    for(auto it: nums){
        sum+=ceil((double)(it)/(double)(x));
        if(sum>threshold) return false;
    }
    return true;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int mx=nums[0];
    for(auto it: nums) mx = max(mx,it);
    int l=1, h=mx, mid, ans;
    while(l<=h){
        mid = (l+h)/2;
        if(is_sum_under_threshold(nums, threshold, mid)){
            ans = mid;
            h = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}
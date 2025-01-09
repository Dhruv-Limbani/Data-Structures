#include <bits/stdc++.h>
using namespace std;

int less_than_equal_to_k(vector<int>& nums, int k){
    if(k<=0) return 0;
    unordered_map<int, int> mp;
    int left = 0, ct = 0;
    for(int right=0; right<nums.size(); right++){
        mp[nums[right]]++;
        while(mp.size()>k){
            mp[nums[left]]--;
            if(!mp[nums[left]]) mp.erase(nums[left]);
            left++;
        }
        if(mp.size()<=k) ct+=(right-left+1);
    }
    return ct;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return  less_than_equal_to_k(nums, k) - less_than_equal_to_k(nums, k-1);
}
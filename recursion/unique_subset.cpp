#include<bits/stdc++.h>
using namespace std;

void unique_subsets(vector<vector<int>> &ans, vector<int> &subs, vector<int> nums, int k, int n){
    ans.push_back(subs);
    for(int i=k; i<n; i++){
        if(i!=k && nums[i]==nums[i-1]) continue;
        subs.push_back(nums[i]);
        unique_subsets(ans, subs, nums, i+1, n);
        subs.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> subs;
    sort(nums.begin(), nums.end());
    unique_subsets(ans,subs,nums,0,nums.size());
    return ans;
}
#include <bits/stdc++.h>
using namespace std;

void permutations(vector<vector<int>> &perms, vector<int> nums, int k){
    if(k==nums.size()) perms.push_back(nums);
    else{
        for(int i=k; i<nums.size(); i++){
            swap(nums[k],nums[i]);
            permutations(perms,nums,k+1);
            swap(nums[k],nums[i]);
        }
    }

}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    permutations(ans, nums, 0);
    return ans;
}


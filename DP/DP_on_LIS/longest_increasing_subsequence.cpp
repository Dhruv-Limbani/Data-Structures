#include<bits/stdc++.h>
using namespace std;

// dp memiozation
int lengthOfLIS(vector<int>& nums, vector<vector<int>> &dp, int ind, int prev_ind){
    if(ind>=nums.size()) return 0;
    if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    int not_take = lengthOfLIS(nums, dp, ind+1,prev_ind), take = 0;
    if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
        take = 1 + lengthOfLIS(nums, dp, ind+1,ind);
    }
    return dp[ind][prev_ind+1] = max(take, not_take);
}

// tabulation
int lengthOfLIS(vector<int>& nums) {
    vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1,0));
    for(int ind=nums.size()-1; ind>=0; ind--){
        for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
            int not_take = dp[ind+1][prev_ind+1], take = 0;
            if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                take = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prev_ind+1] = max(take, not_take);
        }
    }
    return dp[0][0];
}

//space optimization
int lengthOfLIS(vector<int>& nums) {
    vector<int> prev(nums.size()+1,0);
    for(int ind=nums.size()-1; ind>=0; ind--){
        vector<int> curr=prev;
        for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
            int not_take = prev[prev_ind+1], take = 0;
            if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                take = 1 + prev[ind+1];
            }
            curr[prev_ind+1] = max(take, not_take);
        }
        prev = curr;
    }
    return prev[0];
}


// approach two: dp[i] indicates length of LIS ending with element at index i
int lengthOfLIS(int n, vector<int>& arr) {
    vector<int> dp(n, 1), prev(n,-1);
    for(int i=0; i<n; i++){
        for(int p=0; p<=i-1; p++){
            if(arr[p]<arr[i] && dp[i]<1+dp[p]){
                dp[i] = 1+dp[p];
                prev[i] = p;
            }
        }
    }
    int mx = 1;
    for(int i=0; i<n; i++){
        mx = max(mx,dp[i]);
    }
    return mx;
}


// approach 3: binary search
void find_replacement_and_replace(vector<int> &ans, int x){
    int low=0, high=ans.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(ans[mid]>=x) high = mid-1;
        else low = mid+1;
    }
    ans[high+1] = x;
}
int lengthOfLIS(vector<int>& nums) {
    // vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
    // return lengthOfLIS(nums, dp, 0, -1);
    vector<int> ans;
    for(auto it: nums){
        if(ans.size()){
            if(it>ans.back()) ans.push_back(it);
            else find_replacement_and_replace(ans, it);
        }
        else ans.push_back(it);
    }
    return ans.size();
}

/*
    Solution 2: Greedy with Binary Search

    Let's construct the idea from following example.
    
    Consider the example nums = [2, 6, 8, 3, 4, 5, 1], let's try to build the increasing subsequences starting with an empty one: sub1 = [].
    
    Let pick the first element, sub1 = [2].
    
    6 is greater than previous number, sub1 = [2, 6]
    
    8 is greater than previous number, sub1 = [2, 6, 8]
    
    3 is less than previous number, we can't extend the subsequence sub1, but we must keep 3 because in the future there 
    may have the longest subsequence start with [2, 3], sub1 = [2, 6, 8], sub2 = [2, 3].
    
    With 4, we can't extend sub1, but we can extend sub2, so sub1 = [2, 6, 8], sub2 = [2, 3, 4].
    
    With 5, we can't extend sub1, but we can extend sub2, so sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5].
    
    With 1, we can't extend neighter sub1 nor sub2, but we need to keep 1, so sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5], sub3 = [1].
    
    Finally, length of longest increase subsequence = len(sub2) = 4.
    
    In the above steps, we need to keep different sub arrays (sub1, sub2..., subk) which causes poor performance. 
    But we notice that we can just keep one sub array, when new number x is not greater than the last element of the subsequence sub, we do binary search to find the smallest element >= x in sub, and replace with number x.
    
    Let's run that example nums = [2, 6, 8, 3, 4, 5, 1] again:
    
    Let pick the first element, sub = [2].
    
    6 is greater than previous number, sub = [2, 6]
    
    8 is greater than previous number, sub = [2, 6, 8]
    
    3 is less than previous number, so we can't extend the subsequence sub. 
    We need to find the smallest number >= 3 in sub, it's 6. Then we overwrite it, now sub = [2, 3, 8].
    
    4 is less than previous number, so we can't extend the subsequence sub. We overwrite 8 by 4, so sub = [2, 3, 4].
    
    5 is greater than previous number, sub = [2, 3, 4, 5].
    
    1 is less than previous number, so we can't extend the subsequence sub. We overwrite 2 by 1, so sub = [1, 3, 4, 5].
    
    Finally, length of longest increase subsequence = len(sub) = 4.
*/
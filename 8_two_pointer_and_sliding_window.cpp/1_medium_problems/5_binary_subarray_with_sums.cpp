#include <bits/stdc++.h>
using namespace std;

int less_than_equal_to_goal(vector<int>& nums, int goal) {
    if(goal<0) return 0;
    int left = 0, right = 0, ct = 0, sum=0;
    while(right<nums.size()){
        if(nums[right]) sum++;
        while(sum>goal) if(nums[left++]) sum--;
        if(sum<=goal) ct+=(right-left+1);
        right++;
    }
    return ct;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return less_than_equal_to_goal(nums, goal) - less_than_equal_to_goal(nums, goal-1);
}
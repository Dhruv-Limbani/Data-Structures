#include<bits/stdc++.h>
using namespace std;

/*
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
    and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation: 
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    
    Notice that the order of the output and the order of the triplets does not matter.
    
    Example 2:

    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.
*/

vector<vector<int>> brute_force(vector<int>& nums) {
    int s = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    for(int i=0; i<=s-3; i++){
        for(int j=i+1; j<=s-2; j++){
            for(int k=j+1; k<=s-1; k++){
                if(nums[i]+nums[j]+nums[k]) continue;
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*
    Time Complexity: O(N^3 * log(no. of unique triplets)), where N = size of the array.
    Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes 
    O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity
     of sorting as we are just sorting 3 elements every time.

    Space Complexity: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.
*/

vector<vector<int>> better_approach_1(vector<int>& nums) {
    int s = nums.size();
    set<vector<int>> st;
    for(int i=0; i<=s-3; i++){
        int two_sum_target = -nums[i];
        set<int> hashset;
        for(int j=i+1; j<s; j++){
            int rem = two_sum_target - nums[j];
            if(hashset.find(rem) != hashset.end()){
                vector<int> temp = {nums[i], nums[j], rem};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            else hashset.insert(nums[j]); 
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*
    in the above algo we iterate from i=0 to n-3
    at each iteration we perform two sum algorithm for target = 0 - nums[i]
    that means we are looking for two numbers nums[j] & nums[k] from i+1 to n whose sum equals to -nums[i]
    so that overall sum of nums[i] + nums[j] + nums[k] = zero

    below algo has slight modification.
    at each iteration we are looking for a number which is equal to 0 - nums[i] - nums[j]

    we are using hashset in both approaches
*/

vector<vector<int>> better_approach_2(vector<int>& nums) {
    int s = nums.size();
    set<vector<int>> st;
    for(int i=0; i<=s-3; i++){
        set<int> hashset;
        for(int j=i+1; j<s; j++){
            int rem = -(nums[i]+nums[j]);
            if(hashset.find(rem) != hashset.end()){
                vector<int> temp = {nums[i], nums[j], rem};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            else hashset.insert(nums[j]); 
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
/*
    Complexity:
        Time : O(n^2*log(no. of unique triplets)) where m is remaining rhs elements at each iteration on which two sum algo is executed
        Space: O(2* no. of unique triplets) + O(n)
*/

vector<vector<int>> optimal(vector<int>& nums) {
    int s = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i=0; i<=s-3; i++){
        if(i!=0 && nums[i]==nums[i-1]) continue;
        int j=i+1,k=s-1;
        while(j<k){
            if(nums[i] + nums[j] + nums[k] == 0){
                ans.push_back({nums[i],nums[j],nums[k]});
                j++,k--;
                while(nums[j]==nums[j-1] && j<k) j++;
                while(nums[k]==nums[k+1] && j<k) k--;
            }
            else if(nums[i]+nums[j]+nums[k] > 0) k--;
            else j++;   
        }
    }
    return ans;
}

/*
    The steps are as follows:

    First, we will sort the entire array.
    We will use a loop(say i) that will run from 0 to n-1. This i will represent the fixed pointer. 
    In each iteration, this value will be fixed for all different values of the rest of the 2 pointers. 
    
    Inside the loop, we will first check if the current and the previous element is the same and 
    if it is we will do nothing and continue to the next value of i.
    
    After that, there will be 2 moving pointers i.e. j(starts from i+1) and k(starts from the last index). 
    The pointer j will move forward and the pointer k will move backward until they cross each other while the value of i will be fixed.
    
    Now we will check the sum i.e. arr[i]+arr[j]+arr[k].
    If the sum is greater, then we need lesser elements and so we will decrease the value of k(i.e. k--). 
    If the sum is lesser than the target, we need a bigger value and so we will increase the value of j (i.e. j++). 
    If the sum is equal to the target, we will simply insert the triplet i.e. arr[i], arr[j], arr[k] 
    into our answer and move the pointers j and k skipping the duplicate elements(i.e. by checking the adjacent elements 
    while moving the pointers).
    
    Finally, we will have a list of unique triplets.

    Complexity:
        Time : O(nlogn) + O(n^2)
        Space: O(no. of unique triplets) This space is only used to store the answer. 
        We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/
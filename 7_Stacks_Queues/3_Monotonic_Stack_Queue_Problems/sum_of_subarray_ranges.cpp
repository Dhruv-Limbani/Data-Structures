#include<bits/stdc++.h>
using namespace std;

// previous smaller element and next smaller or equal element
vector<pair<int,int>> get_dist_from_pse_nse(vector<int>& nums){
    int n = nums.size();
    vector<pair<int,int>> ans;
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        if(!st.empty()) ans.push_back({i-st.top(),-1});
        else ans.push_back({i+1,-1});
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        if(!st.empty()) ans[i].second = st.top()-i;
        else ans[i].second = n-i;
        st.push(i);
    }
    return ans;
}

// previous greater element and next greater or equal element
vector<pair<int,int>> get_dist_from_pge_nge(vector<int>& nums){
    int n = nums.size();
    vector<pair<int,int>> ans;
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
        if(!st.empty()) ans.push_back({i-st.top(),-1});
        else ans.push_back({i+1,-1});
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
        if(!st.empty()) ans[i].second = st.top()-i;
        else ans[i].second = n-i;
        st.push(i);
    }
    return ans;
}

// sum of subarray mins
long long sum_of_subarray_mins(vector<int>& nums){
    vector<pair<int,int>> dist = get_dist_from_pse_nse(nums);
    long long sum=0;
    for(int i=0; i<nums.size(); i++){
        sum += (long long)dist[i].first*dist[i].second*nums[i];
    }
    return sum;
}

// sum of subarray maxs
long long sum_of_subarray_maxs(vector<int>& nums){
    vector<pair<int,int>> dist = get_dist_from_pge_nge(nums);
    long long sum=0;
    for(int i=0; i<nums.size(); i++){
        sum += (long long)dist[i].first*dist[i].second*nums[i];
    }
    return sum;
}

// sum of subarray ranges
long long subArrayRanges(vector<int>& nums) {
    return sum_of_subarray_maxs(nums) - sum_of_subarray_mins(nums); 
}

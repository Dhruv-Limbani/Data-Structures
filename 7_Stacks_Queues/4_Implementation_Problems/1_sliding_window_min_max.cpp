#include<bits/stdc++.h>
using namespace std;

// sliding window max - approach 1
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
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<pair<int,int>> dist = get_dist_from_pge_nge(nums);
    vector<int> ans;
    for(int i=0; i<nums.size(); i++){
        dist[i].first=dist[i].first>k?0:k-dist[i].first;
        dist[i].second=dist[i].second>k?0:k-dist[i].second;
        int num_max = k-dist[i].first-dist[i].second;
        while(num_max>0){
            ans.push_back(nums[i]);
            num_max--;
        }
    }
    return ans;
}

// sliding window max - approach 2
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;
    for(int i=0; i<nums.size(); i++){
        while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) ans.push_back(nums[dq.front()]);
        if(i+1-dq.front()==k) dq.pop_front();
    }
    return ans;
}


// sliding window min - approach -1
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
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<pair<int,int>> dist = get_dist_from_pse_nse(nums);
    vector<int> ans;
    for(int i=0; i<nums.size(); i++){
        dist[i].first=dist[i].first>k?0:k-dist[i].first;
        dist[i].second=dist[i].second>k?0:k-dist[i].second;
        int num_max = k-dist[i].first-dist[i].second;
        while(num_max>0){
            ans.push_back(nums[i]);
            num_max--;
        }
    }
    return ans;
}
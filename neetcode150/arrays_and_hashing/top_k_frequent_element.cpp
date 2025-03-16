#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            
            unordered_map<int, int> mp;
            for(auto it: nums) mp[it]++;
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
            for(auto it: mp){
                heap.push({it.second, it.first});
                if(heap.size()>k) heap.pop();
            }
    
            vector<int> ans;
            for(int i=0; i<k; i++){
                ans.push_back(heap.top().second);
                heap.pop();
            }
            return ans;
            
        }
        vector<int> topKFrequent(vector<int>& nums, int k) {
        
            unordered_map<int, int> mp;
            for(auto it: nums) mp[it]++;
            
            vector<vector<int>> freq(nums.size()+1);
    
            for(auto it: mp){
                freq[it.second].push_back(it.first);
            }
    
            vector<int> ans;
    
            for(int i=freq.size()-1; i>0; i--){
                for(int j: freq[i]){
                    ans.push_back(j);
                    if(ans.size()==k) return ans;
                }
            }
            
            return ans;
        }
};
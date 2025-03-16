#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<vector<int>, vector<string>> mp;
            for(auto str: strs){
                vector<int> v(26,0);
                for(auto it: str) v[it-'a']++;
                mp[v].push_back(str); 
            }
            vector<vector<string>> ans;
            for(auto it: mp){
                ans.push_back(it.second);
            }
            return ans;
        }
};
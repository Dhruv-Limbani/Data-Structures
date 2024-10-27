#include<bits/stdc++.h>
using namespace std;

void unique_combs(vector<vector<int>> &ans, vector<int> comb, vector<int> arr, int sum, int i, int k){
    if(sum==k){
        ans.push_back(comb);
    }
    if (sum<k && i<arr.size()) {
        comb.push_back(arr[i]);
        unique_combs(ans, comb, arr, sum+arr[i], i, k);
        comb.pop_back();
        unique_combs(ans, comb, arr, sum, i+1, k);
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> comb;
    unique_combs(ans, comb, candidates, 0, 0, target);
    return ans;
}


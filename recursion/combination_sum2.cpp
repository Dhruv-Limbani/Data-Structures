#include<bits/stdc++.h>
using namespace std;

void unique_combs(vector<vector<int>> &ans, vector<int> &comb, vector<int> arr, int sum, int i, int k){
    if(sum==k){
        ans.push_back(comb);
        return;
    }
    else if(sum<k){
        for(int j=i; j<arr.size(); j++){
            if(j!=i && arr[j]==arr[j-1]) continue;
            comb.push_back(arr[j]);
            unique_combs(ans, comb, arr, sum+arr[j], j+1, k);
            comb.pop_back();
        }
    }

}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> comb;
    sort(candidates.begin(),candidates.end());
    unique_combs(ans, comb, candidates, 0, 0, target);
    return ans;
}
#include<bits/stdc++.h>
using namespace std;
// if sum of all elements is odd return false else check for subset with sum == total_sum/2

bool canPartition(vector<int>& arr) {
    int s=0;
    for(auto it: arr) s+=it;
    if(s%2) return false;
    int target = s/2;
    vector<int> prev(target+1,0);
    int n = arr.size();
    if(arr[0]<=target) prev[arr[0]] = 1;
    prev[0] = 1;
    for(int i=1; i<n; i++){
        vector<int> curr(target+1,0);
        curr[0] = 1;
        for(int t=1; t<=target; t++){
            if(t-arr[i]>=0) curr[t] = prev[t-arr[i]];
            curr[t] = curr[t] || prev[t];
        }
        prev = curr;
    }
    return prev[target];
}
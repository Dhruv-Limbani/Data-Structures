#include <bits/stdc++.h>
using namespace std;

// striver - fruit basket
int totalFruits(vector<int> &arr, int k) {
    int left = 0, right =0, mx = 0;
    unordered_map<int, int> mp;
    while(right<arr.size()){
        mp[arr[right]]++;
        if(mp.size()<=k) mx = max(mx, right-left+1);
        if(mp.size()>k){
            mp[arr[left]]--;
            if(!mp[arr[left]]) mp.erase(arr[left]);
            left++;
        }
        right++;
    }
    return mx;
}
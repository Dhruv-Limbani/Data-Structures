#include<bits/stdc++.h>
using namespace std;

bool is_split_possible(vector<int>& nums, int k, int x){
    int cs = 0, ct = 0;
    for(auto it: nums){
        if(cs+it<=x) cs+=it;
        else{
            cs=it;
            ct++;
            if(ct>k) return false;
        }
    }
    if(0<cs && cs<=x) ct++;
    if(ct>k) return false;
    return true;

}
int splitArray(vector<int>& nums, int k) {
    int l=nums[0], h=0, mid;
    for (auto it : nums) {
        l = max(l, it);
        h += it;
    }
    while(l<=h){
        mid = (l+h)/2;
        if(is_split_possible(nums,k,mid)){
            h = mid-1;
        }
        else l = mid+1;
    }
    return h+1;        
}
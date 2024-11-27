#include<bits/stdc++.h>
using namespace std;

bool is_possible(vector<int>& weights, int days, int x){
    int ct=1, load = 0;
    for(auto it: weights){
        if(load+it <= x) load+=it;
        else{
            ct++;
            load=it;
        }
        if(ct>days) return false;
    }
    return true;
}
int shipWithinDays(vector<int>& weights, int days) {
    int l=weights[0],h=0,mid,ans;
    for(auto it: weights) {
        h+=it;
        l = max(l, it);
    }
    while(l<=h){
        mid = (l+h)/2;
        if(is_possible(weights, days, mid)){
            ans = mid;
            h = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}
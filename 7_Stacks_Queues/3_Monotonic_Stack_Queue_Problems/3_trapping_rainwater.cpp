#include<bits/stdc++.h>
using namespace std;

// prefix max
int trap(vector<int>& height) {
    vector<int> lm;
    int mx=0, total=0;
    for(auto it: height){
        mx = max(it, mx);
        lm.push_back(mx);
    }
    mx = 0;
    for(int i=height.size()-1; i>=0; i--){
        mx = max(mx, height[i]);
        total += max(min(mx,lm[i])-height[i],0);
    }
    return total;
}

// two pointers
int trap(vector<int>& height) {
    int l=0, r=height.size()-1, lm=0, rm=0, total=0;
    while(l!=r){
        if(height[l]<=height[r]){
            lm = max(height[l],lm);
            total += (lm-height[l]);
            l++;
        }
        else{
            rm = max(height[r],rm);
            total += (rm-height[r]);
            r--;
        }
    }
    return total;
}
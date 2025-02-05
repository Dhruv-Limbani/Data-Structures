#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int l=0, r=height.size()-1, lm=0, rm=0, mx=0;
    while(l<=r){
        int wd = r-l, ht = min(height[l],height[r]);
        mx = max(mx, wd*ht);
        (height[l]<=height[r])?l++:r--;
    }
    return mx;
}
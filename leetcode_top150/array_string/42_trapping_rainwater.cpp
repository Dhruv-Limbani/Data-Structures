#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> right(n,0);
    int last_wall = height[n-1], trapped=0;
    for(int i=n-1; i>=0; i--){
        if(height[i]<=last_wall) right[i] = last_wall-height[i];
        else last_wall = height[i];
    }
    last_wall = height[0];
    for(int i=0; i<n; i++){
        if(height[i]<=last_wall) trapped += min(right[i], last_wall-height[i]);
        else last_wall = height[i];
    }
    return trapped;
}

/*
    TC: O(n)
    SC: O(n)
*/

/*
    A better solution with SC: O(1) exists. (uses Up-Down-Peak)
*/
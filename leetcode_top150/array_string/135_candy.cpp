#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> elevation_from_right(n,1);
    for(int i=n-2; i>=0; i--){
        elevation_from_right[i] = ratings[i]>ratings[i+1]?(elevation_from_right[i+1] + 1):1;
    }
    int num_candies = max(1,elevation_from_right[0]), elevation_from_left=1;
    for(int i=1; i<n; i++){
        elevation_from_left = ratings[i]>ratings[i-1]?(elevation_from_left+1):1;
        num_candies += max(elevation_from_left,elevation_from_right[i]);
    }
    return num_candies;
}

/*
    TC: O(n)
    SC: O(n)
*/

/*
    A better solution with SC: O(1) exists. (uses Up-Down-Peak)
*/
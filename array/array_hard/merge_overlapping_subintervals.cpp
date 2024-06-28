#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> optimal_approach(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    int n = intervals.size(),ct=-1;
    sort(intervals.begin(),intervals.end());
    ans.push_back(intervals[0]);
    for(int i=1; i<n; i++){
        if(ans.back()[1]>=intervals[i][0]){
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

/*
    Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
    Reason: Sorting the given array takes  O(N*logN) time complexity. 
    Now, after that, we are just using a single loop that runs for N times. So, the time complexity will be O(N).

    Space Complexity: O(N), as we are using an answer list to store the merged intervals. 
    Except for the answer array, we are not using any extra space.
*/
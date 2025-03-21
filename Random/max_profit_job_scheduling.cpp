#include <bits/stdc++.h>
using namespace std;


struct job{
    int start, end, w, idx;
};
int latest_non_overlapping(struct job jobs[], int size, int key){
    int low = 0, high = size-1, mid;
    while(low<=high){
        mid = (low+high)/2;
        if(jobs[mid].end<=key) low = mid+1;
        else high = mid-1;
    }
    return low-1;
}
bool static comp(struct job j1, struct job j2){
    if(j1.end<j2.end) return true;
    else return false;
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    struct job jobs[n];
    for(int i=0; i<n; i++){
        jobs[i].start = startTime[i];
        jobs[i].end = endTime[i];
        jobs[i].w = profit[i];
        jobs[i].idx = i;
    }
    sort(jobs,jobs + n, comp);
    int size = jobs[n-1].end+1, mx=0, i=0;
    vector<int> dp(n+1,0);
    vector<int> schedule;
    for(int i=0; i<n; i++){
        int j = latest_non_overlapping(jobs,n,jobs[i].start);
        if(dp[j+1]+jobs[i].w)
        dp[i+1] = max(dp[i], dp[j+1]+jobs[i].w);
    }
    return dp[n];
}
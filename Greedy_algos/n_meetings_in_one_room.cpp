#include<bits/stdc++.h>
using namespace std;


// leetcode variant: https://leetcode.com/problems/maximum-length-of-pair-chain/description/
static bool comp2(vector<int> p1, vector<int> p2){
    if(p1[1]<p2[1]) return true;
    else return false;
}
int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), comp2);
    int ct=1, last=pairs[0][1];
    for(int i=1; i<pairs.size(); i++){
        if(pairs[i][0]>last){
            ct++;
            last = pairs[i][1];
        }
    }
    return ct;
}

// original N meetings in a room

struct meeting {
    int start;
    int end;
    int pos;
};

bool static comp1(struct meeting m1, struct meeting m2){
    if(m1.end<m2.end) return true;
    else if(m1.end>m2.end) return false;
    else if(m1.pos<m2.pos) return true;
    else return false;
}

int maxMeetings(vector<int> start, vector<int> end) {
    int n = start.size();
    struct meeting meets[n];
    for(int i=0; i<n; i++){
        meets[i].start = start[i];
        meets[i].end = end[i];
        meets[i].pos = i;
    }
    
    sort(meets, meets + n, comp1);
    
    int ct = 1, last = meets[0].end;
    vector<int> meetings_order = {meets[0].pos};
    
    for(int i=1; i<n; i++){
        if(meets[i].start>last){
            meetings_order.push_back(meets[i].pos);
            ct++;
            last = meets[i].end;
        }
    }
    
    return ct;
}

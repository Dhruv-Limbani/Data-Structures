#include<bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> &stalls, int k, int x){
    k--;
    int ls = 0;
    for(int i=1; i<stalls.size(); i++){
        if(stalls[i] - stalls[ls] >= x){
            k--;
            if(k==0) return true;
            ls=i;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int l = 1, h = stalls[n-1] - stalls[0], ans;
    while(l<=h){
        int mid = (l+h)/2;
        if(is_possible(stalls,k,mid)){
            ans = mid;
            l = mid+1;
        }
        else h = mid-1;
    }
    return ans;
}
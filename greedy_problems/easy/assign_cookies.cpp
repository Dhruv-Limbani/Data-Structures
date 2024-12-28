#include <bits/stdc++.h>
using namespace std;

// O(nlogn) + O(mlogm) + O(m)
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i=0, j=0, ct=0;
    while(i<g.size() && j<s.size()){
        if(s[j]>=g[i]){
            ct++;
            i++;
        }
        j++;
    }
    return ct;
}
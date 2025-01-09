#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    vector<int> hash(256, 0);
    for(auto it: t) hash[it]++;
    int left = 0, right = 0, mn = INT_MAX, i=1, j=0, ct=0;
    while(right<s.size()){
        hash[s[right]]--;
        if(hash[s[right]]>=0) ct++;
        while(ct==t.size()){
            if(right-left+1<mn){
                mn = right-left+1;
                i = left;
                j = right;
            }
            hash[s[left]]++;
            if(hash[s[left]]>0) ct--;
            left++;
        }
        right++;
    }
    string ans;
    while(i<=j) ans += s[i++];
    return ans;
}
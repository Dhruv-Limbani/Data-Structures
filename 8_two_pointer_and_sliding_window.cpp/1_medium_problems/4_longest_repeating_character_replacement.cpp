#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int left = 0, right = 0, mx = 0, mxf=0, hash[26]={0};
    while(right<s.size()){
        hash[s[right]-'A']++;
        mxf = max(hash[s[right]-'A'],mxf);
        if(right-left+1-mxf<=k) mx = max(right-left+1,mx);
        else hash[s[left++]-'A']--;
        right++;
    }
    return mx;
}
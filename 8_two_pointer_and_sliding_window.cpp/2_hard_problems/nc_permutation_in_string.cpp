#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    vector<int> hash(256, 0);
    for(auto it: s1) hash[it]++;
    int left = 0, right = 0, ct=0;
    while(right<s2.size()){
        hash[s2[right]]--;
        if(hash[s2[right]]>=0) ct++;
        while(ct==s1.size()){
            if(right-left+1==s1.size()) return true;
            hash[s2[left]]++;
            if(hash[s2[left]]>0) ct--;
            left++;
        }
        right++;
    }
    return false;
}
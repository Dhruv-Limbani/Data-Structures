#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int i=0,j=0,mx=0;
    while(j<s.size()){
        if(st.find(s[j])==st.end()) st.insert(s[j]);
        else{
            mx = max(mx, j-i);
            while(s[i]!=s[j]) st.erase(s[i++]);
            i+=1;
        }
        j++;
    }
    mx = max(mx, j-i);
    return mx;
}
#include <bits/stdc++.h>
using namespace std;

// optimal approach 1
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

// optimal approach 2
int lengthOfLongestSubstring(string s) {
    vector<int> mpp(256,-1);
    int mx=0, j=0, i=0;
    while(i<s.size()){
        if(mpp[s[i]]!=-1){
            j= max(mpp[s[i]]+1,j);
        }
        mpp[s[i]]=i;
        mx = max(mx, i-j+1);
        i++;
    }
    return mx;
}
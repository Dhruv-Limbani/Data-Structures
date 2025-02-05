#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.size()!=t.size()) return false;
    vector<int> arr1(256,-1), arr2(256,-1);
    for(int i=0; i<s.size(); i++){
        if(arr1[s[i]]==-1 && arr2[t[i]]==-1){
            arr1[s[i]] = t[i];
            arr2[t[i]] = s[i];
        }
        else if(arr1[s[i]]!=t[i]) return false;
    }
    return true;
}
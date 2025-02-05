#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ref = strs[0], ans;
    int j=0, f=1;
    while(j<ref.size()){
        int i=0;
        for(i=1; i<strs.size(); i++){
            if(j>=strs[i].size() || ref[j]!=strs[i][j]) break;
        }
        if(i==strs.size()) ans += ref[j];
        else break;
        j++;
    }
    return ans;
}
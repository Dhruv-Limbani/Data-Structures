#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    string st;
    for(int i=0; i<num.length(); i++){
        while(k && st.size() && (int)st.back()>(int)num[i]){
            st.pop_back();
            k--;
        }
        if(st.size() || num[i]!='0') st.push_back(num[i]);
    }
    while(k-- && st.size()) st.pop_back();
    if (st.empty()) return "0";
    return st;
}
#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.size()!=goal.size()) return false;
    int n = s.size();
    while(n--){
        if(s==goal) return true;
        s += s[0];
        s.erase(0,1);
    }
    return false;

    // or 
    
    return s.size()==goal.size() && (s+s).find(goal)!=string::npos;
}
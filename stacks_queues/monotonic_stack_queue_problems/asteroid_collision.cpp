#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    list<int> st;
    for(auto it: asteroids){
        if(st.empty() || it>0){
            st.push_back(it);
            continue;
        }
        else if(it<0){
            while(!st.empty() && st.back()>0 && st.back()<-it) st.pop_back();
            if(!st.empty() && st.back()==-it) st.pop_back();
            else if(st.empty() || st.back()<0) st.push_back(it);
        }
    }
    vector<int> ans;
    for(auto it: st) ans.push_back(it);
    return ans;
}   
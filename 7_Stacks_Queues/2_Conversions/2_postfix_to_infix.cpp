#include<bits/stdc++.h>
using namespace std;

string postToInfix(string s) {
    stack<string> st1;
    string ans;
    for(int i=0; i<s.length(); i++){
        string temp;
        temp += s[i];
        if(isalpha(s[i]) || isdigit(s[i])) st1.push(temp);
        else{
            string b = st1.top();
            st1.pop();
            string a = st1.top();
            st1.pop();
            st1.push("(" + a + s[i] + b + ")");
        }
    }
    while(!st1.empty()){
        ans = st1.top() + ans;
        st1.pop();
    }
    return ans;
}
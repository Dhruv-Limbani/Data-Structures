#include<bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') return 2;
    else if (c == '/' || c == '*') return 1;
    else if (c == '+' || c == '-') return 0;
    else return -1;
}
string infixToPostfix(string s) {
    stack<char> st;
    string ans;
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='1' && c<='9')) ans += c;
        else if(c == ')'){
            while(st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(c == '(') st.push(c);
        else{
            while(!st.empty() && prec(st.top())>=prec(c)){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}
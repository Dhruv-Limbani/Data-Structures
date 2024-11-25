#include<bits/stdc++.h>
using namespace std;

int evaluate(int a, string c, int b){
    if(c=="+") return a+b;
    if(c=="-") return a-b;
    if(c=="*") return a*b;
    return a/b;
}
int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for(auto it: tokens){
        if(it=="+" || it=="-" || it=="*" || it=="/"){
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            s.push(evaluate(a,it,b));
        }
        else s.push(stoi(it));
    }
    return s.top();
}
#include<bits/stdc++.h>
using namespace std;

void generate(string s, int n, int n1, int n2, vector<string> &ans){
    if(s.length()==2*n) ans.push_back(s);
    else{
        if(n1!=n2) generate(s+")", n, n1, n2-1, ans);
        if(n1>0) generate(s+"(", n, n1-1, n2, ans);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generate("",n,n,n,ans);
    return ans;
}
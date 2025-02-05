#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int sum=0, st=0, ed=0, i=0;
        while(i<s.length()){
            sum += s[i]=='('?+1:-1;
            if(!((sum==1 && s[i]=='(') || sum==0)) ans += s[i];
            i++;
        }
        return ans;
    }
};

/*
    TC: O(N)
    SC: O(N)
*/


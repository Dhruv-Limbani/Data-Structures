#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isalnum(char c){
            return (c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z');
        }
        char lower(char c){
            if(c>='A' && c<='Z') return 'a' + c - 'A';
            return c;
        }
        bool isPalindrome(string s) {
            int i = 0, j = s.size()-1;
            while(i<j){
                while(i<s.size() && !isalnum(s[i])) i++;
                while(j>=0 && !isalnum(s[j])) j--;
                if(i>j || j<0 || i>=s.size()) break;
                if(lower(s[i])!=lower(s[j])) return false;
                i++;
                j--;
            }
            return true;
        }
};
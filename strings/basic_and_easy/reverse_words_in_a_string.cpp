#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(string &s, int start, int end){
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        int i=0, j=0, k=0, len = s.length();
        reverse(s,0,len-1);
        while(j<len){
            while(j<len && s[j]==' ') j++;
            if(j==len) break;
            while(j<len && s[j]!=' ') s[i++] = s[j++];
            reverse(s,k,i-1);
            s[i] = ' ';
            k=++i;
            j++;
        }
        s.resize(i-1);
        return s;
    }
};

/*
https://leetcode.com/problems/reverse-words-in-a-string/solutions/4884894/best-explanation-with-photos-without-extra-space-beats-100-in-time-95-in-space/
*/
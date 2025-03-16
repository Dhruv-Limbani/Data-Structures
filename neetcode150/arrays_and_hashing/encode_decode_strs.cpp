#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        string encode(vector<string>& strs) {
            string encoded;
            for(auto str: strs) encoded += to_string(str.size()) + "#" + str;
            cout<<encoded<<endl;
            return encoded;
        }
    
        int get_len(string s, int i, int j){
            string len;
            while(i<=j){
                len+=s[i];
                i++;
            }
            return stoi(len);
        }
    
        string get_substr(string s, int i, int j){
            string temp;
            while(i<=j){
                temp+=s[i];
                i++;
            }
            return temp;
        }
    
        vector<string> decode(string s) {
            vector<string> decoded_strs;
            int i=0, n=s.size();
            while(i<n){
                int j=i;
                while(j<n && s[j]!='#') j++;
                int len = get_len(s, i, j-1);
                i=j+1;
                j=i+len-1;
                decoded_strs.push_back(get_substr(s, i, j));
                i=j+1;
            }
            return decoded_strs;
        }
};
    
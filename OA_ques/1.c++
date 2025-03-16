#include<bits/stdc++.h>
using namespace std;

/*
 * Complete the 'calculateScore' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING text
 *  2. STRING prefixString
 *  3. STRING suffixString
 */

 string get_sub_str(string s, int i, int j){
    string temp;
    while(i<=j){
        temp+=s[i];
        i++;
    }
    return temp;
}

string calculateScore(string text, string prefixString, string suffixString) {
    int nt = text.size(), np = prefixString.size(), ns = suffixString.size();
    vector<vector<int>> dp1(nt, vector<int>(np, 0)), dp2(nt, vector<int>(ns,0));
    int s_idx = 0, e_idx = 0, mx1=0, mx2=0;
    for(int i=0; i<nt; i++){
        for(int j=0; j<np; j++){
            if(text[i]==prefixString[j]){
                dp1[i][j] = 1;
                if(i-1>=0 && j-1>=0){
                    dp1[i][j] += dp1[i-1][j-1];
                }
            }
            if(j==np-1){
                if(mx1<dp1[i][j]){
                    mx1 = dp1[i][j];
                    s_idx = i-dp1[i][j] + 1;
                }
            }
        }
    }
    for(int i=0; i<nt; i++){
        for(int j=0; j<ns; j++){
            if(text[i]==suffixString[j]){
                dp2[i][j] = 1;
                if(i-1>=0 && j-1>=0){
                    dp2[i][j] += dp2[i-1][j-1];
                }
            }
            if(mx2<dp2[i][j] && dp2[i][j]==j+1){
                mx2 = dp2[i][j];
                e_idx = i;
            }
        }
    }
    if(s_idx>e_idx){
        if (text[s_idx]<text[e_idx]) e_idx = s_idx + mx1 - 1;
        else s_idx = e_idx - mx1 + 1;
    }
    
    string ans = get_sub_str(text, s_idx, e_idx);
    return ans;
}
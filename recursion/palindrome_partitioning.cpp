#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){
    while(i<=j) if (s[i++]!=s[j--]) return false;
    return true;
}
void partitions(vector<vector<string>> &v, vector<string> v1, string s, int i){
    if(i==s.size())  v.push_back(v1);
    for(int k=i; k<s.size(); k++){
        if(isPalindrome(s,i,k)){
            v1.push_back(s.substr(i,k-i+1));
            partitions(v,v1,s,k+1);
            v1.pop_back();
        }
    }
    
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> v;
    vector<string> v1;
    partitions(v,v1,s,0);
    return v;
}

/*
    Time Complexity: O( (2^n) *k*(n/2) )

    Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated 
    is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  
    is the average length of the palindrome list.

    Space Complexity: O(k * x)

    Reason: The space complexity can vary depending upon the length of the answer. k is the average 
    length of the list of palindromes and if we have x such list of palindromes in our final answer. 
    The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
*/
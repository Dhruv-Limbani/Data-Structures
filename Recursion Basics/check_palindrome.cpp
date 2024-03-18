#include <bits/stdc++.h>
using namespace std;

bool is_alphanum(char c){
    return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9');
}

char to_lower(char c){
    return (c>='A' && c<='Z')?c+32:c;
}


// recursive approach
bool check_palindrome(string s, int i, int j, int l){
    if(i>=j) return true;
    while(!(is_alphanum(s[i]))){
        i++;
        if(i==l) break;
    } 
    while(!(is_alphanum(s[j]))){
        j--;
        if(j<0) break;
    }
    if(i==l && j<0) return true;
    if(to_lower(s[i])==to_lower(s[j])){
        return true && check_palindrome(s,i+1,j-1,l);
    }
    else return false;
}

bool check_palindrome_without_recursion(string s){
    int i=0, l=s.size();
    int j=l-1;
    while(i<j){
        while(!(is_alphanum(s[i]))){
            i++;
            if(i==l) break;
        } 
        while(!(is_alphanum(s[j]))){
            j--;
            if(j<0) break;
        }
        if(i==l && j==0) return true;
        if(!(to_lower(s[i++])==to_lower(s[j--]))) return false;
    }
    return true;
}


/*
    time complexity = O(n) -> actually takes n/2 time
    space complexity = O(1)
*/
int main()
{
    string s;
    getline(cin,s);
    cout<<"string: "<<s<<endl;
    cout<<check_palindrome(s,0,s.size()-1,s.size())<<endl;
    cout<<check_palindrome_without_recursion(s);
    return 0;
}
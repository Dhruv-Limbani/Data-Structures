#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of integers: [1, 2, 1, 3, 2] and we are given some queries: [1, 3, 4, 2, 10]. 
    For each query, we need to find out how many times the number appears in the array. 
    For example, if the query is 1 our answer would be 2, and if the query is 4 the answer will be 0.

    Brute Force:
    take each from query arr and compare it with each in int arr, if match then increase the counter.
    takes O(Q*N)

    Optimized approach (using hashing):
    1) Assume or find the highest possible number in query array
    2) Pre-storing : Declare hash array of the size equal to highest number + 1(for ease of referencing)
    3) Fetching : for each num in query array, fetch hash[num] and increase the value by 1

*/


vector<int> count_num_freq(int arr[], int n){
    vector<int> hash(13,0); // we assume 12 is the highest number
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    return hash;
}

vector<int> count_char_freq(string s, int n){
    vector<int> hash(26,0); // if s contains both upper case and lower case then adjust size accordingly
    for(int i=0; i<n; i++){
        hash[s[i]-'a']++; // if s contains only upper case then hash[s[i]-'A'], if it contains both then simply hash[s[i]] 
    }
    return hash;
}



int main()
{
    // int n,q;
    // cin>>n>>q;
    // int arr[n],qr[q];
    // for(int i=0; i<n; i++) cin>>arr[i];
    // for(int i=0; i<q; i++) cin>>qr[i];
    // vector<int> hash = count_num_freq(arr, n);
    // for(int i=0;i<q;i++){
    //     cout<<qr[i]<<"--"<<hash[qr[i]]<<endl;
    // }

    string s;
    cin>>s;
    int q;
    cin>>q;
    char qr[q];
    for(int i=0; i<q; i++) cin>>qr[i];
    vector<int> hash = count_char_freq(s, s.length());
    for(int i=0;i<q;i++){
        cout<<qr[i]<<"--"<<hash[qr[i]-'a']<<endl;
    }
    return 0;
}


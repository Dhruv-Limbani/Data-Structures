#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: You are given an array of ‘N’ integers. 
    You need to find the length of the longest sequence which contains the consecutive elements.\
    Input:
    A = [5, 8, 3, 2, 1, 4], N = 6
    Output:
    5
    Explanation: 
    The resultant sequence can be 1, 2, 3, 4, 5.    
    The length of the sequence is 5.
*/

int brute_force_approach(vector<int>&arr) {
    int n = arr.size();
    int mx=1;
    for(int i=0; i<n; i++){
        int ct = 0;
        for(int j=arr[i]; j<=arr[i]+n-1; j++){
            int f=0;
            for(auto it: arr){
                if(it==j){
                    f=1;
                    break;
                }
            }
            if(f) ct++;
            else break;
        }
        mx = max(mx,ct);
    }
    return mx;
}
/*
    TC: O(n^3)
    SC: O(1)
*/

int better_approach(vector<int>&arr) {
    int n = arr.size();
    sort(arr.begin(),arr.begin()+n);
    int i=0, j=1, mx=1, ct=1;
    while(j<n){
        while(arr[j]==arr[i] && j<n) j++;
        if(j==n) break;
        else if(arr[j]-arr[i]==1){
            ct++;
        }
        else{
            mx = max(mx,ct);
            ct=1;
        }
        i=j;
        j++;
    }
    mx = max(ct, mx);
    return mx;
}

/*
    TC: O(nlog(n) + n)
    SC: O(1)
*/

int optimal_approach(vector<int>&arr) {
    int n = arr.size(),mx=0,ct=0;
    unordered_set<int> s;
    for(auto it: arr) s.insert(it);
    for(auto it: s){
        if(s.find(it-1)==s.end()){
            int j=it,ct=1;
            while(s.find(j+1)!=s.end()){
                ct++;
                j++;
            }
            mx = max(ct,mx);
        }
    }
    return mx;
}

/*
    TC: O(N + 2N)
    SC: O(N)
*/
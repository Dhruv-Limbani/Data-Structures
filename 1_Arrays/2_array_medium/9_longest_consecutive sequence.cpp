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
    int mx=0;
    for(int i=0; i<n; i++){
        int ct = 0;
        int f=1, x=arr[i];
        do{
            f=0;
            for(int j=0; j<n; j++){
                if(arr[j]==x){
                    ct++;
                    x++;
                    f=1;
                    break;
                }
            }
        }while(f==1);
        mx = max(mx,ct);
    }
    return mx;
}
/*

    Algorithm:
    To begin, we will utilize a loop to iterate through each element one by one.
    Next, for every element x, we will try to find the consecutive elements like 
    x+1, x+2, x+3, and so on using the linear search algorithm in the given array.
    
    Within a loop, our objective is to locate the next consecutive element x+1. 
    
    If this element is found, we increment x by 1 and continue the search for x+2. 
    Furthermore, we increment the length of the current sequence (cnt) by 1. 
    
    This process repeats until step 2.2 occurs.

    If a specific consecutive element, for example, x+i, is not found, we will halt the search 
    for subsequent consecutive elements such as x+i+1, x+i+2, and so on. Instead, we will take 
    into account the length of the current sequence (cnt).
    
    Among all the lengths we get for all the given array elements, the maximum one will be the answer.

    TC: O(n^2)
    SC: O(1)
*/

int better_approach(vector<int>&arr) {
    int n = arr.size();
    sort(arr.begin(),arr.begin()+n);
    int i=0, j=1, mx=1, ct=1;
    while(j<n){
        while(j<n && arr[j]==arr[i]) j++;
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
    Algorithm:
    We will declare 2 variables, 

    ‘cnt’ → (to store the length of the current sequence), 
    ‘longest’ → (to store the maximum length).

    First, we will put all the array elements into the set data structure.
    For every element, x, that can be a starting number(i.e. x-1 does not exist in the set) we will do the following:
        We will set the length of the current sequence(cnt) to 1.
        
        Then, again using the set, we will search for the consecutive elements such as x+1, x+2, 
        and so on, and find the maximum possible length of the current sequence. 
        This length will be stored in the variable ‘cnt’.

    After that, we will compare ‘cnt’ and ‘longest’ and update the variable ‘longest’ 
    with the maximum value (i.e. longest = max(longest, cnt)).
    Finally, we will have the answer i.e. ‘longest’.

    TC: O(N + 2N)
    SC: O(N)
*/
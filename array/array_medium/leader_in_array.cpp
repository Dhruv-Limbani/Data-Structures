#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an array, print all the elements which are leaders.
    A Leader is an element that is greater than all of the elements on its right side in the array.
*/


vector<int> superiorElements(vector<int>&arr) {
    int n = arr.size();
    vector<int> ans;
    for(int i=n-1; i>=0; i--){
        int j=i+1;
        while(arr[i]>arr[j] && j<n) j++;
        if(j==n) ans.push_back(arr[i]);
    }
    return ans;
}

/*
    TC: O(N^2)
    SC: O(N) used to store ans
*/

vector<int> superiorElements(vector<int>&arr) {
    int n = arr.size();
    int mx=arr[n-1];
    vector<int> ans;
    ans.push_back(mx);
    for(int i=n-2; i>=0; i--){
        if(arr[i]>mx){
            ans.push_back(arr[i]);
            mx = arr[i];
        }
    }
    return ans;
}

/*
    We traverse from the end and keep track of max element
    if at any point i, an element arr[i] > max, that means arr[i] is one of the leaders so we add it to leaders array
    and update the max element

    TC: O(N)
    SC: O(N) used to store ans
*/


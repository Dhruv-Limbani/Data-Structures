#include<bits/stdc++.h>
using namespace std;

void get_subset_sums(vector<int> &ans, vector<int> arr, int k){
    if(k<arr.size()){
        // get the total number of subset sums
        int size = ans.size();
        // for each sum in subset sums, a new subset sum is created by adding the current element k to each of them
        // so if we already have n subset sums, we can create k more subsets by adding an element k to each subset.
        // so we have subset sums (without k) ... subset sums (with k), then the next k+1th element will be added to both combinations and so on
        for(int i=0; i<size; i++) ans.push_back(ans[i]+arr[k]);
        get_subset_sums(ans, arr, k+1);
    }
}

void get_subset_sums_2(vector<int> &ans, vector<int> arr, int sum, int k, int n){
    if(k<n){
        // include an element in subset and increment sum
        get_subset_sums_2(ans, arr, sum+arr[k], k+1, n);
        // not to include an element and the sum remains as it is 
        get_subset_sums_2(ans, arr, sum, k+1, n);
    }
    else ans.push_back(sum);
}

vector<int> subsetSums(vector<int> arr, int n) {
    // for version 1
    // vector<int> ans = {0};
    // get_subset_sums(ans, arr, 0);
    
    // for version 2
    vector<int> ans;
    get_subset_sums_2(ans, arr, 0, 0, n);

    // apply sorting if output is asked in sorted order
    return ans;
}

/*
    TC: O(2^n) + sorting(2^n.log(2^n))
    SC: O(2^n) // for storing the ans
*/
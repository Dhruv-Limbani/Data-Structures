#include<bits/stdc++.h>
using namespace std;


int brute_force_approach(vector<int>& nums, int k){
    int n = nums.size(), ct=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int t=i; t<=j; t++){
                sum+=nums[t];
            }
            if(sum==k)
                ct++;
        }
    }
    return ct;
}

/*
    TC: O(N^3)
    SC: O(1)
*/


int better_approach(vector<int>& nums, int k) {
    int n = nums.size(), ct=0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum+=nums[j];
            if(sum==k)
                ct++;
        }
    }
    return ct;
}

/*
    TC: O(N^2)
    SC: O(1)
*/

int optimal_approach(vector<int>& nums, int k) {
    int n = nums.size(), ct=0, sum=0;
    map<int,int> m;
    for(int i=0; i<n; i++){
        sum+=nums[i];
        if(sum==k) ct++;
        int rem = sum-k;
        if(m.find(rem)!=m.end()){
            ct+=m[rem];
        }
        if(m.find(sum)==m.end()) m[sum]=1;
        else m[sum]++;
    }
    return ct;
}

/*
    Check longest subarray with sum K problem in array easy module to understand the logic.
    TC: O(N*logN)
    SC: O(N)
*/
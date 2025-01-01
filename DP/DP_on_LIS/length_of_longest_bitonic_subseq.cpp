#include<bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(int n, vector<int> &arr) {
    vector<int> dp1(n,1), dp2(n,1);
    int mx = 0;

    // LIS from 0 to i
    for(int i=0; i<n; i++){
        for(int p=0; p<=i-1; p++){
            if(arr[p]<arr[i] && dp1[i]<1+dp1[p]){
                dp1[i] = 1+dp1[p];
            }
        }
    }

    // LIS from n-1 to i 
    for(int i=n-1; i>=0; i--){
        for(int p=n-1; p>i; p--){
            if(arr[p]<arr[i] && dp2[i]<1+dp2[p]){
                dp2[i] = 1+dp2[p];
            }
        }
        if(dp1[i]!=1 && dp2[i]!=1) mx = max(mx, dp1[i] + dp2[i] - 1);
    }
    return mx;
}
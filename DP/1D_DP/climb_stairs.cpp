#include<bits/stdc++.h>
using namespace std;

// recursive
int num_ways(int n){
    if(n==0 || n==1) return 1;
    return num_ways(n-1) + num_ways(n-2);
}

// DP - Tabulation
int climbStairs(int n) {
    vector<int> ways(n+1,1);
    for(int i=0; i<=n; i++){
        if(i-2>=0) ways[i] = ways[i-1] + ways[i-2];
    }
    return ways[n];
}

// space optimized
int climbStairs(int n) {
    int last=1, second_last=1;
    for(int i=2; i<=n; i++){
        int temp = last + second_last;
        second_last = last;
        last = temp;
    }
    return last;
}

/*
    DP recurrence relation:
    Key Idea: A step k can be reached either from the last step (k-1) or second last step (k-2). 
    So total number of ways to reach the step k = num_ways(k-1) + num_ways(k-2)
*/
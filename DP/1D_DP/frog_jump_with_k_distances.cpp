#include<bits/stdc++.h>
using namespace std;

// recursive approach
int minimizeCost(int n, int k, vector<int> &height){
    if(n==1) return 0;
    int min_cost = INT_MAX;
    for(int i=1; i<=k; i++){
        if(n-1-i>=0){
            min_cost = min(abs(height[n-1]-height[n-1-i]) + minimizeCost(n-i,k,height),min_cost);
        }
    }
    return min_cost;
}

//    DP - Tabulation/Memiozation    //

// recusrive
int minimize(int n, int k, vector<int> &height, vector<int> &cost){
    if(cost[n]!=-1) return cost[n];
    cost[n] = INT_MAX;
    for(int i=1; i<=k; i++){
        if(n-1-i>=0){
            cost[n] = min(abs(height[n-1]-height[n-1-i]) + minimize(n-i,k,height,cost),cost[n]);
        }
    }
    return cost[n];
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> cost(n+1,-1);
    cost[1] = 0;
    return minimize(n,k,height,cost);
}

// Iterative
int minimizeCost(int n, int k, vector<int> &height){
    vector<int> cost(n+1,0);
    for(int i=2; i<=n; i++){
        cost[i] = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-1-j >= 0){
                cost[i] = min(abs(height[i-1] - height[i-1-j]) + cost[i-j], cost[i]);
            }
        }
    }
    return cost[n];
}
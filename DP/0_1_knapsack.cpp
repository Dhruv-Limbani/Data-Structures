#include<bits/stdc++.h>
using namespace std;

// memiozation
int maxProfit(vector<int> &values, vector<int> &weights, vector<vector<int>>& dp, int i, int n, int w){
	if(i>=n || w<=0) return 0;
	if(dp[i][w]!=-1) return dp[i][w];
	int not_take = maxProfit(values, weights, dp, i+1, n, w);
	int take = 0;
	if(w>=weights[i]) take = values[i] + maxProfit(values, weights, dp, i+1, n, w-weights[i]);
	return dp[i][w] = max(take, not_take);
}

// tabulation
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w+1, 0));
	for(int i=0; i<n; i++){
		if(i==0){
			for(int j=0; j<w+1; j++){
				if(weights[i]<=j) dp[i][j] = values[i];
			}
		}
		else{
			for(int j=0; j<w+1; j++){
				int not_take = dp[i-1][j];
				int take = 0;
				if(weights[i]<=j) take = values[i] + dp[i-1][j-weights[i]];
				dp[i][j] = max(take, not_take);
			}
		}
	}
	return dp[n-1][w];
}

// space optimized
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<int> prev(w+1, 0);
	for(int i=0; i<n; i++){
		vector<int> curr = prev;
		if(i==0){
			for(int j=0; j<w+1; j++){
				if(weights[i]<=j) curr[j] = values[i];
			}
		}
		else{
			for(int j=0; j<w+1; j++){
				int not_take = prev[j];
				int take = 0;
				if(weights[i]<=j) take = values[i] + prev[j-weights[i]];
				curr[j] = max(take, not_take);
			}
		}
		prev = curr;
	}
	return prev[w];
}

/*
	DP relation:
		
*/
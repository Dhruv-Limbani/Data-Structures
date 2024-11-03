#include <bits/stdc++.h> 
using namespace std;

// recursive approach
int frogJump(int n, vector<int> &heights)
{
    if(n==1) return 0;
    else if(n==2) return abs(heights[n-1] - heights[n-2]);
    else return min(frogJump(n-1, heights) + abs(heights[n-1] - heights[n-2]), frogJump(n-2, heights) + abs(heights[n-1] - heights[n-3]));
}

// DP - Tabulation/Memiozation
int frogJump(int n, vector<int> &heights)
{
    vector<int> cost(n+1,0);
    cost[2] = abs(heights[1]-heights[0]);
    for(int i=2; i<n; i++){
        cost[i+1] = min(cost[i] + abs(heights[i-1]-heights[i]), cost[i-1] + abs(heights[i-2]-heights[i]));
    }
    return cost[n];
}

// space optimized
int frogJump(int n, vector<int> &heights)
{
    if(heights.size()<2) return 0;
    else{
        int last=abs(heights[1]-heights[0]), second_last=0;
        for(int i=2; i<n; i++){
            int temp = min(last + abs(heights[i-1]-heights[i]), second_last + abs(heights[i-2]-heights[i]));
            second_last = last;
            last = temp;
        }
        return last;
    }
}
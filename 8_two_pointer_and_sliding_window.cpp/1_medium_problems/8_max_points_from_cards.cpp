#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int left = k-1, right = n, sum=0;
    for(int i=0; i<k; i++) sum+=cardPoints[i];
    int mx = sum;
    while(left>=0){
        sum -= cardPoints[left];
        left--;
        right--;
        sum += cardPoints[right];
        mx = max(mx, sum);
    }
    return mx;
}
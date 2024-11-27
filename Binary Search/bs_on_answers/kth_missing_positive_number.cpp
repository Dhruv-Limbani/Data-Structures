#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int l=0, h=arr.size()-1, mid;
    while(l<=h){
        mid = (l+h)/2;
        int mis = arr[mid] - (mid+1);
        if(k<=mis) h = mid-1;
        else l = mid+1;            
    }
    return h+k+1;
}
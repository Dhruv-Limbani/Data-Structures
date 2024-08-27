#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: You're given an sorted array arr of n integers and an integer x. 
    Find the floor and ceiling of x in arr[0..n-1].
    The floor of x is the largest element in the array which is smaller than or equal to x.
    The ceiling of x is the smallest element in the array greater than or equal to x.
*/

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	pair<int, int> ans = {-1,-1};
	int l=0, h=n-1, mid;
	while(l<=h){
		mid = (l+h)/2;
		if(a[mid]>x){
			ans.second = a[mid];
			h = mid - 1;
		}
		else if(a[mid]<x){
			ans.first = a[mid];
			l = mid + 1;
		}
		else{
			return {a[mid], a[mid]};
		}
	}
	return ans;
}

/*
    TC: O(logn)
    SC: O(1)
*/

int main(){
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    pair<int, int> ans = getFloorAndCeil(arr, 6, 11);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}
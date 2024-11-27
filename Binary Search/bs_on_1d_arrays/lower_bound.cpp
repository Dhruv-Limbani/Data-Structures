#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.
    What is Lower Bound?
    The lower bound algorithm finds the first or the smallest index in a sorted array where the value at
    that index is greater than or equal to a given key i.e. x.

    The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, 
    the lower bound algorithm returns n i.e. size of the given array.
*/

//Naive approach
int lowerBound(vector<int> arr, int n, int x) {
	for(int i=0; i<n; i++){
        if(arr[i]>=x) return i;
    }
	return n;
}
/*
    TC: O(n)
    SC: O(1)
*/

// optimal approach
int lowerBound(vector<int> arr, int n, int x) {
	int l=0, h=n-1, lb=n, mid;
	while(l<=h){
		mid = (l+h)/2;
		if(arr[mid]>=x){
			lb=mid;
			h=mid-1;
		}
		else l=mid+1;
	}
	return lb;
}
/*
    TC: O(logn)
    SC: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

/*

*/

/*
    Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.
    What is Upper Bound?
    The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index 
    is greater than the given key i.e. x.

    The upper bound is the smallest index, ind, where arr[ind] > x.

    But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. 
    The main difference between the lower and upper bound is in the condition. For the lower bound the condition 
    was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.
*/

//Naive approach
int upperBound(vector<int> arr, int x, int n) {
	for(int i=0; i<n; i++){
        if(arr[i]>x) return i;
    }
	return n;
}
/*
    TC: O(n)
    SC: O(1)
*/

// optimal approach
int upperBound(vector<int> &arr, int x, int n){
	int l=0, h=n-1, mid, ub=n;
	while(l<=h){
		mid = (l+h)/2;
		if(arr[mid]>x){
			ub = mid;
			h = mid-1;
		}
		else l = mid+1;
	}
	return ub;	
}
/*
    TC: O(logn)
    SC: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: You are given a sorted array containing N integers and a number X, 
    you have to find the occurrences of X in the given array.

*/

int count(vector<int>& arr, int n, int x) {
	int first=-1, last=-1;
	int l=0, h=n-1, mid;
	while(l<=h){
		mid = (l+h)/2;
		if(x==arr[mid]){
			first = mid;
			h = mid-1;
		}
		else if(x<arr[mid]){
			h = mid-1;
		}
		else l=mid+1;
	}
	if(first==-1) return 0;
	l=0;
	h=n-1;
	while(l<=h){
		mid=(l+h)/2;
		if(x<arr[mid]){
			h=mid-1;
		}
		else if(x>arr[mid]){
			l=mid+1;
		}
		else{
			last=mid;
			l=mid+1;
		}
	}
	if(last==-1) return 1;
	return (last-first)+1;
}

/*
    TC: O(2*logn)
    SC: O(1)

    Solution = Last Occurence - First Occurence + 1
*/
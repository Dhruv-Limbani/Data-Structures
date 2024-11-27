#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an array of N integers. 
    Every number in the array except one appears twice. Find the single number in the array.

    Example 1:
    Input Format:
    arr[] = {1,1,2,2,3,3,4,5,5,6,6}
    Result:
    4
    Explanation:
    Only the number 4 appears once in the array.

    Example 2:
    Input Format:
    arr[] = {1,1,3,5,5}
    Result:
    3
    Explanation:
    Only the number 3 appears once in the array.

*/


//Brute Force approach 1 - Count occurences of each using Linear Search
//Brute Force approach 2 - Using XOR

// optimal approach
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size(), l, h, mid, ans;
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];
    l=1,h=n-2;
    while(l<=h){
        mid = (l+h)/2;
        if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]) return nums[mid];
        else if(mid%2==0){
            if(nums[mid+1]==nums[mid]) l=mid+1;
            else h=mid-1;
        }
        else{
            if(nums[mid-1]==nums[mid]) l=mid+1;
            else h=mid-1;
        }
    }
    return 0;
}
/*
    TC: O(logn)
    SC: O(1)
*/
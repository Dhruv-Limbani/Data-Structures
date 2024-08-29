#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). 
    Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

    Example 1:
    Input Format:
    arr = [4,5,6,7,0,1,2,3]
    Result:
    4
    Explanation:
    The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

    Example 2:
    Input Format:
    arr = [3,4,5,1,2]
    Result:
    3
    Explanation:
    The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.

*/

/*
    Observation: 

    We can easily observe that the number of rotations in an array is equal to the index(0-based index) of its minimum element.
    So, in order to solve this problem, we have to find the index of the minimum element.

*/

//Naive approach - Linear Search

// optimal approach
int findKRotation(vector<int> &nums){
    int n=nums.size(), l=0, h=n-1, mid, ans=0;
    while(l<=h){
        mid = (l+h)/2;
        if(nums[l]<=nums[h]){
            if(nums[l]<nums[ans]){
                return l;
            }
            else return ans;
        }
        else if(nums[l]<=nums[mid]){
            if(nums[l]<nums[ans]){
                ans = l;
            }
            l = mid+1;
        }
        else if(nums[mid]<=nums[h]){
            if(nums[mid]<nums[ans]){
                ans = mid;
            }
            h = mid - 1;
        }
    }
    return ans;
}
/*
    TC: O(logn)
    SC: O(1)
*/
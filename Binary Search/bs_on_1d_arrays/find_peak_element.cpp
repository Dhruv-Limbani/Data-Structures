#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an array of length N. Peak element is defined as the element greater 
    than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' 
    and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. 
    If there are multiple peak numbers, return the index of any peak number.

    Note: For the first element, the previous element should be considered as negative infinity 
    as well as for the last element, the next element should be considered as negative infinity.

*/

/*
    Example 1:
    Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
    Result: 7
    Explanation: In this example, there is only 1 peak that is at index 7.

    Example 2:
    Input Format: arr[] = {1,2,1,3,5,6,4}
    Result: 1
    Explanation: In this example, there are 2 peak numbers that are at indices 1 and 5. We can consider any of them.

    Example 3:
    Input Format: arr[] = {1, 2, 3, 4, 5}
    Result: 4
    Explanation: In this example, there is only 1 peak that is at the index 4.

    Example 4:
    Input Format: arr[] = {5, 4, 3, 2, 1}
    Result: 0
    Explanation: In this example, there is only 1 peak that is at the index 0.
*/

/*
    Observations:

    The left half of the peak element has an increasing order. This means for every index i, arr[i-1] < arr[i].
    On the contrary, the right half of the peak element has a decreasing order. This means for every index i, arr[i+1] < arr[i].
    Now, using the above observation, we can easily identify the left and right halves, 
    just by checking the property of the current index, i, like the following:

    If arr[i] > arr[i-1]: we are in the left half.
    If arr[i] > arr[i+1]: we are in the right half.
    How to eliminate the halves accordingly:

    If we are in the left half of the peak element, we have to eliminate this left half (i.e.    
    low = mid+1). Because our peak element appears somewhere on the right side.
    If we are in the right half of the peak element, we have to eliminate this right half (i.e.high = mid-1). 
    Because our peak element appears somewhere on the left side.
*/

// optimal approach
int findPeakElement(vector<int>& nums) {
    int n=nums.size(), l, h, mid;
    if(n==1) return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;
    l=1, h=n-2;
    while(l<=h){
        mid = (l+h)/2;
        if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) return mid;
        else if(nums[mid-1]<nums[mid]) l=mid+1;
        else h = mid-1;
    }
    return 0;
}
/*
    TC: O(logn)
    SC: O(1)
*/
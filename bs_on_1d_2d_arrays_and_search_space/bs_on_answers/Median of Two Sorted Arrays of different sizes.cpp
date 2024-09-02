#include<bits/stdc++.h>
using namespace std;
/*

    Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, 
    return the median of the two sorted arrays. The median is defined as the middle value of a 
    sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

    Examples
    Example 1:
    Input Format:
    n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
    Result:
    3.5
    Explanation:
    The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged 
    list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. 
    So the median will be the average of 3 and 4, which is 3.5.

    Example 2:
    Input Format:
    n1 = 3, arr1[] = {2,4,6}, n2 = 2, arr2[] = {1,3}
    Result:
    3
    Explanation:
    The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 6 }. The median is simply 3.
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
    int n1 = nums1.size(), n2 = nums2.size(), n=(n1+n2), l=0, h=n1, left_half = (n+1)/2;
    while(l<=h){
        int mid = (l+h)/2;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if(mid<n1) r1 =  nums1[mid];
        if(left_half-mid<n2) r2 = nums2[left_half-mid];
        if(mid>0) l1 = nums1[mid-1];
        if(left_half-mid>0) l2 = nums2[left_half-mid-1];

        if(l1<=r2 && l2<=r1){
            if(n%2==0) return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            else return max(l1,l2);
        }
        else if(l1>r2) h = mid-1;
        else l = mid+1;
    }
    return 0;
}

/*
    We are going to use the Binary Search algorithm to optimize the approach.

    The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, 
    thereby reducing the search space by half. It does this by determining a specific condition that ensures that 
    the target is not present in that half.

    Now, let’s learn through the following observations how we can apply binary search to this problem. 
    First, we will try to solve this problem where n1+n2 is even and then we will consider the odd scenario.

    Observations:
    Assume, n = n1+n2 i.e. the total length of the final merged array.

    Median creates a partition on the final merged array: Upon closer observation, 
    we can easily show that the median divides the final merged array into two halves. For example,

    Characteristics of each half:
    Each half contains (n/2) elements.
    Each half also contains x elements from the first array i.e. arr1[] and (n/2)-x elements from the second array i.e. arr2[]. 
    The value of x might be different for the two halves. 
    For example, in the above array, the left half contains 3 elements from arr1[] and 2 elements from arr2[].
    The unique configuration of halves: Considering different values of x, 
    we can get different left and right halves(x = the number of elements taken from arr1[] for a particular half). 
    Some different configurations for the above example are shown below:

    How to solve the problem using the above observations:

    Try to form the unique left half: 
    For a valid merged array, the configurations of the two halves are unique. 
    So, we can try to form the halves with different values of x, where x = the number of elements taken from arr1[] for a particular half.
    There's no need to construct both halves. Once we have the correct left half, 
    the right half is automatically determined, consisting of the remaining elements not yet considered. 
    Therefore, our focus will solely be on creating the unique left half.
    How to form all configurations of the left half: We know that the left half will surely contain x elements from arr1[] 
    and (n/2)-x elements from arr2[]. Here the only variable is x. 
    The minimum possible value of x is 0 and the maximum possible value is n1(i.e. The length of the considered array).
    For all the values,[0, n1] of x, we will try to form the left half and then we will check if that half’s configuration is valid.
    
    Check if the formed left half is valid: For a valid left half, the merged array will always be sorted. 
    So, if the merged array containing the formed left half is sorted, the formation is valid.
    
    How to check if the merged array is sorted without forming the array:
    In order to check we will consider 4 elements, i.e. l1, l2, r1, r2.
    l1 = the maximum element belonging to arr1[] of the left half.
    l2 = the maximum element belonging to arr2[] of the left half.
    r1 = the minimum element belonging to arr1[] of the right half.
    r1 = the minimum element belonging to arr2[] of the right half.
    For example,


    How to apply Binary search to form the left half:

    We will check the formation of the left half for all possible values of x. 
    Now, we know that the minimum possible value of x is 0 and the maximum is n1(i.e. The length of the considered array). 
    Now the range is sorted. So, we will apply the binary search on the possible values of x i.e. [0, n1].
    How to eliminate the halves based on the values of x: Binary search works by eliminating the halves in each step.
    Upon closer observation, we can eliminate the halves based on the following conditions:
    If l1 > r2: This implies that we have considered more elements from arr1[] than necessary. 
    So, we have to take less elements from arr1[] and more from arr2[]. In such a scenario, 
    we should try smaller values of x. To achieve this, we will eliminate the right half (high = mid-1).
    If l2 > r1: This implies that we have considered more elements from arr2[] than necessary. 
    So, we have to take less elements from arr2[] and more from arr1[]. In such a scenario, 
    we should try bigger values of x. To achieve this, we will eliminate the left half (low = mid+1).
    Until now, we have learned how to use binary search but with the assumption that (n1+n2) is even. 
    
    Let’s generalize this.

    If (n1+n2) is odd: In the case of even, we have considered the length of the left half as
    (n1+n2) / 2. In this case, that length will be (n1 + n2 + 1) / 2. 
    This much change is enough to handle the case of odd. The rest of the things will be completely the same.
    As in the code, division refers to integer division, this modified formula (n1+n2+1) / 2 will be valid for both cases of odd and even.

    What will be the answer i.e. the median:

    If l1 <= r2 && l2 <= r1: This condition assures that we have found the correct elements. 
    If (n1+n2) is odd: The median will be max(l1, l2).
    Otherwise, median = (max(l1, l2) + min(r1, r2)) / 2.0
    Note: We are applying binary search on the possible values of x i.e. [0, n1]. 
    Here n1 is the length of arr1[]. Now, to further optimize it, we will consider the smaller array as arr1[]. 
    So, the actual range will be [0, min(n1, n2)].

    Algorithm:
    First, we have to make sure that the arr1[] is the smaller array. If not by default, we will just swap the arrays. 
    Our main goal is to consider the smaller array as arr1[].
    Calculate the length of the left half: left = (n1+n2+1) / 2.
    Place the 2 pointers i.e. low and high: Initially, we will place the pointers. 
    The pointer low will point to 0 and the high will point to n1(i.e. The size of arr1[]).
    Calculate the ‘mid1’ i.e. x and ‘mid2’ i.e. left-x: Now, inside the loop, 
    we will calculate the value of ‘mid1’ using the following formula:
    mid1 = (low+high) // 2 ( ‘//’ refers to integer division)
    mid2 = left-mid1
    Calculate l1, l2, r1, and r2: Generally,
    l1 = arr1[mid1-1]
    l2 = arr2[mid2-1]
    r1 = arr1[mid1]
    r2 = arr2[mid2]
    The possible values of ‘mid1’ and ‘mid2’ might be 0 and n1 and n2 respectively. 
    So, to handle these cases, we need to store some default values for these four variables. 
    The default value for l1 and l2 will be INT_MIN and for r1 and r2, it will be INT_MAX.
    
    Eliminate the halves based on the following conditions:
    If l1 <= r2 && l2 <= r1: We have found the answer.
    If (n1+n2) is odd: Return the median = max(l1, l2).
    Otherwise: Return median = (max(l1, l2)+min(r1, r2)) / 2.0
    If l1 > r2: This implies that we have considered more elements from arr1[] than necessary. 
    So, we have to take less elements from arr1[] and more from arr2[]. In such a scenario, we should try smaller values of x. 
    To achieve this, we will eliminate the right half (high = mid1-1).
    If l2 > r1: This implies that we have considered more elements from arr2[] than necessary. 
    So, we have to take less elements from arr2[] and more from arr1[]. In such a scenario,
    we should try bigger values of x. To achieve this, we will eliminate the left half (low = mid1+1).
    Finally, outside the loop, we will include a dummy return statement just to avoid warnings or errors.
    The steps from 4-6 will be inside a loop and the loop will continue until low crosses high.

    Time Complexity: O(log(min(n1,n2))), where n1 and n2 are the sizes of two given arrays.
    Reason: We are applying binary search on the range [0, min(n1, n2)].

    Space Complexity: O(1) as no extra space is used.
*/
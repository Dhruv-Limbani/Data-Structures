#include<bits/stdc++.h>
using namespace std;

/*
    Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
    Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that 
    it contains the last M elements.

    Example 1:
    Input:
    
    n = 4, arr1[] = [1 4 8 10] 
    m = 5, arr2[] = [2 3 9]

    Output:
    
    arr1[] = [1 2 3 4]
    arr2[] = [8 9 10]

    Explanation:

    After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.

    Example2:
    Input:
    
    n = 4, arr1[] = [1 3 5 7] 
    m = 5, arr2[] = [0 2 6 8 9]

    Output:
    
    arr1[] = [0 1 2 3]
    arr2[] = [5 6 7 8 9]

    Explanation:

    After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9.
*/

// Brute force approach is same as that of merge algorithm of merge sort but it uses extra space


// Leetcode variant:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(m==0){
        nums1.clear();
        nums1.insert(nums1.begin(),nums2.begin(),nums2.end());
        nums2.clear();
        return;
    }
    else if(n==0) return;
    // the above two conditions are of edge cases
    else{
        int i=m-1, j=0;
        while(i>=0 && j<n){
            if(nums1[i]>=nums2[j]) swap(nums1[i],nums2[j]);
            else break;
            i--;
            j++;
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        for(int k=0;k<n;k++){
            nums1[m+k] = nums2[k];
        }
    }
}
/*
    The steps are as follows:
    
    We will declare two pointers i.e. left and right. 
        The left pointer will point to the last index of the arr1[](i.e. Basically the maximum element of the array). 
        The right pointer will point to the first index of the arr2[](i.e. Basically the minimum element of the array).
    
    Now, the left pointer will move toward index 0 and the right pointer will move towards the index m-1. 
    
    While moving the two pointers we will face 2 different cases like the following:
        If arr1[left] > arr2[right]: In this case, we will swap the elements and move the pointers to the next positions.
        If arr1[left] <= arr2[right]: In this case, we will stop moving the pointers as arr1[] and arr2[] are containing correct elements.
    
    Thus, after step 2, arr1[] will contain all smaller elements and arr2[] will contain all bigger elements. 
    Finally, we will sort the two arrays.

    Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
    
    Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.

    Space Complexity: O(1) as we are not using any extra space.
*/

void compare_and_swap(int left, int right, vector<int>& arr1, vector<int>& arr2){
    if(arr1[left]>arr2[right]) swap(arr1[left],arr2[right]);
    else return;
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(m==0){
        nums1.clear();
        nums1.insert(nums1.begin(),nums2.begin(),nums2.end());
        nums2.clear();
        return;
    }
    else if(n==0) return;
    else{
        int len=n+m;
        int gap=len/2 + len%2;
        while(gap>0){
            int left=0, right=left+gap;
            while(right<len){
                if(left<m && right<m){
                    compare_and_swap(left,right,nums1,nums1);
                }
                else if(left<m && right>=m){
                    compare_and_swap(left,right-m,nums1,nums2);
                }
                else if(left>=m && right>=m){
                    compare_and_swap(left-m,right-m,nums2,nums2);
                }
                left++;
                right++;
            }
            if (gap==1) break;
            gap = gap/2 + gap%2;
        }
        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
    }
}

/*
    Algorithm / Intuition
        Optimal Approach 2 (Using gap method): 
        This gap method is based on a sorting technique called shell sort. The intuition of this method is simple. 

    Intuition:
        Similar to optimal approach 1, in this approach, we will use two pointers i.e. left and right, 
        and swap the elements if the element at the left pointer is greater than the element at the right pointer. 

        But the placing of the pointers will be based on the gap value calculated. The formula to calculate the initial gap is the following:

        Initial gap = ceil((size of arr1[] + size of arr2[]) / 2)

        Assume the two arrays as a single continuous array and initially, 
        we will place the left pointer at the first index and the right pointer at the (left+gap) index of that continuous array.

        Now, we will compare the elements at the left and right pointers and move them by 1 place each time after comparison. 
        While comparing we will swap the elements if the element at the left pointer > the element at the right pointer. 
        After some steps, the right pointer will reach the end and the iteration will be stopped.

        After each iteration, we will decrease the gap and will follow the same procedure until the 
        iteration for gap = 1 gets completed. Now, after each iteration, the gap will be the following:

            gap = ceil( previous gap / 2)

        The whole process will be applied to the imaginary continuous array constructed using arr1[] and arr2[].

        The reason we are using right-m, left-m etc in code is that when right = left + gap is the index of imaginary continuous array
        so if the right or left pointer lies in the second array then we have to reduce lenght of 1st array from that in order to access
        elements in 2nd array.
 
        Complexity Analysis
            Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the given arrays.
            Reason: The gap is ranging from n+m to 1 and every time the gap gets divided by 2. 
            So, the time complexity of the outer loop will be O(log(n+m)). Now, for each value of the gap, 
            the inner loop can at most run for (n+m) times. So, the time complexity of the inner loop will be O(n+m). 
            So, the overall time complexity will be O((n+m)*log(n+m)).

            Space Complexity: O(1) as we are not using any extra space.
*/
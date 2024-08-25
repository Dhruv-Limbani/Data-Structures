#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.
*/

// naive approach is to consider all possible subarrays with three loops

int better_approach(vector<int> &arr){
	int mx=INT_MIN,prod;
	for (int i = 0; i < arr.size(); i++) {
		prod=1;
		for(int j=i; j<arr.size(); j++){
			prod*=arr[j];
			mx = max(prod,mx);
		}
	} 
	return mx;
}
/*
    Considering all possible subarrays
    TC: O(N^2)
    SC: O(1)
*/

int optimal_approach(vector<int> &arr){
	int mx=INT_MIN,pre=1,suf=1, n=arr.size();
	for (int i = 0; i < n; i++) {
		if(pre==0) pre=1;
		if(suf==0) suf=1;
		pre*=arr[i];
		suf*=arr[n-i-1];
		mx = max(mx,max(pre,suf));
	} 
	return mx;
}

/*
    Observations:
    1) If given array contains only positives, then product of the entire array is our answer
    2) If there are even number of -ves then again the product of the entire array is our answer
    3) If there are odd number of -ves then we have to drop one of them and the product of the array elements before or after
    the element will be our answer

    Also, the subarray with maximum product cannot contain 0, so we have to apply the above logic to the arrays on either side
    each zero we encounter.

    For example, the given array is: {-2, 3, 4, -1, 0, -2, 3, 1, 4, 0, 4, 6, -1, 4}.
    In this case, we will divide the array into 3 different subarrays based on the 0’s locations. 
    So, the subarrays will be {-2, 3, 4, -1}, {-2, 3, 1, 4}, and {4, 6, -1, 4}.

    In these 3 subarrays, we will apply the logic discussed in case 3. We will get 3 different answers for 3 different subarrays.
    The maximum one among those 3 answers will be the final answer.
    Summary: In real-life problems, we will not separate out the cases as we did in the observations. 
    Instead, we can directly apply the logic discussed in the 4th observation to any given subarray, 
    and it will automatically handle all the other cases.

    Algorithm: 
    
    We will first declare 2 variables i.e. ‘pre’(stores the product of the prefix subarray) and 
    ‘suff’(stores the product of the suffix subarray). They both will be initialized with 1(as we want to store the product).
    
    Now, we will use a loop(say i) that will run from 0 to n-1.
    
    We have to check 2 cases to handle the presence of 0:
    If pre = 0: This means the previous element was 0. 
    So, we will consider the current element as a part of the new subarray. So, we will set ‘pre’ to 1.
    If suff = 0: This means the previous element was 0 in the suffix. 
    So, we will consider the current element as a part of the new suffix subarray. So, we will set ‘suff’ to 1.
    
    Next, we will multiply the elements from the starting index with ‘pre’ and the elements from the end with ‘suff’. 
    
    To incorporate both cases inside a single loop, we will do the following:
    We will multiply arr[i] with ‘pre’ i.e. pre *= arr[i].
    We will multiply arr[n-i-1] with ‘suff’ i.e. suff *= arr[n-i-1].
    
    After each iteration, we will consider the maximum among the previous answer, ‘pre’ and ‘suff’ i.e. max(previous_answer, pre, suff).
    Finally, we will return the maximum product.

*/
#include<bits/stdc++.h>
using namespace std;

int brute_force_approach(int arr[], int n, int k){
    int mx=0;
    for(int i=0; i<n; i++){
        for(int t=i; t<n; t++ ){
            int sum = 0;
            for(int j=i; j<=t; j++){
                sum += arr[j];
            }
            if(sum==k){
                mx=max(mx,t-i+1);
            }
        }
    }
    return mx;
}

/*
    considering all the subarrays of array and then calculating the sum
    followed by comparing it with k and updating mx value

    TC: O(N^3)
    SC: O(1)
*/

int better_approach(int arr[], int n, int k){
    int mx=0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int t=i; t<n; t++ ){
            sum+=arr[t];
            if(sum==k){
                mx=max(mx,t-i+1);
            }
        }
    }
    return mx;
}

/*
    considering all the subarrays of array and then calculating the sum
    followed by comparing it with k and updating mx value

    TC: O(N^2)
    SC: O(1)
*/


int optimal_approach(int arr[], int n, int k){
    int mx=0, sum=0;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum==k){
            mx = i+1;
        }
        int rem = sum - k;
        if(m.find(rem)!=m.end()){
            int len = i - m[rem];
            mx = max(mx,len);
        }
        if(m.find(sum)==m.end()) m[sum] = i;
    }
    return mx;
}

/*
    hashing approach using maps by finding prefix sum

    we maintain the map<sum, i> structure which stores sum till index i as key and i as value

    we add elements to sum one by one
    then we check if sum == k then set maxlen to i+1

    we calculate rem = sum - k

    now we check if rem is present in map or not,
    if it is present and let say at idx j
    then it means that rem = sum - k is total of all elements till j
    where sum is total of all elements till i
    therefore sum of subarray[j:i] = sum - (sum - k) = k
    len of subarray = i - j
    we compare this len with existing maxlen and update maxlen accordingly

    Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
    Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)
    (though in the worst case which occurs very rarely, unordered_map takes O(N) to find an element and the time complexity becomes O(N^2)) 
    but if we are using a map data structure, the time complexity will be O(N*logN). 
    The least complexity will be O(N) as we are using a loop to traverse the array.

    Space Complexity: O(N) as we are using a map data structure.
*/

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &A, int B) {
    int n = A.size();
    int ct=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int x = B;
            for(int k=i; k<=j; k++){
                x^=A[k];
            }
            if(!x) ct++;
        }
    }
    return ct;
}
/*
    We find all the subarrays, calculate xor and then compare and finally increment the count.
    TC: O(n^3)
    SC: O(1)
*/


int better_approach(vector<int> &A, int B) {
    int n = A.size();
    int ct=0;
    for(int i=0; i<n; i++){
        int x=0;
        for(int j=i; j<n; j++){
            x^=A[j];
            if(x==B) ct++;
        }
    }
    return ct;
}
/*
    We find all the subarrays, calculate xor and then compare and finally increment the count. We reduce the loops to 2.
    TC: O(n^2)
    SC: O(1)
*/


int optimal_approach(vector<int> &A, int B) {
    int n = A.size();
    int ct=0,x=0;
    map<int,int> m;
    for(int i=0; i<n; i++){
        x^=A[i];
        if(x==B) ct++;
        int prefix = x^B;
        ct+=m[prefix];
        m[x]++;
    }
    return ct;
}
/*
    Here, we are using the same concept as that of subarray with sum k.
    in an arrat a[0...n] lets say for a subarray a[i...j] to have xor = k,
    xor of a[0...i] i.e. the array to right side of subarray should be x^k 
    where x is xor of a[0...j] i.e. both right side + subarray included.

    So we start from i=0 to n and do the following at each iteration:
        1) calculate the xor of current xr value and the current element at i
        2) if xor till element at i becomes equal to k, then increment the counter
        3) calculate the prefix xor = x^k
        4) increment the counter with the total number of occurances of x^k
        5) increment the occurence of current xor: x in map by 1

*/



#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] 
    both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. 
    The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.
*/

vector<int> brute_force(vector<int> arr, int n) {
    int rep=0,mis=0;
    for(int i=1; i<=n; i++){
        int ct=0;
        for(int j=0; j<n; j++){
            if(arr[j]==i) ct++;
        }
        if(ct==2) rep=i;
        else if (ct==0) mis=i;
        if(rep && mis) return {rep,mis};
    }
}

/*
    TC: O(N^2)
    SC: O(1)
*/

vector<int> better_approach(vector<int> arr, int n) {
    int rep=0,mis=0;
    int hash[n+1] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    for(int i=1; i<=n; i++){
        if(hash[i]==2) rep=i;
        else if(hash[i]==0) mis=i;
        if(rep && mis) return {rep,mis};
    }
}

/*
    TC: O(N) + O(N)
    SC: O(N)
*/

vector<int> optimal_approach_1(vector<int> arr, int n) {
    long long N = (long long)n;
    long long SN = (N*(N+1))/2, S2N=(N*(N+1)*(2*N+1))/6;
    long long S=0,S2=0;
    for(int i=0; i<n; i++){
        S += (long long)arr[i];
        S2 += ((long long)arr[i]*(long long)arr[i]);
    }
    long long rep = S2-S2N;
    rep /= (S-SN);
    rep += (S-SN);
    rep /= 2;
    long long mis = rep - (S-SN);
    return {(int)rep,(int)mis};
}
/*
    Using Mathematics
    Sum of 1 to N = N(N+1)/2, Sum of squares from 1 to N = N(N+1)(2N+1)/6

    Actual sum of all elements = Val1 , Actual sum of squares of all elements = Val2

    if we subtract sum of 1 to N from actual sum, all the elements get cancelled on lhs except for
    repeting and missing element.
    Therefore we get expression: rep - mis = Actual Sum - Sum 1 to N
    Similarly we get expression: rep^2 - mis^2 = Actual sqaured sum - Sum squared 1 to N
    rep^2-mis^2 = (rep-mis)(rep+mis) so we can substitue the value of (rep-mis) in the equation to get (rep+mis)
    now since we have two variables and two equations we can solve them to get values of rep and mis.

    TC: O(N)
    SC: O(1)  

*/

vector<int> optimal_approach_2(vector<int> arr, int n) {
    int xr=0;
    for(int i=0; i<n; i++) {
        xr^=arr[i];
        xr^=(i+1);
    }
    int a=1;
    while((a&xr) == 0){
        a=a<<1;
    }
    int zero=0,one=0;
    for(int i=0; i<n; i++){
        if(arr[i]&a) one^=arr[i];
        else zero^=arr[i];
        if((i+1)&a) one^=(i+1);
        else zero^=(i+1);
    }
    for(int i=0; i<n; i++) if(arr[i]==zero) return{zero,one};
    return {one,zero};
}

/*
    We xor all the elements in array and all the numbers from 1 to N.
    Now xr will be (repeating number ^ missing number) lets say we get 5 which in binary will be 1 1 0
    now there is 1 at 2nd position from right in xor, that means the bit in 2nd postion of both repeating 
    and missing number will be different.
    So now from a pool of all the array elements and all elements from 1 to N, we will put a number having bit set (or 1) 
    at 2nd position in a group called "One" and if not then in group called "Zero".
    Total number of occurence of repeating number and missing number in the entire pool will be 3,1 repectively and remaining will be 2.
    So if we take xor of each group, it will give us repeating number and missing number

    Note: we only need to find the first set bit from right for segregation.
    For example:
    
    2 3 1 3     1 2 3 4

    xor = 3^4 = 7 i.e. 1 1 1

    the first set bit from right is at position 1

    so group one (with all the elements with set bit at position 1) and group zero with rest will be:

    One : 3^1^3^1^3 = 3
    Zero: 2^2^4 = 4

    now we will take any value let say zero and will check if it exists in array or not.
    If it exists then it is repeating number and one is storing the missing number
    else otherwise

    TC: O(n)+O(n)+O(n)+O(n) = O(n)
    SC: O(1)

*/
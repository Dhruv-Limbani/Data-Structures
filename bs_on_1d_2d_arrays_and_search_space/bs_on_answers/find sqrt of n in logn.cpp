#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: You are given a positive integer n. Your task is to find and return its square root. 
    If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

    Note: The question explicitly states that if the given number, n, is not a perfect square, our objective 
    is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). 
    In other words, we need to determine the floor value of the square root of n.

    Example 1:
    Input Format:
    n = 36
    Result:
    6
    Explanation:
    6 is the square root of 36.

    Example 2:
    Input Format:
    n = 28
    Result:
    5
    Explanation:
    Square root of 28 is approximately 5.292. So, the floor value will be 5.
*/

// Brute Force
int floorSqrt(int n)
{
    int i=1;
    while(i*i<=n) i++;
    return i-1;
}
/*
    TC: O(n)
    SC: O(1)
*/

// optimal apporoach
int floorSqrt(long long int n)
{
    long long int l=0, h=n, mid, ans;
    while(l<=h){
        mid = (l+h)/2;
        if(mid*mid==n) return mid;
        else if(mid*mid<n){
            ans = mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }   
    }
    return ans;
}

/*
    TC: O(logn)
    SC: O(1)
*/

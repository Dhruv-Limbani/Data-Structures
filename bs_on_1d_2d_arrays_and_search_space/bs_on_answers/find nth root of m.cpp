#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given two numbers N and M, find the Nth root of M. 
    The nth root of a number M is defined as a number X when raised to the power N equals M. 
    If the 'nth root is not an integer, return -1.

    Examples
    Example 1:
    Input Format:
    N = 3, M = 27
    Result:
    3
    Explanation:
    The cube root of 27 is equal to 3.

    Example 2:
    Input Format:
    N = 4, M = 69
    Result:
    -1
    Explanation:
    The 4th root of 69 does not exist. So, the answer is -1.
*/

// optimal apporoach
int power(int x, int n, int m){
  long long ans = 1;
  while (n--) {
    ans *= x;
    if(ans>m) return 2;
  }
  if(ans==m) return 1;
  return 0;
}

int NthRoot(int n, int m) {
  if(m==1) return 1;
  int l=1, h=m, mid;
  while(l<=h){
    mid = (l+h)/2;
    int p = power(mid,n,m);
    if(p==1) return mid;
    else if(p==0) l=mid+1;
    else h=mid-1;
  }
  return -1;
}

/*
    TC: O(logn)
    SC: O(1)
*/

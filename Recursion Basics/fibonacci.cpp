#include<bits/stdc++.h>
using namespace std;


// recursive approach
int fib(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1) + fib(n-2);
}

/*
    time complexity: O(2^n)
    space complexity: O(n) --> if stack overflows
*/

int fib_without_recursion(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    int i=0, j=1;
    while(n>=2){
        j+=i;
        i=j-i;
        n--;
    }
    return j;
}

/*
    time complexity: O(n)
    space complexity: O(1)
*/
int main()
{
    int num;
    cout<<"Enter num: "<<endl;
    cin>>num;
    cout<<fib(num)<<endl;
    cout<<fib_without_recursion(num);
    return 0;
}
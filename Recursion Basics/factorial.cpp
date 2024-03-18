#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n<1){
        return 1;
    }
    return n*factorial(n-1);
}
/*
    Time Complexity: O(N) -> Since the function is being called n times, and for each function, 
    we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N)

    Space Complexity: O(N) { In the worst case, the recursion stack space would be full with
    all the function calls waiting to get completed and that would make it an O(N) recursion stack space
*/ 

int main()
{
    int num;
    cin>>num;
    cout<<factorial(num);
    return 0;
}
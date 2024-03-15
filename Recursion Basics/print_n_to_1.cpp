#include<bits/stdc++.h>
using namespace std;


// forward recursion: first, number is printed and then function is called
void printnto1(int n)
{
    if(n==0){
        return;
    }
    cout<<n<<" ";
    printnto1(n-1);
}


// a backtracking approach aka backward recursion: first goes to the depth and then print and comes out
void printnto1_2(int i, int n){
    if(i>n){
        return;
    }
    printnto1_2(i+1,n);
    cout<<i<<" ";
}

int main()
{
    printnto1(7);
    cout<<endl;
    printnto1_2(1,4);
    return 0;
}

/*
    Time Complexity: O(N) -> Since the function is being called n times, and for each function, 
    we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N)

    Space Complexity: O(N) -> In the worst case, the recursion stack space would be full with all the function calls
    waiting to get completed and that would make it an O(N) recursion stack space

*/
#include<bits/stdc++.h>
using namespace std;

int sum_1ton(int s){
    if(s==0){
        return 0;
    }
    s += sum_1ton(s-1);
    return s;
}
/*
    we can also use formula: sum of 1 to n = n(n+1)/2 but just for practice
    we are using recursion.
    The above method is a backward recursion
    time complexity: O(n)
    space complexity: O(n) worst case if the recursion stack is full
*/ 

int sum_1ton_2(int i, int sum){
    if(i<1){
        return 0;
    }
    sum = i + sum_1ton_2(i-1,sum);
    return sum;
}

int main()
{
    int num;
    cin>>num;
    cout<<sum_1ton_2(num,0);
    return 0;
}
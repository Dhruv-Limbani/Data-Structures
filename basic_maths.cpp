#include<bits/stdc++.h>
using namespace std;

void count_digits_1(int num){
    int ct=0;
    while(num){
        num/=10;
        ct++;
    }
    cout<<ct<<endl;
    /*
    complexity
    time: O(n) where "n" is number of digits
    space: O(1)
    */
}

int main()
{
    int num;
    cin>>num;
    count_digits_1(num);
    return 0;
}
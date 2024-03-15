/*
Problem statement
You are given an integer ‘n’.



Your task is to return an array containing integers from 1 to ‘n’ (in increasing order) without using loops.


Example:
Input: ‘n’ = 5

Output: 1 2 3 4 5

Explanation: An array containing integers from ‘1’ to ‘n’ is [1, 2, 3, 4, 5].
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> printNos(int x) {
    if(x==1){
        vector<int> v;
        v.push_back(x);
        return v;
    }
    vector<int> v(printNos(x-1));
    v.push_back(x);
    return v;
}

int main()
{
    int num;
    cin>>num;
    vector<int> v=printNos(num);
    for(auto it: v){
        cout<<it<<" ";
    }
}

/*
In recursion, whenever a function is called within the same function, the parent function is stored in stack until the called function is executed.
func(){
    func(); -----> func(){
    return;
}                       func(); ------> func(){
                        return;
                    }                   base condition met
                                        return;
                                        }

There is a limit on how much functions can be waiting in the stack for the child function to return value.
It varies for different compilers. When that limit is exceeded, mostly in case of infinite recursion, the stack overflows.
This raises segmentation fault error
*/
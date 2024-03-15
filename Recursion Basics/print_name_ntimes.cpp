#include<bits/stdc++.h>
using namespace std;

void printNtimes(string a, int n){
    if(n==0){
        return;
    }
    cout<<a<<" ";
    printNtimes(a,n-1);
}

int main()
{
    int num;
    string name;
    cout<<"Enter name and number: ";
    cin>>name>>num;
    printNtimes(name,num); 
}

/*
Time complexity : O(n)
Space Complexity : O(n) -> worst case
*/
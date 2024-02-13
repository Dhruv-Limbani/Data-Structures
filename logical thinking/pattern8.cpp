#include<iostream>
using namespace std;

int main()
{
    for(int i=1;i<=5;i++){  // index of the starting star
        for(int j=1; j<=i+2*(5-i); j++){ // number of stars following the starting star
            j<i?cout<<" ":cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
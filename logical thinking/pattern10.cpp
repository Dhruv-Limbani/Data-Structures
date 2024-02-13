#include<iostream>
using namespace std;

int main()
{
    for(int i=4;i>-5;i--){
        int k=i*((2*i+1)%2); // stores abs(i) in k
        cout<<"    ";
        for(int j=5;j<=5+(4-k);j++){ // star following starting star goes from 0..4..0
            cout<<"*"; 
        }
        cout<<"\n";
    }
    return 0;
}

    //     *
    //     **
    //     ***
    //     ****
    //     *****
    //     ****
    //     ***
    //     **
    //     *
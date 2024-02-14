#include<iostream>
using namespace std;

void pattern(int n)
{
    for(int i=n-1;i>=1-n;i--){
        int k=i*((2*i+1)%2); // stores abs(i) in k
        for(int j=n;j<=n+(n-1-k);j++){ // star following starting star goes from 0..4..0
            cout<<"*"; 
        }
        cout<<"\n";
    }
}
int main()
{
    int n;
    cout<<"Enter lenth: ";
    cin>>n;
    pattern(n);
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
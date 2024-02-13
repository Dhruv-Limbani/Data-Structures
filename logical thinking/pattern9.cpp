#include<iostream>
using namespace std;

int main()
{
    for(int i=5;i>=-5;i--){ 
        if(i==0)
            continue;
        int k=i*((2*i+1)%2); // stores the abs value of i in k as the starting star index goes from 5 to 1 and 1 again and back upto 5
        for(int j=1;j<=k+2*(5-k);j++){ // till 1 to <k index " " will be printed then 2*(5-k) are number of stars following the starting star
            j<k?cout<<" ":cout<<"*";
        }
        cout<<"\n";
    }
}

//     *
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *
#include<iostream>
using namespace std;

void pattern(int n){
    for(int i=n;i>=-n;i--){    
        if(i==0)
            continue;
        int k=i*((2*i+1)%2); // stores the abs value of i in k as the starting star index goes from n to 1 and 1 again and back upto n
        for(int j=1;j<=k+2*(n-k);j++){ // till 1 to <k index " " will be printed then 2*(n-k) are number of stars following the starting star
            j<k?cout<<" ":cout<<"*";
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
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *
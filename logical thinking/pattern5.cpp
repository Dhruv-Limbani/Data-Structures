#include<iostream>
using namespace std;

void pattern(int n){
    for(int i=n; i>0; i--){
        for(int j=1; j<=i; j++){
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

// *****
// ****
// ***
// **
// *
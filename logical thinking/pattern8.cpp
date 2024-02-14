#include<iostream>
using namespace std;

void pattern(int n){
    for(int i=1;i<=n;i++){  // index of the starting star
        for(int j=1; j<=i+2*(n-i); j++){ // number of stars following the starting star
            j<i?cout<<" ":cout<<"*";
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
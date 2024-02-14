#include<iostream>
using namespace std;

void pattern(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j;
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

// 1
// 12
// 123
// 1234
// 12345
#include<iostream>
using namespace std;

void pattern(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<i;
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
// 22
// 333
// 4444
// 55555
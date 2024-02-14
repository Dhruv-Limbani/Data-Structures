/*
pattern:

*****
*****
*****
*****
*****
*/

#include<iostream>
using namespace std;

// int main()
// {
//     for(int i=0; i<5; i++){
//         cout<<"*****\n";
//     }
//     return 0;
// }

// another solution
void pattern(int n);
int main()
{
    int n;
    cout<<"Enter lenth: ";
    cin>>n;
    pattern(n);
    return 0;
}

void pattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
};
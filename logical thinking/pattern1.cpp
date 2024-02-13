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

int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
#include<iostream>
using namespace std;

void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
// *****
// *****
// *****
// *****
// *****
};

void pattern2(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }

// *
// **
// ***
// ****
// *****

}

void pattern3(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        cout<<"\n";
    }

// 1
// 12
// 123
// 1234
// 12345
}

void pattern4(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<i;
        }
        cout<<"\n";
    }
// 1
// 22
// 333
// 4444
// 55555
}

void pattern5(int n){
    for(int i=n; i>0; i--){
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
// *****
// ****
// ***
// **
// *

}

void pattern6(int n){
    for(int i=n; i>0; i--){
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        cout<<"\n";
    }
}

void pattern7(int n){
    /*
     because there are n lines and the starting index of "*" in each line is decreasing from n at first line to 1 in last line
    */
    for(int i=n; i>=1; i--){        
        /*
        in each line the number of stars following the starting star is increasing by the factor of 2
        */
        for(int j=1;j<=i+2*(n-i);j++)   
        {
            j<i?cout<<" ":cout<<"*";
        }
        cout<<"\n";
    }
    
//     *
//    ***
//   *****
//  *******
// *********
}

void pattern8(int n){
    for(int i=1;i<=n;i++){  // index of the starting star
        for(int j=1; j<=i+2*(n-i); j++){ // number of stars following the starting star
            j<i?cout<<" ":cout<<"*";
        }
        cout<<"\n";
    }
}

void pattern9(int n){
    for(int i=n;i>=-n;i--){    
        if(i==0)
            continue;
        int k=i*((2*i+1)%2); // stores the abs value of i in k as the starting star index goes from n to 1 and 1 again and back upto n
        for(int j=1;j<=k+2*(n-k);j++){ // till 1 to <k index " " will be printed then 2*(n-k) are number of stars following the starting star
            j<k?cout<<" ":cout<<"*";
        }
        cout<<"\n";
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
}

void pattern10(int n)
{
    for(int i=n-1;i>=1-n;i--){
        int k=i*((2*i+1)%2); // stores abs(i) in k
        for(int j=n;j<=n+(n-1-k);j++){ // star following starting star goes from 0..4..0
            cout<<"*"; 
        }
        cout<<"\n";
    }
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
}

int main()
{
    int n, choice;
    cout<<"Enter pattern number and length: ";
    cin>>choice>>n;
    switch(choice){
        case 1:
            pattern1(n);
            break;
        case 2:
            pattern2(n);
            break;
        case 3:
            pattern3(n);
            break;
        case 4:
            pattern4(n);
            break;
        case 5:
            pattern5(n);
            break;
        case 6:
            pattern6(n);
            break;
        case 7:
            pattern7(n);
            break;
        case 8:
            pattern8(n);
            break;
        case 9:
            pattern9(n);
            break;
        case 10:
            pattern10(n);
            break;
        default:
            cout<<"Incorrect Choice! Choose between 1 to 10";
    }
        
    //pattern1(n);
    return 0;
}



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

void pattern11(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<1-(i+j)%2;
        }
        cout<<endl;
    }
}

void pattern12(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=2*n; j++){
            if(j>=i+1 && j<=2*n-i){
                cout<<" ";
            }
            else{
                cout<<(j<=n)*j+(j>n)*(2*n+1-j);
            }
        }
        cout<<endl;
    }
}

void pattern13(int n){
    int ct=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<ct<<" ";
            ct++;
        }
        cout<<endl;
    }
}

void pattern14(int n){
    for(int i=1; i<=n; i++){
        for(char ch='A'; ch<'A'+i; ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}

void pattern15(int n){
    for(int i=1; i<=n; i++){
        for(char ch='A'; ch<'A'+n+1-i; ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}

void pattern16(int n){
    for(char i='A'; i<'A'+n; i++){
        for(char j='A'; j<=i; j++){
            cout<<i;
        }
        cout<<endl;
    }
}

void pattern17(int n){
    int cols = 2*n-1;
    char ch = 'A'-n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=cols; j++){
            if(j<=n-i || j>=n+i) cout<<" ";
            else{
                char temp = ch + (j<=n)*(j) + (j>n)*(cols-j+1);
                cout<<temp;
            }
        }
        cout<<endl;
        ch++;
        //  for(int j=1; j<=spaces; j++){
        //     cout<<" ";
        //  }
        //  for(char j=)
        //  for(int j=1; j<=spaces; j++){
        //     cout<<" ";
        //  }
    }
}

void pattern18(int n){
    int ch='A'-1;
    for(int i=n; i>0; i--){
        for(char j=ch+i; j<=ch+n; j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern19(int n){
    int space = 0, stars=n;
    for(int i=1; i<=2*n; i++){
        if(i>n){
            stars++;
            space-=2;
        }
        for(int j=1; j<=stars; j++) cout<<"*";
        for (int j=1; j<=space; j++) cout<<" ";
        for(int j=1; j<=stars; j++) cout<<"*";
        if(i<=n){
            stars--;
            space+=2;
        }
        cout<<endl;
    }
}

void pattern20(int n){
    int space, stars;
    for(int i=1; i<=2*n-1; i++){
        if(i>n){
            stars = 2*n-i;
            space = 2*n-2*stars;
        }
        else{
            stars=i;
            space=2*n-2*stars;
        }
        for(int j=1; j<=stars; j++) cout<<"*";
        for (int j=1; j<=space; j++) cout<<" ";
        for(int j=1; j<=stars; j++) cout<<"*";
        cout<<endl;
    }
}

void pattern21(int n){
    int stars, space=n-2;
    for(int i=1; i<=n; i++){
        if(i==1 || i==n){
            for(int j=1; j<=n; j++){
                cout<<"*";
            }
        }
        else{
            cout<<"*";
            for (int j=1; j<=n-2; j++) cout<<" ";
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern22(int n){
    int num = n;
    for(int i=1; i<=2*n-1; i++){
        int flag=-1; // initially the num is set to be decreased
        for(int j=1; j<=2*n-1; j++){
            if(i<=n){
                if(j==i) flag=0; // at j=i num stops decreasing
                if(j==2*n-i) flag=+1; // at j=2*n-i num starts increasing
                cout<<num;
                num+=flag;
            }
            else{
                if(j==2*n-i) flag=0; // for i>n at j=2*n-i num stops decreasing
                if(j==i) flag=+1; // at j=i num starts increasing
                cout<<num;
                num+=flag;
            }
        }
        num = n;
        cout<<endl;
    }
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
        case 11:
            pattern11(n);
            break;
        case 12:
            pattern12(n);
            break;
        case 13:
            pattern13(n);
            break;
        case 14:
            pattern14(n);
            break;
        case 15:
            pattern15(n);
            break;
        case 16:
            pattern16(n);
            break;
         case 17:
            pattern17(n);
            break;
        case 18:
            pattern18(n);
            break;
        case 19:
            pattern19(n);
            break;
        case 20:
            pattern20(n);
            break;
        case 21:
            pattern21(n);
            break;
        case 22:
            pattern22(n);
            break;
        default:
            cout<<"Incorrect Choice! Choose between 1 to 10";
    }
        
    //pattern1(n);
    return 0;
}



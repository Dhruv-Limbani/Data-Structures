#include<iostream>
using namespace std;

void pattern(int n){
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
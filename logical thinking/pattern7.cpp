#include<iostream>
using namespace std;

int main()
{
    /*
     because there are five lines and the starting index of "*" in each line is decreasing from 5 at first line to 1 in last line
    */
    for(int i=5; i>=1; i--){        
        /*
        in each line the number of stars following the starting star is increasing by the factor of 2
        */
        for(int j=1;j<=i+2*(5-i);j++)   
        {
            j<i?cout<<" ":cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}

//     *
//    ***
//   *****
//  *******
// *********
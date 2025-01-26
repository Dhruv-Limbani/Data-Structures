#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: This problem has 3 variations. They are stated below:

    Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

    Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

    Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
*/

int fact(int n){
    if(n==0) return 1;
    else{
        return n*fact(n-1);
    }
}

int nCr(int n, int r){
    int a=1,b=1;
    while(r>0){
        a*=n;
        b*=r;
        r--;
        n--;
    }
    return a/b;
}

// Variation 1

int pascalTriangle_1_brute_force(int r, int c) {
    vector<vector<int>> t;
    int i,j;
    for(i=0; i<r; i++){
        vector<int> row;
        row.push_back(1);
        for(j=1; j<i; j++) row.push_back(t[i-1][j]+t[i-1][j-1]);
        if(i>0) row.push_back(1);
        t.push_back(row);
    }
    return t[r-1][c-1];;
}

/*
    Complexity:
    TC: O(R*(R+1)/2)
    SC: O(R*C)
*/

int pascalTriangle_1_better(int r, int c) {
    return fact(r-1)/(fact(r-1-(c-1))*fact(c-1));
}

/*
    We use the binomial expansion formula
    Complexity:
    TC: O(R)+O(R-C)+O(C)
    SC: O(1)
*/

int pascalTriangle_1_optimized(int r, int c) {
    return nCr(r-1,c-1);
}

/*
    nCr = n!/(n-r)!r!
        = n(n-1)(n-2)..(n-r)!/(n-r)!r!
        = n(n-1)(n-2)..(n-r+1)/r(r-1)(r-2)..1
    
    5C2 = 5*4*3*2*1/(3*2*1)(2*1)
        = 5*4*3/3*2*1
        = 5*4/2*1
        
    We start from n and r, we keep multiplying n to n-1, n-2.. and r to r-1, r-2.. until r = 0. the final value of n/r will be nCr
    Complexity:
    TC: O(C)
    SC: O(1)
*/

// Variation 2
vector<int> pascalTriangle_2(int r) {
    vector<vector<int>> t;
    int i,j;
    for(i=0; i<r; i++){
        vector<int> row;
        row.push_back(1);
        for(j=1; j<i; j++) row.push_back(t[i-1][j]+t[i-1][j-1]);
        if(i>0) row.push_back(1);
        t.push_back(row);
    }
    return t[r-1];
}

/*
    Complexity:
    TC: O(R*(R+1)/2)
    SC: O(R*C)
*/

vector<int> pascalTriangle_2_better(int r) {
    vector<int> ans;
    for(int i=0; i<=r-1; i++){
        int coef = fact(r-1)/(fact(r-1-i)*fact(i));
        ans.push_back(coef);
    }
    return ans;
}

/*
    Complexity:
    Using binomial expansion formula
    TC: O(R^2)
    SC: O(1) --> because we are using a vector to store ans, it is not necessary as we can also print it.
*/

vector<int> pascalTriangle_2_optimized(int r) {
    vector<int> ans;
    ans.push_back(1); // since the first element will always be 1
    for(int i=1; i<=r-1; i++){
        ans.push_back(ans[i-1]*(r-i)/i);
    }
    return ans;
}

/*
    Let n = 5
    the 5th row in pascal's triangle is 1 4 6 4 1

    4C0                    4C1                 4C2                   4C3                    4C4

    4*3*2*1/(4*3*2*1)*1    4*3*2*1/(3*2*1)*1   4*3*2*1/(2*1)*(2*1)   4*3*2*1/1*(3*2*1)      4*3*2*1/1*(4*3*2*1)

    1/1                    4/1                 4*3/1*2               4*3*2/1*2*3            4*3*2*1/1*2*3*4

    1/1                    prev_elem*(row_number-col_number)/col_number ---> pattern
    
    Complexity:
    TC: O(R)
    SC: O(1)

    If we use the optimized approach of variation 1 in variation 2 it will take O(R*C) time.
*/


// Variation 3 

vector<vector<int>> pascalTriangle_3(int numRows) {
    vector<vector<int>> t;
    for(int i=0; i<numRows; i++){
        vector<int> r;
        r.push_back(1);
        for(int j=1; j<i; j++) r.push_back(t[i-1][j]+t[i-1][j-1]);
        if(i>0) r.push_back(1);
        t.push_back(r);
    }
    return t;
}

/*
    Complexity:
    TC: O(N*(N+1)/2)
    SC: O(N*(N+1)/2)
*/

vector<vector<int>> pascalTriangle_3_better(int r) {
    vector<vector<int>> t;
    for(int i=0; i<r; i++){
        vector<int> row;
        for(int j=0; j<=i; j++){
            int coef = fact(i)/(fact(i-j)*fact(j));
            row.push_back(coef);
        }
        t.push_back(row);
    }

    return t;
}

/*
    Complexity:
    Using binomial expansion formula
    TC: O(R^3)
    SC: O(1)
*/

vector<vector<int>> pascalTriangle_3_optimized(int r) {
    vector<vector<int>> t;
    for(int i=1; i<=r; i++){
        vector<int> row;
        row.push_back(1); //since 1st element is always 1
        for(int j=1; j<i; j++){
            row.push_back(row[j-1]*(i-j)/j);
        }
        t.push_back(row);
    }
    return t;
}

/*
    Complexity:
    Using optimized approach in variation 2
    TC: O(R^2)
    SC: O(1)
*/

int main()
{
    int r,c;
    cin>>r>>c;
    cout<<pascalTriangle_1_optimized(r,c)<<endl;
    vector<int> ans = pascalTriangle_2_better(r);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}
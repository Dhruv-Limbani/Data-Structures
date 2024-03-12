#include<bits/stdc++.h>
using namespace std;

void count_digits_1(int num){
    auto start = chrono::steady_clock::now();
    int ct=0;
    while(num){
        num/=10;
        ct++;
    }
    cout<<ct<<endl;
    /*
    complexity
    time: O(n) where "n" is number of digits
    space: O(1)
    */
}

void count_digits_2(int num){
    string n = to_string(num);
    cout<<n.length();
    /*
    complexity
    time: O(1)
    space: O(1)
    problem: num = 000340 output = 6
    */
}

void count_digits_3(int num){
    cout<<floor(log10f(num))+1<<endl;
    /*
    complexity
    time: O(1)
    space: O(1)
    previous approaches problem is solved but it gives -inf for input num = 0
    */
}

void reverse(int x) 
{
    long long int rev = 0;
    while(x){
        rev = rev*10 + x%10;
        x/=10;
    }
    //cout<<rev; // if rev exceeds the signed 32-bit integer range [-(2^31), 2^31 - 1] then it will have a garbage value 
    // hence we use the below code to return 0 in that case
    cout<<(rev<pow(2,31)-1 && rev>-pow(2,31))*rev<<endl;
    //cout<<(rev<INT_MAX && rev>INT_MIN)*rev<<endl;
    // INT_MAX and INT_MIN can be used instead of pow(2,31)-1 and -pow(2,31)
}

string check_palindrome(int x)
{
    if (x<0) return "Not a Palindrome";
    long long int rev = 0, num=x;
    while(x>rev){
        rev = rev*10 + x%10;
        x/=10;
    }
    // the above while loop reverses only the last half of the integer
    if(x==rev || x==rev/10) // we use 2nd condition in case of odd num of digits
        return "Palindrome";
    else
        return "Not a Palindrome";
    // works only for x in the signed 32-bit integer range [-(2^31), 2^31 - 1]
}

int main()
{
    int num;
    cin>>num;
    // count_digits_1(num);
    // count_digits_2(num);
    // count_digits_3(num);
    // reverse(num);
    cout<<check_palindrome(num);
    return 0;
}
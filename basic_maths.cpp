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

void gcp_brute_force(int n, int m){
    if(n<m){
        n = n + m;
        m = n - m;
        n = n - m;
    }
    int gcd = m;
    while(gcd>0){
        if(n%gcd==0 && m%gcd==0){
            cout<<gcd<<endl;
            break;
        }
        gcd--;
    }
    /*
    we all know that the GCD value of two numbers cannot exceed the smallest of the two numbers
    hence we intiate the gcd from smallest number and decrement it while we get a number that divides both the number
    complexity
    worst case that is for gcd(23,21), it will be O(m) where m is the smallest number
    */
}

void gcd_brute_force(int n, int m){
    if(n<m){
        n = n + m;
        m = n - m;
        n = n - m;
    }
    int gcd = m;
    while(gcd>0){
        if(n%gcd==0 && m%gcd==0){
            cout<<gcd<<endl;
            break;
        }
        gcd--;
    }
    /*
    we all know that the GCD value of two numbers cannot exceed the smallest of the two numbers
    hence we intiate the gcd from smallest number and decrement it while we get a number that divides both the number
    complexity
    worst case that is for gcd(23,21), it will be O(m) where m is the smallest number
    space complexity: requires an additional variable "gcd"
    */
}

void gcd_optimized(int n, int m){
    n+=m;
    do{
        n-=m;
        if(n<m){
        n = n + m;
        m = n - m;
        n = n - m;
        }
    }while(n%m);
    cout<<m<<endl;
    /*
    1) find the smallest of two numbers
    2)check whether the smallest divides biggest
    3) if not then decrement the value of biggest number by smallest number
    4) go back to 1
    5) if yes then print the current smallest number

    gcd(60,315)
    60 = 3x5x4
    315 = (3^2)x5x7

    gcd is 15

    so we can rewrite it as
    60 = 15*4
    315 = 15*21

    if we repeatedly deduct the smallest value from biggest number and update the numbers
    every time 15 will come out as common 15(21-4), 15(17-4), 15(13-4),...15(5-4), after this we will have two numbers
    15 and 60, 15 divides both 15 and 60 hence gcd is 15
    time complexity: O(n/m) 
    */
}

void gcd_super_optimized(int n,int m){
    int rem;
    if(n<m){
        n = n + m;
        m = n - m;
        n = n - m;
    }
    while(n%m){
        rem = n%m;
        n = m;
        m = rem;
    }
    /*
    check euclidean method for finding gcd for understanding the logic
    gcd(35,9) -> 35%9 = 8 -> 9%8 = 1 -> 8%1 -> 0
    the last nonzero remainder is the gcd which is in this case is 1 
    */
    cout<<m<<endl;
}

void is_amstrong(int n){
    int k=0,sum=0,m=n;
	while(n){
		k++;
		n/=10;
	}
	n=m;
	while(n){
		sum+=pow(n%10,k);
		n/=10;
	}
	if(sum==m) cout<<"It is an amstrong number"<<endl;
	else cout<<"It is not an amstrong number"<<endl;
}

void divisors(int num){
    int i = 1;
    while(i<num){
        if(num%i==0){
            cout<<i<<" ";
        }
        i++;
    }
    cout<<num<<endl;
    /*
    time complexity: O(n)
    advantage: output is sorted
    */
}

void divisors_optimized(int num){
    int i = 1, j=0;
    for(int i=1; i<=sqrt(num); i++){
        if(num%i==0){
            j = num/i;
            if(i==j){
                cout<<i<<endl;
            }
            else
                cout<<i<<" "<<j<<" ";
        }
    }
    /*
    all the divisors are paired to another divisor that when multiplied together makes a number
    so if we find 1 dividor, then the quotient is also a divisor.
    the square root of the number splits the pairs
    36: 1, 2, 3, 4, 6, 9, 12, 18, 36
        |  |  |  |  ^  |  |   |   |
        |  |  |  -------  |   |   |
        |  |  |-----------|   |   |
        |  |------------------|   |
        |-------------------------|

    time complexity: O(sqrt(n))
    disadvantage: output is not sorted
    */
}

bool isPrime(int n)
{
	if(n==1) return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
    /*
    Time complexity: O(sqrt(n))
    if there are no divisors till sqrt(n), that means there are no more divisors as the sqrt(n) splits the pairs of divisors
    check the logic of "divisors_optimized" function
    */
}

int main()
{
    int num;
    cin>>num;
    // count_digits_1(num);
    // count_digits_2(num);
    // count_digits_3(num);
    // reverse(num);
    // cout<<check_palindrome(num);
    // gcd_brute_force(60,314);
    // gcd_optimized(60,315);
    // gcd_super_optimized(27,9);
    // is_amstrong(num);
    // divisors(num);
    // divisors_optimized(num);
    return 0;
}
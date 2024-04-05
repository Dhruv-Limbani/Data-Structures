#include<bits/stdc++.h>
using namespace std;

int brute_force(int arr[], int n){
    int ct;
    for(int i=0; i<n; i++){
        ct=0;
        for(int j=0; j<n; j++){
            if(arr[i]==arr[j]) ct++;
        }
        if(ct==1) return arr[i];
    }
    return -1;
}

/*
    TC: O(N^2)
    SC: O(1)
*/

int better_approach(int arr[], int n){
    map<int, int> m;
    for(int i=0; i<n; i++) m[arr[i]]++;
    for(auto it: m) if(it.second==1) return it.first;
    return 0;
}
/*
    TC: O(n*log(n))
    SC: O(N)
*/

int optimal_approach(int arr[], int n){
    int a=0;
    for(int i=0; i<n; i++) a^=arr[i];
    return a;
}
/*
    XOR Property:
        a^a = 0
        0^a = a
*/

int optional_approach(int arr[], int n){
    int i=0;
    for(i=0; i<n-2; i+=2){
		if(arr[i]!=arr[i+1]) return arr[i];
	}
    return arr[i];
}
/*
    TC: O(N/2)
    SC: O(1)
    Works only for sorted array
*/


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<brute_force(arr,n);
    return 0;
}
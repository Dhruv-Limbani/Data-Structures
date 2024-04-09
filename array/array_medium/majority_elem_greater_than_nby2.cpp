#include <bits/stdc++.h>
using namespace std;

int brute_force(int *arr, int n){
	int th=n/2 + n%2, ct;
	for(int i=0; i<n-1; i++){
		ct=0;
		for(int j=i; j<n; j++){
			if(arr[i]==arr[j]) ct++;
			if(ct>=th) return arr[i];
		}
	}
	return arr[0];
}
/*
    TC: O(N^2)
    SC: O(1)
*/

int better_approach(int *arr, int n){
	int th=n/2 + n%2, ct;
	map<int,int> m;
    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
        if(m[arr[i]]>=th) return arr[i];
    }
    return 0;
}

/*
    Time Complexity: O(N*logN) + O(N), where N = size of the given array.
    Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

    Space Complexity: O(N) as we are using a map data structure.
*/

int optimal_approach(int *arr, int n){
    int ele,ct=0;
    for(int i=0; i<n; i++){
    if (ct == 0) {
        ele = arr[i];
        ct = 1;
        } 
    else if (ele == arr[i]) ct++;
    else ct--;
    }
	return ele;
}

/*
    Moore's Voting Algorithm
    TC: O(N)
    SC: O(1)

    watch YT for itiution
*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    return 0;
}
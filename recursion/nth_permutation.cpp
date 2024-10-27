#include<bits/stdc++.h>
using namespace std;

void get_permutations(vector<int> &perm, vector<int> &bitarr, int n, int &k, int &status){
    if(perm.size()==n){
        k--;
        if(k==0) status=1;
    }
    else{
        for(int i=1; i<=n; i++){
            if(bitarr[i]){
                bitarr[i] = 0;
                perm.push_back(i);
                get_permutations(perm, bitarr, n, k, status);
                if(status) break;
                perm.pop_back();
                bitarr[i] = 1;
            }
        }
    }
}
string getPermutation(int n, int k) {
    vector<int> perm, bitarr(n+1,1);
    string p;
    int status = 0;
    get_permutations(perm, bitarr, n, k, status);
    for(auto it: perm) p+=to_string(it);
    return p;
}

string getPermutation_version_2(int n, int k) {
    string s;
    int fact = 1;
    vector<int> nums;
    for(int i=1; i<n; i++){
        fact*=i;
        nums.push_back(i);
    }
    nums.push_back(n);
    k=k-1;
    while(true){
        s.push_back(nums[k/fact]+'0');
        nums.erase(nums.begin() + (k/fact));
        k %= fact;
        if(nums.size()==0) break;
        fact /= nums.size();
    }
    return s;
}
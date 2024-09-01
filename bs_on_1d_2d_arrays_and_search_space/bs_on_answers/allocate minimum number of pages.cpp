#include<bits/stdc++.h>
using namespace std;

bool is_possible(vector<int>& arr, int n, int m, int x){
    int ct=0,cs=0;
    for(int i=0; i<arr.size(); i++){
        if (ct + arr[i] <= x) ct += arr[i];
        else{
            ct=arr[i];
            cs++;
        }
    }
    if(ct>0 && ct<=x) cs++;
    if(cs>m) return false;
    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int l=arr[0], h=arr[0], mid, ans;
    for(auto it: arr){
        h+=it;
        l=max(l,it);
    }
    while(l<=h){
        mid = (l+h)/2;
        if(is_possible(arr, n, m, mid)){
            ans = mid;
            h = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}
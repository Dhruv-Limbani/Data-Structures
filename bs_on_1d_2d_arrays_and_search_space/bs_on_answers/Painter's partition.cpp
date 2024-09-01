#include<bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> boards, int k, int x){
    int cs = 0, ct = 1;
    for(auto it: boards){
        if(cs+it<=x) cs+=it;
        else{
            cs=it;
            ct++;
            if(ct>k) return false;
        }
    }
    return true;

}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int l=boards[0], h=0, mid, ans;
    for (auto it : boards) {
        l = max(l, it);
        h += it;
    }
    while(l<=h){
        mid = (l+h)/2;
        if(is_possible(boards,k,mid)){
            ans = mid;
            h = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}


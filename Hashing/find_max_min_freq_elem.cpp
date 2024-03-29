#include<bits/stdc++.h>
using namespace std;


/*
    Given an array 'v' of 'n' numbers. Your task is to find and return the highest and lowest frequency elements.
    If there are multiple elements that have the highest frequency or lowest frequency, pick the smallest element.
*/

vector<int> getFrequencies(vector<int>& v) {
    unordered_map<int, int> hash;
    vector<int> ans(2);
    for(auto it: v) hash[it]++;
    int max=INT_MIN, min=INT_MAX, max_freq_elem, min_freq_elem;
    for(auto it: hash){
        if( it.second>max || (it.second==max && it.first<ans[0]) ){
            max = it.second;
            ans[0] = it.first;
        }
        if( it.second<min || (it.second==min && it.first<ans[1]) ){
            min = it.second;
            ans[1] = it.first;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> ans = getFrequencies(v);
    for(auto it: ans) cout<<it<<" ";
    return 0; 
}

/*
    Time Complexity: O(N), where N = size of the array. The insertion and retrieval operation in the map takes O(1) time.
    Space Complexity:  O(N), where N = size of the array. It is for the map we are using.
*/
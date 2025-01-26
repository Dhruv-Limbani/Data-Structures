#include <bits/stdc++.h>
using namespace std;

vector<int> brute_force(vector<int>& nums) {
    vector<int> ans;
    for(auto it: nums){
        if(ans.size()==2) break;
        if(ans.size() == 0 || it!=ans[0])
        {
            int ct=0;
            for(auto it2: nums) if(it==it2) ct++;
            if(ct>nums.size()/3) ans.push_back(it);
        }
    }
    return ans;
}

/*
Observation : if there are 7 elements then elements that appear for more than floor(7/3) will be the answer
hence for an element to be an answer it has to appear atleast 3 times. So if there are n elements only 2 of them can be the majority elements.
Complexity:
    Time : O(n^2)
    Space: O(1)
*/

vector<int> brute_force_2(vector<int>& nums) {
    vector<int> ans;
    map<int,int> m;
    for(auto it: nums){
        if(ans.size()==2) break;
        if(ans.size() == 0 || it!=ans[0])
        {
            m[it]++;
            if(m[it]>nums.size()/3) ans.push_back(it);
        }
    }
    return ans;
}

/*
Time Complexity: O(N*logN), where N = size of the given array.
Reason: We are using a map data structure. Insertion in the map takes logN time. 
And we are doing it for N elements. So, it results in the first term O(N*logN).
If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N^2).

Space Complexity: O(N) as we are using a map data structure. 
We are also using a list that stores a maximum of 2 elements. That space used is so small that it can be considered constant.
*/

vector<int> optimal_approach(vector<int>& nums) {
    if(nums.size()==1) return nums;
    vector<int> ans;
    int ct1=0, ct2=0, n1=INT_MIN, n2=INT_MIN;
    for(auto it: nums){
        if(ct1==0 && n2!=it){
            n1=it;
            ct1++;
        }
        else if(ct2==0 && n1!=it){
            n2=it;
            ct2++;
        }
        else if(it==n1) ct1++;
        else if(it==n2) ct2++;
        else{
            ct1--;
            ct2--;
        }
    }
    ct1=0;
    ct2=0;
    for(auto it: nums){
        if(n1==it) ct1++;
        else if(n2==it) ct2++;
    }
    if(ct1>nums.size()/3) ans.push_back(n1);
    if(ct2>nums.size()/3) ans.push_back(n2);
    return ans;
}

/*
    Used moore's voting algortihm.
    This algorithm can be used to return the highest K elements that appeared in the array more than array_size/(K+1) times. In our case, K = 2.

    The major Intuition behind this algorithm is that maintaining voting variable for the candidates:
        Increase the variable if you faced the candidate in your iteration.
        Decrease the variable if you faced another element.
        If the variable reaches 0, look for another promising candidate.
    Why this work?
        Assume we are searching for the element that appeared more than array_size / 2 times, 
        then we are sure that the voting variable can has value array_size / 2 + 1 and 
        if we decreased it for all other elements in the array it will also stay positive enough
        to tell us the desired candidate. 

    Complexity:
        Time : O(n)+O(n) ~ O(n)
        Space: O(1)
*/

int main()
{
    vector<int> nums = {2,2}, ans;
    ans = brute_force_2(nums);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}
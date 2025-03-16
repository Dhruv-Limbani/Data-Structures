#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size(), prod=1;
            vector<int> product(n);
            for(int i=n-1; i>=0; i--){
                product[i] = prod;
                prod *= nums[i];
            }
            prod = 1;
            for(int i=0; i<n; i++){
                product[i] = product[i]*prod;
                prod *= nums[i];
            }
            return product;
        }

        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size(), prod=1, zeros=0;
            for(auto it: nums){
                if(it) prod*=it;
                else zeros++;
            }
            if(zeros>1) return vector<int>(nums.size(),0); 
            vector<int> product(n, prod);
            for(int i=0; i<n; i++){
                if(zeros>0){
                    product[i] = (nums[i]==0)?prod:0;
                }
                else product[i] /= nums[i];
            }
            return product;
        }
};
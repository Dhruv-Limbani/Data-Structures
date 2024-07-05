#include<bits/stdc++.h>
using namespace std;

/*
    Variety-1

    Problem Statement:

    There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
    Without altering the relative order of positive and negative elements, you must return 
    an array of alternately positive and negative values.

    Note: Start the array with positive elements.
*/


void brute_force(int *arr, int n){
    for(int i=0; i<n; i++){
        if(i%2==0 && arr[i]<0){
            int j=i;
            while(arr[j]<0 & j<n) j++;
            if(j<n){
                swap(arr[i],arr[j]);
                while (j - 1 > i) {
                    swap(arr[j - 1], arr[j]);
                    j--;
                }
            }
            else return;
        }
        else if(i%2!=0 && arr[i]>0){
            int j=i;
            while(arr[j]>0 & j<n) j++;
            if(j<n){
                swap(arr[i],arr[j]);
                while (j - 1 > i) {
                    swap(arr[j - 1], arr[j]);
                    j--;
                }
            }
            else return;
        }

    } 
}
/*
    // can skip this one
    TC: O(N^3)
    SC: O(1)
*/

void better_approach(int *arr, int n){
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(arr[i]>=0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    int j=0,k=0;
    for(int i=0; i<n/2; i++){
        arr[2*i] = pos[i];
        arr[2*i +1] = neg[i]; 
    }
}

/*
    Segregating pos and neg elements in different vectors and then placing them at correct place in final array.
    TC: O(N + N)
    SC: O(N)

*/

void optimal_approach(int *arr, int s){
    int a[s];
    for(int i=0; i<s; i++) a[i]=arr[i];
    int p=0,n=1;
    for(int i=0; i<s; i++){
        if(a[i]>=0){
            arr[p]=a[i];
            p+=2;
        }
        if (a[i] < 0) {
            arr[n] = a[i];
            n += 2;
        }
    }
}
/*
    Approach:

    In this optimal approach, we will try to solve the problem in a single pass and 
    try to arrange the array elements in the correct order in that pass only.
    
    We know that the resultant array must start from a positive element so we initialize the positive index 
    as 0 and negative index as 1 and start traversing the array such that whenever we see the first positive element, 
    it occupies the space at 0 and then posIndex increases by 2 (alternate places).
    
    Similarly, when we encounter the first negative element, it occupies the position at index 1, 
    and then each time we find a negative number, we put it on the negIndex and it increments by 2.
    
    When both the negIndex and posIndex exceed the size of the array, we see that the whole array 
    is now rearranged alternatively according to the sign.


    TC: O(N)
    SC: O(N)
    
*/

//  the above 3 algos work if there are equal number of positive and negative element


// variety 2: unequal number of pos and neg elements

void optimal_approach_2(int *arr, int n){
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(arr[i]<0) neg.push_back(arr[i]);
        else pos.push_back(arr[i]);
    }
    if(pos.size()>=neg.size()){
        for(int i=0; i<neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int idx = 2*neg.size();
        for(int i=neg.size(); i<pos.size(); i++){
            arr[idx] = pos[i];
            idx++;
        }
    }
    else{
        for(int i=0; i<pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int idx = 2*pos.size();
        for(int i=pos.size(); i<neg.size(); i++){
            arr[idx] = neg[i];
            idx++;
        }
    }
}

/*
    Time Complexity: O(2*N) { The worst case complexity is O(2*N) which is a combination of O(N)
    of traversing the array to segregate into neg and pos array and O(N) for adding the elements 
    alternatively to the main array}.

    Explanation: The second O(N) is a combination of O(min(pos, neg)) + O(leftover elements). 
    There can be two cases: when only positive or only negative elements are present, 
    O(min(pos, neg)) + O(leftover) = O(0) + O(N), and when equal no. of positive and negative elements 
    are present, O(min(pos, neg)) + O(leftover) = O(N/2) + O(0). So, from these two cases, 
    we can say the worst-case time complexity is O(N) for the second part, and 
    by adding the first part we get the total complexity of O(2*N).

    Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and 
    negative element arrays, where N = size of the array A}.
*/

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    return 0;
}
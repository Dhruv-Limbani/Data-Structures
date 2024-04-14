#include <bits/stdc++.h> 
using namespace std;
void generate_permutations(vector<int> a, vector<bool> check, vector<vector<int>>&b){
    for(int i=1; i<=check.size()-1; i++){
        if(!check[i]){
            check[i] = 1;
            a.push_back(i);
            if(a.size()==check.size()-1){
                b.push_back(a);
                return;
            }
            generate_permutations(a,check,b);
            check[i] = 0;
            a.pop_back();
        }
    }
    return;
}   
/*
    TC: O(N*N!)
    SC: O(N*N! + N)
*/

void generate_permutations_using_swap(int p, vector<int> arr, vector<vector<int>> &ans){
    if(p==arr.size()-1){
        ans.push_back(arr);
    }
    else{
        for(int i=p; i<arr.size(); i++){
            swap(arr[i],arr[p]);
            generate_permutations_using_swap(p+1,arr,ans);
            swap(arr[i],arr[p]);
        }
    }
}
/*
    TC: O(N*N!)
    SC: O(1)
*/

void using_inbuilt_func(vector<int> &arr, int n){
    next_permutation(arr.begin(),arr.begin()+n);
}

void better_approach(vector<int> &arr, int n){
    vector<bool> check(n+1,0);
    int idx,f=0;
    for(int i=n-1; i>=0; i--){
        check[arr[i]] = 1;
        for(int j=arr[i]+1; j<=n; j++){
            if(check[j]){
                arr[i] = j;
                check[j] = 0;
                idx=i;
                i=-1;
                f=1;
                break;
            }
        }
    }
    if(f){
        for(int i=idx+1; i<n; i++){
            for(int j=1; j<=n; j++){
                if(check[j]){
                    arr[i] = j;
                    check[j] = 0;
                    break;
                }
            }
        }
    }
    else{
        for(int i=1; i<=n; i++) arr[i-1] = i;
    }
}

void optimal_approach(vector<int> &arr, int n){
    vector<bool> check(n+1,0);
    int mx=arr[n-1],i;
    for(i=n-1; i>=0; i--){
        check[arr[i]]=1;
        if(arr[i]>=mx){
            mx=arr[i];
        }
        else{
            int j=arr[i]+1;
            while(!check[j]) j++;
            arr[i] = j;
            check[j] = 0;
            j=0;
            while(j<=n){
                while(!check[j] && j<=n) j++;
                if(j==n+1) break;
                arr[++i] = j;
                check[j]=0;
            }
            return;
        }
    }
    for(int i=0; i<n; i++) arr[i] = i+1;
    return;
}

/*
    1 3 2 5 4
    next permutation = 1 3 4 2 5
    we loop through the arr from the end and keep track of the maximum element
    if at any point i, the current element is less than maximum element then it means
    that arr[0..i-1] does not need to be changed as we have elements greater than arr[i] to replace it
    meanwhile we also maintain a boolean check array where if check[i] = 1 that means number i is available else locked
    once we find that element which is less than the max element (basically we are finding element which is breaking the acending order of elements in array when it is read backwards)
    in given example
    1 3 2 5 4

    4 < 5 but 5 is not < 2 therefore 2 is our break point. check array at this point will be [0 1 0 1 1]
    once we find the breakpoint we replace it with the element in arr[i+1..n-1] just greater than it. 
    in this case it is 4 and then we mark check[4] = 0
    so
    1 3 4 5 4   and our check array looks like [0 1 0 0 1]
    initialize i to just after break point
    now loop through check array, if you find check[j] = 1 than arr[i] = j and increment i & j; 
    final ans 1 3 4 2 5

    another way to do this is to just reverse the arr[i+1..n-1] after swapping. in that case we don't need check array
    now what we do is 
    TC: O(N)
    SC: O(N)
*/


void optimal_approach_2(vector<int> &arr, int n){
    int idx = -1;
    for(int i=n-1; i>=1; i--){
        if(arr[i-1]<arr[i]){
            idx = i-1;
            break;
        }
    }
    if(idx==-1){
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=n-1; i>idx; i--){
        if(arr[i]>arr[idx]){
            swap(arr[i],arr[idx]);
            break;
        }
    }
    reverse(arr.begin()+idx+1,arr.end());
    return;
}

/*
    TC: O(N + N + N) = O(N)
    SC: O(1)
*/

int main()
{
    int n; 
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    
    // vector<vector<int>> b;
    // vector<int> a;
    // vector<bool> check(n+1,0);
    // generate_permutations(a,check,b);
    // int i=0,f=0;
    // for(auto it: b){
    //     if(f){
    //         for(auto j: it) cout<<j<<" ";
    //         return 0;
    //     }
    //     if(it==arr){
    //         f=1;
    //     }
    // }
    // for(auto it: b){
    //     for(auto j: it) cout<<j<<" ";
    //     return 0;
    // }

    optimal_approach(arr,n);
    // int fact = n;
    // for(int i=n-1; i>0; i--) fact*=i;
    // for(int i=0; i<fact; i++){
    //     for(auto it: arr) cout<<it<<" ";
    //     optimal_approach(arr,n);
    //     cout<<endl;
    // }
    for(auto it: arr) cout<<it<<" ";
    return 0;
}
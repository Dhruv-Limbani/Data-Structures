#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of integers: [1, 2, 1, 3, 2] and we are given some queries: [1, 3, 4, 2, 10]. 
    For each query, we need to find out how many times the number appears in the array. 
    For example, if the query is 1 our answer would be 2, and if the query is 4 the answer will be 0.

    Brute Force:
    take each from query arr and compare it with each in int arr, if match then increase the counter.
    takes O(Q*N)

    Optimized approach (using hashing):
    1) Assume or find the highest possible number in query array
    2) Pre-storing : Declare hash array of the size equal to highest number + 1(for ease of referencing)
    3) Fetching : for each num in query array, fetch hash[num] and increase the value by 1

*/

// Array Hashing
vector<int> count_num_freq(int arr[], int n){
    vector<int> hash(13,0); // we assume 12 is the highest number
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    return hash;
}

vector<int> count_char_freq(string s, int n){
    vector<int> hash(26,0); // if s contains both upper case and lower case then adjust size accordingly
    for(int i=0; i<n; i++){
        hash[s[i]-'a']++; // if s contains only upper case then hash[s[i]-'A'], if it contains both then simply hash[s[i]] 
    }
    return hash;
}


// hashing using map (for hashing numbers like 10^9 or higher)
map<int, int> count_num_freq_map(int arr[], int n){
    map<int, int> freq_map;
    for(int i=0; i<n; i++){
        freq_map[arr[i]]++;
    }
    return freq_map;
}

map<char, int> count_char_freq_map(string s, int n){
    map<char, int> freq_map;
    for(int i=0; i<n; i++){
        freq_map[s[i]]++;
    }
    return freq_map;
}

/*
    if we want to fetch the value of a key that does not exist in the map,
    the map will always return 0 in C++ and null in Java.

    The total time complexity will be O(N * time taken by map data structure).

    Storing(i.e. insertion) and fetching(i.e. retrieval) in a C++ map, both take always O(logN) time complexity, where N = the size of the map. 

    But the unordered_map in C++ and HashMap in Java, both take O(1) time complexity to perform storing(i.e. insertion)
    and fetching(i.e. retrieval). Now, it is valid for the best case and the average case. 

    But in the worst case, this time complexity will be O(N) for unordered_map. 
    Now, the worst case occurs very very rarely. It almost never happens and most of the time, we will be using unordered_map.

    Our first priority will be always to use unordered_map and then map. 
    If unordered_map gives a time limit exceeded error(TLE), we will then use the map.

    The time complexity in the worst case is O(N) because of the internal collision.

    In the map data structure, the data type of key can be anything like int, double, pair<int, int>, etc. 
    But for unordered_map the data type is limited to integer, double, string, etc. 
    We cannot have an unordered_map whose key is pair<int, int>.
*/

int main()
{
    // int n,q;
    // cin>>n>>q;
    // int arr[n],qr[q];
    // for(int i=0; i<n; i++) cin>>arr[i];
    // for(int i=0; i<q; i++) cin>>qr[i];
    // vector<int> hash = count_num_freq(arr, n);
    // for(int i=0;i<q;i++){
    //     cout<<qr[i]<<"--"<<hash[qr[i]]<<endl;
    // }

    // string s;
    // cin>>s;
    // int q;
    // cin>>q;
    // char qr[q];
    // for(int i=0; i<q; i++) cin>>qr[i];
    // vector<int> hash = count_char_freq(s, s.length());
    // for(int i=0;i<q;i++){
    //     cout<<qr[i]<<"--"<<hash[qr[i]-'a']<<endl;
    // }

    // int n,q;
    // cin>>n>>q;
    // int arr[n],qr[q];
    // for(int i=0; i<n; i++) cin>>arr[i];
    // for(int i=0; i<q; i++) cin>>qr[i];
    // map<int,int> hash = count_num_freq_map(arr, n);
    // for(int i=0;i<q;i++){
    //     cout<<qr[i]<<"--"<<hash[qr[i]]<<endl;
    // }    

    string s;
    cin>>s;
    int q;
    cin>>q;
    char qr[q];
    for(int i=0; i<q; i++) cin>>qr[i];
    map<char,int> hash = count_char_freq_map(s, s.length());
    for(int i=0;i<q;i++){
        cout<<qr[i]<<"--"<<hash[qr[i]]<<endl;
    }

    return 0;
}


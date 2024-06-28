#include<bits/stdc++.h>
using namespace std;

void explainPair(){

    pair<int, int> p = {1,3};
    cout << p.first <<" "<< p.second<<endl;
    pair<int, pair<int, int>> p1 = {1,{2,3}};
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;
    pair<int, int> arr[] = {{1,2}, {2,5}, {5,1}};
    cout<<arr[1].second;
}

void explainVector(){

    vector<int> v;
    v.push_back(1);
    v.emplace_back(2); //similar to push_back but better

    vector<pair<int,int>> vec; 

    vec.push_back({1,2}); // need to put 1,2 inside curly braces while using push back
    vec.emplace_back(1,2); // no need to put curly braces, it itself will understand

    vector<int> v2(5, 100); // creates {100, 100, 100, 100, 100}
    vector<int> v3(5); // creates {0,0,0,0,0}; instances may be a garbage value depending on the compiler

    vector<int> v4(v); // copys v into v4; 

    vector<int>::iterator it = v.begin(); // it stores the memory address of the first element in v
    it++; //it moves to the next memory address
    cout<<*(it)<<" "<<endl; //*(it) is the value stored at the memory

    it = it+2; // it jumps 2 memory addresses; for ex {1,2,3,4,5}, if its pointing at 1 then it goes to point at 3
    cout<<*(it)<<" "<<endl;

    vector<int>::iterator it2 =  v.end(); //it points to the memory address just after that of last element, it-- will make 'it' point to the last element's address
    
    // --------
    // never used!
    vector<int>::reverse_iterator it3 = v.rend(); // reverse end; it points to mem adr just before that of 1st element it
    vector<int>::reverse_iterator it4 = v.rbegin(); // reverse begin; points to mem adr of last element; it++ will point to 2nd last and so on
    //---------

    cout<<v[0]<<" "<<v.at(0)<<endl; // both are same but latter one is just for the knowledge. Use V[0]!

    cout<< v.back() << " "<<endl; // stores last element

    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++){
        cout<<*(it)<<" ";
    }
    
    cout<<endl;
    // instead of writing "vector<int>::iterator" everytime we can use auto
    // auto in c++ automatically assigns a vaule to a relevant datatype
    // for ex: auto a = "dhruv"; will automatically assigns string "dhruv" to 'a' and will consider 'a' as string variable
    for(auto it = v.begin(); it!=v.end(); it++){
        cout<<*(it)<<" ";
    }

    cout<<endl;
    for(auto it : v){  // here 'it' is of int datatype so we don't need star  
        cout<<it<<" ";
    }

    //{10,20,12,23}
    v.erase(v.begin()+1); // erase will delete the element v.being()+1
    //{10,12,23}

    //{10,20,30,40,50}
    v.erase(v.begin()+2, v.begin()+4); // will delete everyting in [Start,end): end is not included
    //{10,20,50}


    // insert function
    vector<int> vec2(2,100); //{100, 100}
    vec2.insert(vec2.begin(), 300); //{300,100,100}
    vec2.insert(vec2.begin()+1,2,10); // inserts 2 instances of 10 at 2nd position
    //{300, 10, 10, 100, 100}

    vector<int> copy(2,50); //{50, 50}
    vec2.insert(vec2.begin(), copy.begin(), copy.end()); // inserts the entire 'copy' vector

    cout<<vec2.size(); // number of elements in the vec

    cout<<vec2.back(); //Returns a read-only (constant) reference to the data at the last element of the %vector.

    cout<<vec2.front(); // Returns a read/write reference to the data at the first element of the %vector.
    // {10,20}
    vec2.pop_back(); // {10}

    vec2.swap(v); // will swap the vectors;

    vec2.clear(); // erases the entire vector

    cout<<v.empty(); // returns true if vector is empty else false
}

void explainList()
{
    list<int> ls;

    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2,4}
    ls.push_front(5); // {5,2,4}
    ls.emplace_front(3); // {2,4}

    // rest funcs same as vector
    // begin, end, rend, rbegin, rend, clear, insert, size, swap

    // list internally uses doubly linked list where as vector uses singly linked list
    // hence some operations of list are faster then those of vector  
}

void explainDeque()
{
    deque<int>dq;
    dq.push_back(2); // {2}
    dq.emplace_back(4); // {2,4}
    dq.push_front(5); // {5,2,4}
    dq.emplace_front(3); // {2,4}

    dq.pop_back();
    dq.pop_front();

    cout<<dq.back()<<endl;  // last elem in dq
    cout<<dq.front(); // first elem in dq
}

void explainStack()
{
    stack<int> st;
    st.push(1); //{1}
    st.push(2); //{2,1}
    st.push(3); //{3,2,1}
    st.push(4); //{4,3,2,1}
    st.emplace(5); //{5,4,3,2,1}

    cout<<st.top()<<endl; // prints 5; indexing is invalid in stack
    st.pop(); // {4,3,2,1}

    cout<<st.top()<<endl; // 4
    cout<<st.size()<<endl; // prints size of stack
    cout<<st.empty()<<endl; // returns 1 if stack is empty

    stack<int>st1, st2;
    st1.swap(st2);

    // all the operations in stack takes O(1) time.

}

void explainQueue()
{
    queue<int> q;
    q.push(1); //{1}
    q.push(2); //{1,2}
    q.emplace(4); //{1,2,4}

    q.back() += 5; // 4+5 = 9

    cout<<q.back()<<endl; // 9
    cout<<q.front()<<endl; // 1
    q.pop();
    cout<<q.front(); //2

    // size, empty, swap same as stack
    // all operations in O(1)
}

void explainPQ()
{
    priority_queue<int> pq;
    //largest int or char or lexicographically largest string stays at the top
    // aka max heap
    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.emplace(6); //{8,6,5,2}

    cout<<pq.top()<<endl; // 8
    pq.pop(); //{6,5,2}

    cout<<pq.top()<<endl; //6

    // size, swap, empty function same as others;

    // following is the syntax for declaring the priority queue which stores the minimum at the top
    // aka min heap
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(5); //{5}
    pq1.push(2); //{2,5}
    pq1.push(8); //{2,5,8}
    pq1.emplace(6); //{2,5,6,8}

    cout<<pq1.top()<<endl; //2

    // time complexities
    // push & pop -> O(log(n))
    // top -> O(1)
}

void explainSet()
{
    // stores everything in sorted order and stores unique

    set<int> st;
    st.insert(1); //{1}
    st.emplace(2); //{1,2}
    st.insert(2); // {1,2}
    st.insert(4); //{1,2,4}
    st.insert(3); //{1,2,3,4}

    auto it = st.find(3); // returns an iterator pointing at 3

    auto it1 = st.find(5); // will return an iterator pointing at the adrs after the last elem as 5 is not present in the set

    st.erase(4); //deletes 4 and maintains the sorted order, takes logarithmic time

    int ct = st.count(1); // returns 1 if 1 is present else 0

    st.erase(it); // we can also erase an elem by passing mem addr, takes constant time : O(1)

    //st = {1,2,3,4,5}
    auto it2 = st.find(2);
    auto it3 = st.find(4);
    st.erase(it2, it3); // erases [it2,it3) i.e. elems 2 & 3

    // begin, empty, swap, end, rbegin, rend, size are same as those of vectors
    // everything happens in logarithmic time complexity
}
void explainMultiSet()
{
    // allows multiple occurences of same value
    multiset<int>ms;
    ms.insert(1); // {1}
    ms.insert(1);// {1,2}
    ms.insert(2); // {1,1,2}

    ms.erase(1); // erases all 1s
    
    int ct = ms.count(1);
    cout<<ct;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1); 
    ms.insert(1);
    ms.erase(ms.find(1)); // erases only the first occurence of 1


    
    // to erase the first 2 occurence of 1
    auto itend = ms.find(1);
    itend++;
    itend++;
    ms.erase(ms.find(1), itend); 
    
    // rest all functions are same as those of set 

}

void explainUSet()
{
    unordered_set<int> st;
    //stores unique values but order is randomized
    // lower_bound and upper_bound functions do not work
    // rest all functions are same as above, it does not stores
    // in any particular order it has better complexity than set 
    // in most cases, except some when collision happens

    // time complexity is O(1) in most of the cases and very very rarely there is a chance of linear time i.e. O(n);
}

void explainMap()
{
    // map<key, value> m; key, value can be anything - int, float, pair etc
    map<int, int> mpp;
    map<int, pair<int,int>> mpp1;
    map<pair<int,int>, int> mpp2;

    // map stores unique keys in sorted order 

    mpp[1] = 2;  // key = 1, value = 2  // mpp = [{1,2}]
    mpp.emplace(3,1); // mpp = [{1,2},{3,1}]
    mpp.insert({2,4}); // mpp = [{1,2},{2,4},{3,1}]

    
    mpp2[{2,3}] = 10;

    for(auto it: mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<mpp[1]<<endl; //2
    cout<<mpp[5]; // prints 0 or null as key does not exist

    auto it = mpp.find(3);
    auto it2 = mpp.find(5); // if 5 is not present, it will point after the end

    auto it3 = mpp.lower_bound(2);
    auto it4 = mpp.upper_bound(3);

    // erase, swap, size, empty, are same as above    
    // takes O(log(n)) time
}

void explainMultiMap(){
    // everything same as map, only it can store multiple values with same keys
    // [{1,2},{1,3},{2,4}] is allowed
    // only mpp[key] cannot be used here 
}

void explainUnorderedMap(){
    // same as set and unordered set difference
    // same as map but stores keys in randomized order, stores unique keys only
    // in almost all cases works in constant time O(1)
    // only in the worst case which might be very very rare, it will take O(N) time 

}


bool comp(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second<p2.second) return true;
    else if(p1.second>p2.second) return false;
    else{
        if(p1.first>p2.first) return true;
        else return false;
    }
}

//  MANDATORY
void explainExtra(){

    vector<int> a;
    a.push_back(3);
    a.push_back(2);
    a.emplace_back(5);
    a.insert(a.begin()+1,7);
    a.push_back(1);

    int arr[] = {3,6,23,6,8,-5,2};

    // syntax : sort(start iterator, last iterator) ; last iterator points to addrs next to last element
    // it's like [start,end) end is not included
    sort(a.begin(),a.begin()+a.size()); // to sort vector

    for(auto it: a){
        cout<<it<<" ";
    }
    cout<<endl;

    sort(arr,arr+sizeof(arr)/sizeof(arr[0])); // to sort array

    for(auto it: arr){
        cout<<it<<" ";
    }

    cout<<endl;
    // {1,3,5,2}
    sort(arr+2,arr+4);
    // {1,3,2,5}

    sort(arr, arr+4, greater<int>()); // sorts in increasing order

    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<endl;
    //custom sorting
    pair<int,int> p[] = {{1,2},{2,1},{4,1}}; // array of pair

    // to sort p in increasing order of 2nd element in pair but if the 2nd element is same then sort in decreasing order of first element

    sort(p,p+sizeof(p)/sizeof(p[0]),comp); // if comp returns false we the sort function swaps the two elements
    // while writing comparator or comp function for sorting, always analyse in terms of 2 elements
    // {{4,1},{2,1},{1,2}} 

    for(auto it: p){
        cout<<"("<<it.first<<", "<<it.second<<") ";
    }
    cout<<endl;

    int num = 7;
    int cnt = __builtin_popcount(num); // returns the number of set bits (1s) in the binary form of num
    cout<<cnt<<endl;

    long long llnum = 2748176583753;
    cnt = __builtin_popcountll(llnum);
    cout<<cnt<<endl;

    string s = "123";
    sort(s.begin(),s.end());
    // to print all the permutation of string s
    do{
        cout<<s<<endl;
    } while(next_permutation(s.begin(),s.end()));

    // if s was 213, then it would have printed 213,231,321 and null
    // hence to get all the permutation of string, it is important that string is sorted


    int maxi = *max_element(arr,arr+4); // the maximum element in the container
    int mini = *min_element(arr,arr+4);
    cout<<mini<<" "<<maxi;
    
}

int main()
{
    //explainPair();
    //explainVector();
    //explainDeque();
    //explainStack();
    //explainQueue();
    //explainPQ();
    //explainSet();
    // explainMultiSet();
    // explainMap();
    explainExtra();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void reverse_array(int arr[], int i, int j){
    if(i>=j){
        return;
    }
    int temp;
    temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
    reverse_array(arr,i+1,j-1);
}

/*
    for swapping
    we can also use swap(arr[i],arr[j])
    or
    arr[i] = arr[i]+arr[j];
    arr[j] = arr[i]-arr[j];
    arr[i] = arr[i]-arr[j];
    this will save extra space
    we can also use library function reverse(arr,arr+n)

    time complexity: O(n)
    space complexity: O(1)
*/

int main()
{
    int num;
    cout<<"Enter size: "<<endl;
    cin>>num;
    int arr[num];
    for(int i=0; i<num; i++) cin>>arr[i];
    cout<<"Array before: "<<endl;
    for(int i=0; i<num; i++) cout<<arr[i]<<" ";
    cout<<endl;
    reverse_array(arr,0,num-1);
    cout<<"Array after reversing: "<<endl;
    for(int i=0; i<num; i++) cout<<arr[i]<<" ";
    return 0;
}
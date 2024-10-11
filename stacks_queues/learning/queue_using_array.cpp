#include<bits/stdc++.h>
using namespace std;

class QUEUE{
    public:
        int *arr, start, end, mx_size=1000;
        QUEUE(int max_size){
            mx_size = max_size;
            arr = new int [mx_size];
            start = -1;
            end = -1;
        }
        QUEUE(){
            arr = new int [mx_size];
            start = -1;
            end = -1;
        }
        int size = 0;
        void push(int x){
            if (size!=mx_size){
                size++;
                if(end==-1){
                    start=0;
                    end=0;
                }
                else end = (end + 1)%mx_size;
                arr[end] = x;
            }
            else{
                cout<<"queue_full";
            }
        }
        int pop(){
            if(start!=-1){
                int temp = arr[start];
                size--;
                if(size==0){
                    start = -1;
                    end = -1;
                }
                else start = (start+1)%mx_size;
                return temp;
            }
            else return -1;
        }
        int top(){
            if(start!=-1) return arr[start];
            else return -1;
        }
        int end(){
            if(start!=-1) return arr[end];
            else return -1;
        }
};

int main(){

  QUEUE q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size << endl;
}
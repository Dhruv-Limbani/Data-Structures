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

class STACK{
    QUEUE q;
    public:
        void push(int x){
            int n = q.size;
            q.push(x);
            for(int i=0; i<n; i++) q.push(q.pop());
        }
        int pop(){
            return q.pop();
        }
        int top(){
            return q.top();
        }
        int size(){
            return q.size;
        }
};

int main() {
  STACK s;
  s.push(3);
  s.push(2);
  s.push(4);
  s.push(1);
  cout << "Top of the stack: " << s.top() << endl;
  cout << "Size of the stack before removing element: " << s.size() << endl;
  cout << "The deleted element is: " << s.pop() << endl;
  cout << "Top of the stack after removing element: " << s.top() << endl;
  cout << "Size of the stack after removing element: " << s.size();

}
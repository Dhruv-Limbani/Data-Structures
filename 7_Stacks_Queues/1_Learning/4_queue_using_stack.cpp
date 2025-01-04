#include<bits/stdc++.h>
using namespace std;

class STACK{
    public:    
        int *arr, tp, mx_size;
        STACK(){
            mx_size = 1000;
            arr = new int[mx_size];
            tp = -1;
        }
        STACK(int max_size){
            mx_size = max_size;
            arr = new int[mx_size];
            tp = -1;
        }
        void push(int x){
            tp+=1;
            arr[tp] = x;
        }
        int pop(){
            if(tp!=-1) return arr[tp--];
            else return -1;
        }
        int top(){
            if(tp!=-1) return arr[tp];
            else return -1;
        }
        int size(){
            return tp+1;
        }
};


class QUEUE{
    public:
        STACK st;
        int bck;
        void push(int x){
            STACK temp;
            while(st.size()!=0){
                temp.push(st.pop());
            }
            st.push(x);
            bck = st.top();
            while(temp.size()){
                st.push(temp.pop());
            }
        }
        int pop(){
            return st.pop();
        }
        int top(){
            return st.top();
        }
        int back(){
            return bck;
        }
        int size(){
            return st.size();
        }
};

int main() {
  QUEUE q;
  q.push(3);
  q.push(4);
  cout << "The element poped is " << q.pop() << endl;
  q.push(5);
  cout << "The top of the queue is " << q.top() << endl;
  cout << "The size of the queue is " << q.size() << endl;
}
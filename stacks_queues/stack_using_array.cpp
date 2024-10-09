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

int main(){

  STACK s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.top() << endl;
  cout << "Size of stack before deleting any element " << s.size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.size() << endl;
  cout << "Top of stack after deleting an element " << s.top() << endl;
  return 0;    
}
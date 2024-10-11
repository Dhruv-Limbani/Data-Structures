#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int x){
            data=x;
            next=NULL;
        }
        Node(int x, Node* n){
            data = x;
            next = n;
        }
};

class Stack{
    public:
        Node* head;
        int size;
        Stack(){
            head = nullptr;
            size = 0;
        }
        void push(int x){
            Node* temp = new Node(x, head);
            head = temp;
            size++;
        }
        int pop(){
            if(size){
                int temp = head->data;
                head = head->next;
                size--;
                return temp;
            }
            else return -1;
        }
        int top(){
            if(size) return head->data;
            else return -1;
        }
        bool IsEmpty(){
            return (size==0);
        }
};

int main() {
  Stack s;
  s.push(10);
  cout << "Element popped: " << s.pop() << "\n";
  cout << "Stack size: " << s.size << "\n";
  cout <<"Stack empty or not? "<<s.IsEmpty()<<"\n";
  cout << "stack's top element: " << s.top() << "\n";
  return 0;
}

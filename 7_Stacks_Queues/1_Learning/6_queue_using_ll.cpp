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

/*
    Enqueue     (Insert Node at Rare End )
    Dequeue     (Delete Node from Front ) 
    Peek        (Return value of Front Node without Dequing)
    Empty       (Returns True when queue is empty else False)
    Size        (Returns size of Queue) 
*/


class Queue{
    public:
        Node* front, *rare;
        int size;
        Queue(){
            front = NULL;
            rare = NULL;
            size = 0;
        }
        void enqueue(int x){
            if(size==0){
                front = new Node(x, NULL);
                rare = front;
            }
            else{
                rare->next = new Node(x,NULL);
                rare = rare->next;
            }
            size++;
            return;
        }
        int dequeue(){
            if(size){
                Node* temp = front;
                front = front->next;
                int t = temp->data;
                delete temp;
                size--;
                return t;
            }
            else return -1;
        }
        int top(){
            if(size) return front->data;
            else return -1;
        }
        bool IsEmpty(){
            return (size==0);
        }
};

int main()
{
    Queue Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);
    Q.dequeue();
    cout<<"The size of the Queue is "<<Q.size<<endl;
    cout<<"The Peek element of the Queue is "<<Q.top()<<endl;
    return 0;
}   
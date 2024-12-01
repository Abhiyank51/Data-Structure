#include<iostream>
#include<stdio.h>
using namespace std;

class Node {
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Queue{
    private:
        int front;
        int rear;
        int size;
        Node **Q;
    public:
        // Non parameterized constructor 
        // That sets value by default when an object of type Queue is formed.
        Queue(){
            front=rear=-1;
            size=10;
            Q=new Node*[size];
        }

        // Parameterized constructor
        Queue(int size){
            front=rear=-1;
            this->size=size;
            Q=new Node*[this->size];
        }

        // Operations
        void enqueue(Node *x);
        Node* dequeue();
        int isEmpty(){return front ==rear;}
        void Display();

};

void Queue::enqueue(Node *x){
    if(rear==size-1){
        cout<<"Queue Full"<<endl;
    }
    else{
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue(){
    Node* x = NULL;
    if(front == rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        front++;
        x = Q[front];
    }
    return x;
}


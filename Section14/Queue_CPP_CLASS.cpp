#include<iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
        // Non parameterized constructor 
        // That sets value by default when an object of type Queue is formed.
        Queue(){
            front=rear=-1;
            size=10;
            Q=new int[size];
        }

        // Parameterized constructor
        Queue(int size){
            front=rear=-1;
            this->size=size;
            Q=new int[this->size];
        }

        // Operations
        void enqueue(int x);
        int dequeue();
        void Display();
};

void Queue::enqueue(int x){
    if(rear==size-1){
        cout<<"Queue Full"<<endl;
    }
    else{
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue(){
    int x = -1;
    if(front == rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::Display(){
    for (int i = front+1; i <=rear; i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
    
}
int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.Display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    cout<<endl;
    q.Display();
    return 0;
}
// This is a queue basic operationa header file to make a binary tree
//  We do some changes in queue code as make a tree node name as node here 
//  and also change int *Q to Node **Q 

// struct Node **Q; sir can you pls elaborate on why we are using a double pointer ?
/*

ANS -- 
Queue is going to store address of nodes.
so struct Node *Q

Queue is an array of address of Nodes and we are going to create Queue dynamically.

so struct Node **Q
*/

#include<iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int size;
    int front;
    int rear;
    Node **Q;  // as this is a node type pointer so we shold take sdouble pointer.
};

// Create queue
void create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node **)malloc(q->size*sizeof(Node *));  // create an array to initialize queue
}

// enqueue
void enqueue(struct Queue *q, Node * x){
    if((q->rear+1)%q->size == q->front){
        printf("Queue is full");
    }
    else{
        q->rear= (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

// dequeue
Node * dequeue(struct Queue *q){
    Node * x = NULL;
    if(q->front==q->rear){
        printf("Queue is empty\n");
    }
    else{
        q->front = (q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front == q.rear;
}




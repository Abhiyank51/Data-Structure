#include<iostream>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

// Create queue
void create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));  // create an array to initialize queue
}

// enqueue
void enqueue(struct Queue *q, int x){
    if(q->rear == q->size-1){
        printf("Queue is full");
    }
    else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// dequeue
int dequeue(struct Queue *q){
    int x = -1;
    if(q->front==q->rear){
        printf("Queue is empty\n");
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

// display queue
void Display(struct Queue q){
    for (int i = q.front+1; i <=q.rear; i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
    
}

int main()
{
    struct Queue q;
    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);

    Display(q);

    printf("%d \n",dequeue(&q));
    printf("%d \n",dequeue(&q));
    printf("%d \n",dequeue(&q));
    printf("%d \n",dequeue(&q));
    printf("%d \n",dequeue(&q));
    Display(q);
    return 0;
}
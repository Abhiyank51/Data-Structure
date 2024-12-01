#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

// push()
void push(int x){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL){
        printf("Stack is fill\n");
    }
    else{
        t->data = x;
        t->next = top;
        top=t;
    }
}

// pop()
int pop(){
    struct Node *t;
    int x = -1;

    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

// Display
void display(){
    struct Node *p;
    p=top;
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

// stacktop

int stackTop(){
    if(top){
        return top->data;
    }
    return -1;
}

// isempty()
int isEmpty(){
    return top?0:1;
}

// isFull()
int isFull(){
    struct Node *p = new Node;
    int r = p?1:0;
    free(p);
    return 0;
}
int main(){
    push(10);
    push(20);
    push(30);

    display();

    printf("%d ",pop());
    
    return 0;
}
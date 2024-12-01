#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL,*second=NULL,*third=NULL;


// Create a first LL
void create(int A[] ,int n){
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = A[0];
    first->next=NULL;
    last = first;

    for(i=1; i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Display a LL
void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

// function to check whether a loop present or not.
int isLoop(struct Node *f){
    struct Node *p, *q;
    p=q=f;
    do
    {
        p = p->next;
        q = q->next;
        if(q!=NULL){    // if q is not null than only q take one step forward 
            q=q->next;
        }
    } while (p && q && p!=q);
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    struct Node *t1, *t2;
    int A[] = {10,20,30,40,50};
    create(A,5);

    // creating a loop
    t1=first->next->next;  //at node 30 
    t2=first->next->next->next->next;  // at last node 50
    t2->next=t1;    // loop created as t2 on last node points to t1 at node 30

    printf("%d\n", isLoop(first));
    return 0;
}
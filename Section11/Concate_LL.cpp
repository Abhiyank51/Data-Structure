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

// Create a 2nd LL
void create2(int A[] ,int n){
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second -> data = A[0];
    second->next=NULL;
    last = second;

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

// Code to concat two LL
void Concat(struct Node *p, struct Node *q){
    p=first;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    q = NULL;    
}

// Merging two LL
void Merge(struct Node *p,struct Node *q)
 {
    struct Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
            
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
            
        }
    }
 if(p)last->next=p;
 if(q)last->next=q;
 }

int main(){
    // int A[] = {50,40,10,30,20};
    // int B[] = {1,2,3,4,5};
    // create(A,5);
    // create2(B,5);

    // Concat(first,second);

    // printf("Concated LL\n");
    // Display(first);
    // printf("\n\n");


    // printf("First--\n");
    // Display(first);
    // printf("\n\n");

    // printf("Second--\n");
    // Display(second);
    // printf("\n\n");



    // CODE FOR MERGING
    int A[] = {1,2,4};
    int B[] = {1,3,4};
    create(A,3);
    create2(B,3);

    Merge(first,second);

    printf("Merged LL\n");
    Display(third);
    printf("\n\n");





    return 0;
}
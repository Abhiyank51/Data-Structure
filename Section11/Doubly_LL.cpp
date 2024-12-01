#include<iostream>
using namespace std;

// structure for doubly ll
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

// create a doubly ll
void create(int A[], int n){
    struct Node *t,*last;
    int i;

    first = new Node;
    first->data = A[0];
    first->prev=first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=new Node;
        t->data = A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

// display a doubly ll
void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

// length of a doubly ll
int length(struct Node *p){
    int len = 0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

// insert in a doubly ll
void insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if(index<0 || index>length(p)){
        return ;
    }
    if(index==0){
        t= new Node;
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(i=0; i<index-1;i++){
            p=p->next;
        }
        t=new Node;
        t->data=x;
        t->next=p->next;
        t->prev=p;
        if(p->next){
            p->next->prev=t;
        }
        p->next=t;
    }
}

// delete a node 

int Delete(struct Node *p, int index){
    int x=-1,i;

    if(index<1 || index>length(p)){
        return -1;
    }
    if(index==1){
        first=first->next;
        if(first){
            first->prev=NULL;
        }
        x=p->data;
        delete p;
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }
        x=p->data;
        delete p;
    }
    return x;
}


// Reverse a doubly ll
void Reverse(struct Node *p){
    struct Node *temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5); 

    printf("Length is: %d\n",length(first));
    
    Display(first);

    Reverse(first);

    Display(first);


    // insert(first,2,25);
    // Display(first);

    // Delete(first,2);
    // Display(first);

    return 0;
}
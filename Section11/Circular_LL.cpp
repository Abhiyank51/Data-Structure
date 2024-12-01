#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*Head;

// create a circluar ll
void create(int A[],int n){
    int i;
    struct Node *t,*last;

    // creating first node that is head
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;  // now it is circular
    last=Head;

    for(i=1; i<n; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next = last->next;
        last->next = t;
        last=t;
    }
}

// display a circluar ll
void Display(struct Node *h){
    do{
       printf("%d ",h->data);
       h=h->next;
    } while (h!=Head);
    printf("\n");
}

// create a circluar ll using recursion
int RDisplay(struct Node *h){
    static int flag = 0;
    if(h!=Head || flag==0){
        flag=1;
        printf("%d ",h->data);
        RDisplay(h->next);
    }
    flag=0;
}

// Length on circluar LL
int Length(struct Node *p){
    int len = 0;
    p= Head;
    do
    {
        len++;
        p=p->next;
    } while (p!=Head);
    return len;
}


// Insert a new node in a circular LL
void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;

    if(index<0 || index>Length(Head))
        return ;
    if(index==0){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        if(Head==NULL){
            Head=t;
            Head->next=Head;
        }
        else{
            while(p->next!=Head) p=p->next;
            p->next = t;
            t->next = Head;
            Head=t;
        }
    }
    else{
        for(i=0; i<index-1; i++){
            p=p->next;
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->next=p->next;
            p->next=t;
        }
    }
}

// Delete node in circluar LL
int Delete(struct Node *p, int index){
    struct Node *q;
    int i,x;

    if(index<0 || index>Length(Head)){
        return -1;
    }

    // delete head node 
    if(index==1){
        while(p->next!=Head) p=p->next;
        x=Head->data;

        // if only one node is present 
        if(Head==p){
            delete Head;
            Head=NULL;
        }
        // delete head and move head to ita next node
        else{
            p->next=Head->next;
            delete Head;
            Head=p->next;
        }
    }

    // delete in between nodes 
    else{
        for(i-0; i<index-1;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}


int main()
{
    int A[] = {2,3,4,5,6,7};
    create(A,6);

    Insert(Head,2,10);

    printf("Length of LL is %d \n",Length(Head));
    RDisplay(Head);

    printf("\n");
    Delete(Head,2);
    RDisplay(Head);

    return 0;
}
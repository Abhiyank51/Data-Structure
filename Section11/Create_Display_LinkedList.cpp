#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL;  // global pointer -- can directly access or pass as parameter 
// first initialize as NULL b/c initially LL is empty. 


// Create a LL
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

// Recursive fucntion to display LL
// void RDisplay(struct Node *p){
//     if(p!=NULL){
//         printf("%d ",p->data);
//         RDisplay(p->next);
//     }
// }



// this will reversely print the LL because we call recursive function firstly so only when all 
// recursive display function calles then on return time we get the print of element in reverse 
void TDisplay(struct Node *p){
    if(p!=NULL){
        TDisplay(p->next);
        printf("%d ",p->data);
    }
}


// Count the no. of nodes 
int count(struct Node *p){
    int count = 0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

// Count using recursion
int Rcount(struct Node *p){
    if(p!=NULL){
        return Rcount(p->next) + 1;
    }
    else{
        return 0;
    }
}


// Sum of the elements in LL
int Sum(struct Node *p){
    int s = 0;
    while(p!=NULL){
        s += p->data;
        p = p->next;
    }
    return s;
}

// Sum recursively
int Rsum(struct Node *p){
    if(p!=NULL){
        return Rsum(p->next) + p->data;
    }
    else{
        return 0;
    }
}


// MAX element in LL
int max(struct Node *p){
    int max = INT32_MIN;
    while(p!=NULL){
        if(p->data>max){
            max = p->data;
        }
        p=p->next;
    }
    return max;
}

// Recursice approach 
int Rmax(struct Node *p){
    int x = INT32_MIN;
    if(p==0){
        return 0;
    }
    x = max(p->next);
    return x>p->data?x:p->data;
}



// MIN element in LL
int min(struct Node *p){
    int min = INT32_MAX;
    while(p!=NULL){
        if(p->data<min){
            min = p->data;
        }
        p=p->next;
    }
    return min;
}

// Recursice approach 
int Rmin(struct Node *p){
    int x = INT32_MAX;
    if(p==0){
        return 0;
    }
    x = min(p->next);
    return x<p->data?x:p->data;
}

// Search for element in LL
struct Node * LSearch(struct Node *p,int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
} 

// Recursive search
struct Node * RSearch(struct Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(key==p->data){
        return p;
    }
    return RSearch(p->next,key);
}


// Improved search method 
struct Node * ILSearch(struct Node *p,int key){

    struct Node *q;

    while(p!=NULL){
        if(key==p->data){
            q->next = p->next;
            p->next = first;
            first= p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
} 


// Insert element in a node 
void Insert(struct Node *p, int index, int x){

    struct Node *t;

    if(index < 0 || index > count(p)){
        return;
    }

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0){
        t->next = first;
        first = t;
    }
    else{
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        t->next =p->next;
        p->next = t;
    }
}

// Inserting a new node in sorted LL
void SortedInsert(struct Node *p, int x){
    struct Node *t, *q=NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data =x;
    t->next = NULL;

    if(first == NULL){  // if LL is empty
        first= t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

// Delete a Node from LL
int Delete(struct Node *p, int index){
    struct Node *q;  // tail pointer
    int x = -1;

    if(index < 1 || index > count(p)){
        return -1;
    }
    if(index == 1){
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else{
        for(int i = 0; i < index -1;i++){
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

// Check whether the given LL is sorted or not  
int isSorted(struct Node *p){
    int x = INT32_MIN;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        else{
            x = p->data;
            p =p->next;
        }
    }
    return 1;
}

// Delete duplicates from a LL
int DelDuplicate(struct Node *p){
    struct Node *q = p->next;
    while(q!=NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

// Reverse a LL
// 1. Using an array 
void Reverse1(struct Node *p){
    int *A, i=0;    
    struct Node *q=p;
    A = (int *)malloc(sizeof(int)*count(p));
    while(q!=NULL){
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data = A[i];
        q =q->next;
        i--;
    }
}

// 2. using reversing links approach -- sliding pointer 
void Reverse2(struct Node *p){
    struct Node *q=NULL, *r=NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p=p->next;
        q->next=r;
    }
    first = q;
}

// 3. Recursive function to reverse a LL
void Reverse3(struct Node *q, struct Node *p){
    if(p!=NULL){
        Reverse3(p,p->next);
        p->next = q;
    }
    else{
        first = q;
    }

}





int main()
{
    // for check duplicate
    int A[] = {1,1,2,3,3};
    create(A,5);
    Display(first);
    DelDuplicate(first);
    printf("\n");
    Display(first);

    // Reverse1(first);
    // Display(first);


    // int A[] = {3,5,7,10,15};
    // int B[] = {10,20,30,40,50};  // for inserting in sorted LL
    // struct Node *temp;   //for search function
    // create(A,5);
    // create(B,5);

    // SortedInsert(first, 35);
    // Display(first);
    // printf("\n\n");

    // Delete(first,2);  // delete 20
    // Display(first);
    // printf("\n\n");

    // if(isSorted(first)){
    //     printf("Sorted\n");
    // }
    // else{
    //     printf("Not Sorted.\n");
    // }


    // OLD CODE 
    // Display(first);

    // printf("\n");
    // printf("Length is %d",Rcount(first));

    // printf("\n");
    // printf("Sum of LL is %d",Rsum(first));

    // printf("\n");
    // printf("Max element of LL is %d",Rmax(first));

    // printf("\n");
    // printf("Min element of LL is %d",Rmin(first));

    // printf("\n");
    // temp = ILSearch(first,15);
    // if(temp!=NULL){
    //     printf("Key is Found %d ",temp->data);
    // }
    // else{
    //     printf("Key not found ");
    // }

    // printf("\n");
    // Display(first);

    // Insert(first, 3, 11);
    // Display(first);

    return 0;
}
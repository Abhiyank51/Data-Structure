#include<iostream>

// we create a header file of queue as we need operations of queue like - enqueue, dequeue, isEmpty to create a binary search tree
// so for them we make a header file and get their code seperate and export here otherwiae if we include them here the code become too messy and long.
#include "Queue.h"  // here is how we include header files exists in our local directory
using namespace std;

struct Node *root = NULL;

void Treecreate(){
    struct Node *p, *t;  // create two pointers to handle flow 
    int x;
    struct Queue q;
    create(&q,100);  // create queue and initialize max size = 100
    printf("Enter root value ");
    scanf("%d", &x);   // get value to insert in first root node created 
    root = (struct Node *)malloc(sizeof(struct Node));    // create first root node 
    root->data = x;      // insert value of x to root node 
    root->lchild = root->rchild=NULL;    // make left and right child of root node null
    enqueue(&q,root);          // insert address of root node to the queue q

    while(!isEmpty(q)){       // run a while loop until q become empty
        p = dequeue(&q);      // get address of a node from queue and assign pointer p to that node 
        
        // for left child
        printf("Enter left child of %d ",p->data);   
        scanf("%d", &x);          // get data for left child 
        if(x!=-1){                // if there exists a left child then do the code inside it 
            t = (struct Node *)malloc(sizeof(struct Node));      // create a new node for left child by help of t pointer
            t->data = x;          // insert data x 
            t->lchild=t->rchild=NULL;    // make it's left and right child of left node null
            p->lchild=t;           // point pointer p(that is on root now) to the left child
            enqueue(&q,t);          // insert address of left node to the queue q
        }
        // for right child 
        printf("Enter right child of %d ",p->data); 
        scanf("%d", &x);    // get data for right child 
        if(x!=-1){          // if there exists a right child then do the code inside it 
            t = (struct Node *)malloc(sizeof(struct Node));   // create a new node for right child by help of t pointer
            t->data = x;        // insert data x 
            t->lchild=t->rchild=NULL;       // make it's left and right child of left node null
            p->rchild=t;            // point pointer p(that is on root now) to the right child
            enqueue(&q,t);      // insert address of right node to the queue q
        }
    }
}


// preorder finding function

void preorder(struct Node *p){
    if(p){
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

// inorder finding function

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}


// Postorder finding function

void Postorder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

// count no of nodes 
int count(struct Node *root){
    if(root!=NULL){
        return count(root->lchild) + count(root->rchild) +1;
    }
    return 0;
}

// height of tree
int height(struct Node *root){
    int x=0,y =0;
    if(root==0){
        return 0;
    }
    x = height(root->lchild);
    y = height(root->rchild);
    if(x>y){
        return x+1;
    }
    else{
        return y+1;
    }
}

int main()
{
    Treecreate();
    printf("\n");
    printf("Preorder of given tree \n");
    preorder(root);
    printf("\n");

    printf("Inorder of given tree \n");
    Inorder(root);
    printf("\n");

    printf("Postorder of given tree \n");
    Postorder(root);
    printf("\n");

    printf("Count %d ", count(root));
    printf("\n");
    printf("Height %d ", height(root));


    return 0;
}
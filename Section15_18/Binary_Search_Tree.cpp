#include<iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;


// Iterative function to Insert node in a BST  
void Insert(int key){
    struct Node *t = root;
    struct Node *r, *p;   // r is a tail pointer and p is user to create a new node 

    if(root==NULL){
        p = new Node();   // if it is the first node - create new node
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }

    while(t!=NULL){
        r=t;
        if(key<t->data){
            t=t->lchild;
        }
        else if(key > t->data){
            t=t->rchild;
        }
        else{
            return;
        }
    }
    p = new Node();   // now to insert left and right chile of root node 
    p->data=key;
    p->lchild=p->rchild=NULL;

    if(key<r->data){
        r->lchild=p;
    }
    else{
        r->rchild=p;
    }
}

// Recursive function to Insert node in a BST  
struct Node * RInsert(struct Node *p, int key){
    struct Node *t = NULL;
    if(p==NULL){
        t=new Node();
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key<p->data){
        p->lchild = RInsert(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild = RInsert(p->rchild,key);
    }
    else{
        return p;    // if node to inser is already present in BST then don't do anything just return
    }
}

// Height of tree - use in delete function
int Height(struct Node *p){
    int x,y;
    if(p==NULL) return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}

// To find Inorder predecessor of a node 
struct Node *InPre(struct Node *p){
    while(p && p->rchild !=NULL){
        p=p->rchild;
    }
    return p;
}


// To find Inorder successor of a node 
struct Node *InSucc(struct Node *p){
    while(p && p->lchild !=NULL){
        p=p->lchild;
    }
    return p;
}



// Recursive function to Delete node in a BST  
struct Node *Delete(struct Node *p, int key){

    struct Node *q;
    if(p==NULL){
        return NULL;
    }

    // for to delete leaf node - 
    if(p->lchild == NULL && p->rchild == NULL){
        if(p==root){
            root =NULL;
        }
        free(p);
        return NULL;
    }

    if(key<p->data){
        p->lchild = Delete(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild = Delete(p->rchild,key);
    }
    // if heigth of left subtree is greater then right subtree then delete element from left subtree(inorder predecessor)
    // else delete element form right subtree(inroder successor), if their height are equal then delete from any of the side.
    else{
        if(Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;  //replace data
            p->lchild = Delete(p->lchild, q->data);
        }
        else{
            q = InSucc(p->rchild);
            p->data = q->data;  //replace data
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

// To find Inorder of BST 
void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}


// To search for an element in BST 
struct Node *Search(int key){
    struct Node *t = root;
    while(t!=NULL){
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else    
            t=t->rchild;
    }
    return NULL;
}


int main()
{
    struct Node *temp;
    // Insert(10);
    // Insert(5);
    // Insert(20);
    // Insert(8);
    // Insert(30);

    root = RInsert(root,10);
    RInsert(root,5);
    RInsert(root,20);
    RInsert(root,8);
    RInsert(root,30);

    Delete(root,20);

    Inorder(root);  // as inorder traversal returns elements of bst in sorted order 
    printf("\n");

    temp = Search(20);
    if(temp!=NULL){
        printf("element %d is found\n", temp->data);
    }
    else{
        printf("element is not found\n");
    }
    return 0;
}
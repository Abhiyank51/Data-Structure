#include<iostream>
using namespace std;

struct Node {
    struct Node *lchild;
    int data;
    int height;    // as we need height to calc. balance factor
    struct Node *rchild;
}*root=NULL;

// Finding height of given node of tree
int NodeHeight(struct Node *p){
    int hl,hr;

    // for height of left subtree first check that p is not null && check is p has left child then is true take height of left child else 0
    hl = p && p->lchild ? p->lchild->height:0;

    // for height of right subtree first check that p is not null && check is p has right child then is true take height of right child else 0
    hr = p && p->rchild ? p->rchild->height:0;

    // whichever is greater in height add 1 to it and set height of node
    return hl>hr? hl+1:hr+1;
}



// Balance factor finding function  -- height of leftsubtree - height of rightsubtree
int BalanceFactor(struct Node *p){
    int hl,hr;

    // for height of left subtree 
    hl = p && p->lchild ? p->lchild->height:0;

    // for height of right subtree 
    hr = p && p->rchild ? p->rchild->height:0;

    return hl-hr;
}


// LL ROTATION
struct Node *LLRotation(struct Node *p){
    // here we need three pointers 
    // -- one on root node
    // -- second on root->lchild  (pl)
    // -- third on root->lchild->rchild  (plr) -- as during ALL rotation this rchild attach to as root->lchild


    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild=plr;
    p->height = NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root==p){
        root=pl;
    }
    return pl;  //new root
}

// LR Rotation
struct Node *LRRotation(struct Node *p){
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root==p){
        root=plr;
    }
    return plr; //new root
}

// Recursive function to Insert node in a BST  
struct Node * RInsert(struct Node *p, int key){
    struct Node *t = NULL;

    if(p==NULL){
        t=new Node();
        t->data = key;
        t->height=1;   // here we start height from 1 onwards can also take height=0
/*
if height=1
        |Node|  --> height=3
        /
    |leftNode|   --> height=2
    /
|leftNode|  -->hieght=1
********************
if height=0
        |Node|  --> height=2
        /
    |leftNode|   --> height=1
    /
|leftNode|  -->hieght=0
*/

        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key<p->data)
        p->lchild = RInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild = RInsert(p->rchild,key);

    p->height=NodeHeight(p);

    // Perform necessary rotations 
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1){
        return LLRotation(p);
    }
    // else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1){
    //     return LRRotation(p);
    // }
    // else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1){
    //     return RRRotation(p);
    // }
    // else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1){
    //     return LRRotation(p);
    // }
    return p;    // if node to inser is already present in BST then don't do anything just return
}


int main()
{
    // FOR LL ROTAION
    // root = RInsert(root,10);
    // RInsert(root,5);
    // RInsert(root,2);

    // FOR LR ROTATION
    root = RInsert(root,50);
    RInsert(root,10);
    RInsert(root,20);    //--> can see answer on debug as we not implement diplay function

    return 0;
}
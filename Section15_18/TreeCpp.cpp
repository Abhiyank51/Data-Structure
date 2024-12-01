#include <iostream>
#include "TreeQueuecpp.h"
using namespace std;

class Tree {
public:
    // if we make all dummy variables for all function then we make the below data member as private.

    Node *root;    // data member of class Tree
    Tree() { root = NULL; }   //constructor 

    void CreateTree();
    // below is the dummy function for Preorder like this we can make for other also
    
    void Preorder(){Preorder(root);} // function overloading -- create a function without parameter that call same function that is with parameter, 
    // now we dont have to pass root in main function simply call it 
    void Preorder(Node *p);

    void Postorder(){Postorder(root);}
    void Postorder(Node *p);

    void Inorder(){Inorder(root);}
    void Inorder(Node *p);

    void LevelOrder(){LevelOrder(root);}
    void LevelOrder(Node *p);


    int count(Node *root);

    int Height(){return Height(root);}
    int Height(Node *root);
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
 
    printf("Enter root value ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();

        printf("Enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        printf("Enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

// preorder finding function

void Tree::Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

// inorder finding function

void Tree::Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

// Postorder finding function

void Tree::Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Tree::LevelOrder(struct Node *root)
{
    Queue q(100);

    printf("%d ", root->data);
    q.enqueue(root);

    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}


// to count the no. of nodes 
int Tree::count(struct Node *root){
    if(root){
        cout<<count(root->lchild) + count(root->rchild)+1;
    return 0;
    }
}

// to get height of tree 
int Tree::Height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}




int main()
{
    Tree t;
    t.CreateTree();
    cout<<endl;

    // cout<<"Preorder ";
    // t.Preorder(t.root);
    // cout<<endl;

    // the below also work without pass root as parameter 
    cout<<"Preorder ";
    t.Preorder();
    cout<<endl;

    cout<<"Postorder ";
    t.Postorder(t.root);
    cout<<endl;

    cout<<"Inorder ";
    t.Inorder(t.root);
    cout<<endl;

    cout<<"Level Order ";
    t.LevelOrder(t.root);
    cout<<endl;


    return 0;
}
// structure of stack
#include<iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    struct Node **S;
};

// create stack
void Stackcreate(struct Stack *st,int size){
    st->size=size;
    st->top=-1;
    st->S=(struct Node **)malloc(st->size*sizeof(struct Node *)); 
}


// push()
void push(struct Stack *st, struct Node * x){
    if(st->top==st->size-1){
        printf("Stack overflow\n");
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

// pop()
struct Node * pop(struct Stack *st){

    struct Node *x = NULL;   // deleted value data store in x.

    if(st->top==-1){
        printf("Stack underflow\n");
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int isEmptyStack(struct Stack st){
    if(st.top==-1){
        return 1;
    }
    return 0;
}

int isFullStack(struct Stack st){
    return st.top==st.size-1;
}

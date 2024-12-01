#include<iostream>
#include<stdlib.h>
using namespace std;

// structure of stack
struct Stack{
    int size;
    int top;
    int *S;
};

// create stack
void create(struct Stack *st){
    printf("Enter size ");
    scanf("%d", &st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int)); 
}

// display stack 
void Display(struct Stack st){
    int i;
    for(i=st.top; i>=0; i--){
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

// push()
void push(struct Stack *st, int x){
    if(st->top==st->size-1){
        printf("Stack overflow\n");
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

// pop()
int pop(struct Stack *st){

    int x = -1;   // deleted value data store in x.

    if(st->top==-1){
        printf("Stack underflow\n");
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

// peek
int peek(struct Stack st, int index){
    int x = -1;
    if(st.top - index + 1 <0){
        printf("Position in inValid.");
    }
    else{
        x = st.S[st.top-index+1];
    }
    return x;
}

// isempty()
int isEmpty(struct Stack st){
    if(st.top == -1){
        return 1;
    }
    return 0;
}

// isfull()
int isFull(struct Stack st){
    if(st.top ==st.size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

// stackTop()
int stackTop(struct Stack st){
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);


    // printf("%d \n",pop(&st));
    printf("element is %d \n",peek(st,6));


    Display(st);
    return 0;
}
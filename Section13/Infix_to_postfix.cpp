#include<iostream>
#include<string.h>

using namespace std;

struct Node{
    char data;
    struct Node *next;
}*top=NULL;

// push()
void push(char x){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL){
        printf("Stack is fill\n");
    }
    else{
        t->data = x;
        t->next = top;
        top=t;
    }
}

// pop()
char pop(){
    struct Node *t;
    char x = -1;

    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

// Display
void display(){
    struct Node *p;
    p=top;
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

// stacktop
int stackTop(){
    if(top){
        return top->data;
    }
    return -1;
}

// isempty()
int isEmpty(){
    return top?0:1;
}

// isFull()
int isFull(){
    struct Node *p = new Node;
    int r = p?1:0;
    free(p);
    return 0;
}
// here we handle only 4 operators with associativity L-R
// check precedence 
int pre(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

// check whether the given is operand or operator
int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;   // it is not an operand 
    }
    else{
        return 1;   // it is an operand 
    }
}

// infix to postfix conversion function
char * InfixToPostfix(const char *infix){
    int i = 0, j=0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i])>pre(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++] = pop();
            }
        }
    }
    while(top!=NULL){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    const char *infix = "a+b*c-d/e"; 
    push('#');

    char *postfix =InfixToPostfix(infix);

    printf("%s ", postfix);
    return 0;
}
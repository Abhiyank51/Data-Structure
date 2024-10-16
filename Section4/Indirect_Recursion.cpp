#include<iostream>
using namespace std;

// because we call funB before its declaration so it will get error that's why we have to add prititype of funB() here.
void funB(int n);   

void funA(int n){
    if(n>0){
        printf("%d ", n);
        funB(n-1);
    }
}

void funB(int n){
    if(n>1){
        printf("%d ",n);
        funA(n/2);
    }
}

int main()
{
    funA(20);
    return 0;
}
#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int *A, int n){
    int i,j,temp, flag=0;
    for(i=0; i<n-1; i++){
        flag=0;
        for(j=0; j<n-i-1; j++){
            if(A[j] > A[j+1]){
                // swap(&A[j], &A[j+1]);
                // OR
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int A[] = {7,9,4,1,8,98,3,12,37,22};
    BubbleSort(A,10);

    for(int i=0; i<10; i++){
        printf("%d ",A[i]);
    }
    return 0;
}
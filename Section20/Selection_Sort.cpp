#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int A[], int n){
    int i,j,k;
    for(i=0; i<n-1; i++){
        for(j=k=i; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}


int main()
{
    int A[] = {7,9,4,1,8,98,3,12,37,22};
    int n = sizeof(A)/sizeof(A[0]);
    SelectionSort(A,n);
    for(int i=0; i<10; i++){
        printf("%d ",A[i]);
    }
    return 0;
}
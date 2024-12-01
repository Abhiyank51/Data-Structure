#include<iostream>
using namespace std;


void InsertionSort(int A[], int n){
    int i,j,x;
    for(int i = 1; i<n; i++){
        j = i-1;
        x = A[i];
        while(j>-1 && A[j] > x){
            A[j+1] = A[j];   // shifting element 
            j--;
        }
        A[j+1] = x;
    }
}


int main()
{
    int A[] = {0,9,4,1,8,98,3,12,37,22};
    int n = sizeof(A)/sizeof(A[0]);
    InsertionSort(A,n);
    for(int i=0; i<10; i++){
        printf("%d ",A[i]);
    }
    return 0;
}
#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
           i++;
        } while (A[i]<=pivot);
        do
        {
            j--;
        } while (A[j]>pivot);
        if(i<j){
            swap(&A[i], &A[j]);
        }
    } while (i<j);
    swap(&A[l], &A[j]);
    return j;
}


void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j = partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

int main()
{
    int A[] = {7,9,4,1,8,98,3,12,37,22,INT32_MAX};
    int n = sizeof(A)/sizeof(A[0]);
    QuickSort(A,0,n-1);
    for(int i=0; i<10; i++){
        printf("%d ",A[i]);
    }
    return 0;
}
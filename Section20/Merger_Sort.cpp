#include<iostream>
using namespace std;

void Merge(int A[], int l, int mid, int h){
    int i=l,j=mid+1,k=l;
    int B[100];

    while(i<=mid && j<=h){
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(;i<=mid;i++)
        B[k++] = A[i];
    for(;j<=h;j++)
        B[k++] = A[j];
    for(int i=l; i<=h; i++)
        A[i] =B[i];
}


// Iterative version of merge sort 
void IMergeSort(int A[], int n){
    int p,l,h,mid,i;
    for(p=2; p<=n; p=p*2){
        for(i=0; i+p-1<n; i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n){
        Merge(A,0,p/2-1,n);
    }
}


// Recursive merge sort 
void RMergeSort(int A[], int l, int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        RMergeSort(A,l,mid);
        RMergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}
int main()
{
    int A[] = {0,9,4,1,8,98,3,12,37,22};
    int n = sizeof(A)/sizeof(A[0]);
    // IMergeSort(A,n);
    RMergeSort(A,0,n-1);
    for(int i=0; i<10; i++){
        printf("%d ",A[i]);
    }
    return 0;
}
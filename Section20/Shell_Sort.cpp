#include<iostream>
using namespace std;

void ShellSort(int A[], int n){
    int gap,i,j,temp;
    for(gap=n/2; gap>=1; gap/=2){
        for(i=gap; i<n; i++){
            temp = A[i];
            j = i-gap;
            while(j>=0 && A[j]>temp){
                A[j+gap] = A[j];
                j=j-gap;
            }
            A[j+gap] = temp;
        }
    }
}

int main()
{
    int A[] = {7,9,4,1,8,98,3,12,37,22};
    ShellSort(A,10);
    for(int i=0; i<10; i++){
        printf("%d ",A[i]);
    }
    return 0;
}
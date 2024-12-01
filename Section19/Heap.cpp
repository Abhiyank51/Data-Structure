#include<iostream>
using namespace std;

// Insert element in Heap
void Insert(int A[], int n){
    int i=n, temp;
    temp=A[i];

    while(i>1 && temp>A[i/2]){
        A[i] = A[i/2];
        i=i/2;
    }
    A[i] = temp;
}


// Delete element in Heap  
// n is size of heap
int Delete(int A[], int n){
    int i,j,x,temp,val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i=1; j=i*2;

    while(j<n-1){
        if(A[j+1]>A[j]){
            j=j+1;
        }
        if(A[i] < A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i=j;
            j=2*j;
        }
        else{
            break;
        }
    }
    return val;   //deleted value
}

int main()
{
    // array size is 8 and want have only 7 elem in heap 
    // int H[] = {0,2,5,8,9,4,10,7};   // 0th index is skipped by set it as 0  
    // // Insert(H,2);  // 2 is index here
    // // Insert(H,3); 
    // // Insert(H,4); 
    // // Insert(H,5); 

    // // insert by loop
    // for(int i=2; i<=7; i++){       // see using debugger
    //     Insert(H,i);
    // }


    // Create max heap
    int H[] = {0,10,20,30,25,5,40,35};
    // max heap order -- 40,25,35,10,5,20,30

    for(int i=2; i<=7; i++){       
        Insert(H,i);
    }


    // printf("Deleted value is %d\n", Delete(H,7));

    // delete elem in loop
    // HEAP SORT
    for(int i=7; i>1; i--){
        Delete(H,i);    // elements are sorted 
    }

    for(int i=1; i<=7; i++){
        printf("%d ", H[i]);
    }
    return 0;
}
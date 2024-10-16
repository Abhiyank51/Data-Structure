#include<iostream>
using namespace std;


//  By using square brackets, as when we use [] them they only justify to array not to others but 
// when we use * they should be used for any type not only bind up with array.

// void fun(int A[], int n){
// void fun(int *A, int n){
//     // cout<<sizeof(A)/sizeof(int)<<endl;
    
//     for (int i = 0; i < 5; i++)
//     {
//         cout<<A[i]<<endl;
//     }

//     A[0] = 15;   // value will change as it is a pointer whether it is a * or a []
// }

int * fun(int size){
    int *p;
    p = new int[size];   // this array created in heap

    for (int i = 0; i < size; i++)
    {
        p[i]= i+1;
        return p;
    }
    
}
int main()
{
    int *ptr, sz=5;
    ptr = fun(sz);

    for (int i = 0; i < sz; i++)
    {
        cout<<ptr[i]<<endl;
    }

    // old
    int A[] = {2,4,6,7,8};
    // int n = 5;

    // fun(A,5);

    
    for(int x:A){
        cout<<x<<" ";
    }
    return 0;
}
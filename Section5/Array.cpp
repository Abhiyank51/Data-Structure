#include<iostream>
#include<stdlib.h>
using namespace std;
// int main()
// {
//     // ways to initialize an array.
//     int A[5];
//     // int B[5] = {1,2,3,4,5};
//     // int C[10] = {2,4,6};   // rest of the places filled with 0
//     // int D[5] = {0};   //all filled with 0
//     // int E[] = {1,2,3,4,5,6};

//     for (int i = 0; i < 5; i++)
//     {
//         printf("%u \n", &A[i]);   // print address of locations of array placed
//     }
    
//     return 0;
// }



// Static vs dynamic array 

// int main()
// {
//     // static array 
//     int A[5] = {1,2,3,4,5};

//     // dynamic array 
//     int *p;  // p is a pointer in stack that points to array in heap which is a dynamic array

//     p=(int *)malloc(5*sizeof(int));  // this will create an array in heap 
//     p[0] = 3;
//     p[1] = 5;
//     p[2] = 7;
//     p[3] = 8;
//     p[4] = 9;

//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", A[i]);
//     }

//     printf("\n");

//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", p[i]);
//     }
//     return 0;
// }


// increase array size 

int main()
{
    int *p, *q;

    p = (int *)malloc(5*sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    // for make a large array create a new array with new pointer q
    q = (int *)malloc(10*sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    free(p);
    p=q;  // now p pointer pointed to q array 
    q = NULL; //set q to null so it does not point array of size 10 only p pointed it.


    // printf("Elements in q: ");
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", q[i]);
    // }

    // printf("\n");
    
    printf("Elements in p: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    
    return 0;
}


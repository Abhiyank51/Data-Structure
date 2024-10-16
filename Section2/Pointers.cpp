#include<iostream>
#include <stdio.h>
#include <stdlib.h>  // for malloc function usage 
using namespace std;


// all the variables that are assigned a value should be always store in satck memory
// int main()
// {
//     int a = 10;

//     // declare and then assign pointer 
//     int *p;
//     p=&a;  // dereferencing
//     cout<<a<<endl;

//     printf("Using pointer %d", *p);
//     return 0;
// }


// Pointer to an array
// int main(){
//     int A[5] = {2,4,6,8,10};
//     int *p;
//     p = A;   // if we give an array name to pointer then we dont need to put & to it.
//     // OR if want to use &
//     // p=&A[0];

//     for (int i = 0; i < 5; i++){
//         cout<<p[i]<<endl;   // in place of A[i] we can use p[i] as P=A here
//     }
// }



// Create an array in heap memory and access by pointer 
// int main(){
//     int *p;  // here p is inside the stack
//     // p = (int *)malloc(5*sizeof(int));   // this is inside heap and code for c language 
//     p = new int[5];  // simpler syntax in c++ 

//     // assign values to array inside heap
//     p[0] = 10; p[1] = 3; p[2] = 4; p[3] = 6; p[4] = 5;

//     // print 
//     for (int i = 0; i < 5; i++){
//         cout<<p[i]<<endl;   
//     }

//     // as we use array here so we have to add square brackets to delete the memory assigned
//     delete [] p; // for c++
//     free(p); // for c lang.

//     return 0;
// }

// Remember: when we are dynamically allocating memory like in c++  p = new int[5];  we have to delete it using delete keyword with pointer name 


int main(){
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;


    return 0;
    
}

// size of the pointer is independent of its data size.
#include <iostream>
#include <stdio.h>

using namespace std;

// Define a structure it does not take any memory until it is described with variables.
struct Rectangle
{
    int length;  // 4 bytes
    int bredth;  // 4 bytes
    char x;      // instead of taking only 1 byte the machine assign 4 bytes to it for ease for accessibility but char only use 1 byte for its value.
};


// struct Rectangle
// {
//     int length;
//     int bredth;
// } r1, r2, r3;   // can also declare like this 

// Can also declare the variable outside the main function
// struct Rectangle r1;
// struct Rectangle r1,r2,r3;


int main(){
    // struct Rectangle r1;
    // r1.length=5;
    // r1.bredth=6;

    // OR

    struct Rectangle r1 ={5,6};
    // printf("%d", sizeof(r1));  // in latest compilers integer takes 4 bytes 
    cout<<r1.length<<endl;
    cout<<r1.bredth<<endl;

    r1.length = 34;
    r1.bredth = 43; 

    cout<<r1.length<<endl;
    cout<<r1.bredth<<endl;


    return 0;
}
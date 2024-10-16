#include<iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle{
    int length;
    int bredth;
};

// call by value
// void fun(struct Rectangle r1){

//     r1.length = 20;  // it will change only inside the function not in actual values.
//     cout<<"\nLength "<<r1.length<<endl<<"Bredth "<<r1.bredth<<endl;
// }

// call by address
void fun(struct Rectangle *r1){

    r1->length = 20;  // it will change the value of actual parameter length to 20.
    cout<<"\nLength "<<r1->length<<endl<<"Bredth "<<r1->bredth<<endl;
}

// int main()
// {
//     struct Rectangle r = {10,5};
//     printf("Length : %d\nBredth : %d", r.length, r.bredth);

//     // for call by value
//     // fun(r);

//     // for call by address
//     fun(&r); // change the original length value 
//     printf("Length : %d\nBredth : %d", r.length, r.bredth);
//     return 0;
// }



// New concept 
struct Rect {
    int length;
    int bredth;
};

// create a function that used an object of type Rect 
// using a pointer and it is printing an object in heap
//  and it is initializing lenght and bredth to 15 and 20 and returning the address of that structure.
struct Rect *fun(){
    struct Rect *p;
    p = new Rect;   // in c++
    // p = (struct Rect *)malloc(sizeof(struct Rect));

    p->length=15;
    p->bredth=20;

    return p;
}
int main(){
    struct Rect *ptr = fun();
    cout<<"Length "<<ptr->length<<endl<<"Bredth "<<ptr->bredth<<endl;
    return 0;
}
#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int bredth;
};

int main()
{
    // struct Reactangle r = {10,5};
    // in c++ we dont have a need to write struct on declaration it is not mendatory but in c we have to write it 
    // Rectangle r = {10,5};
    // //  normale access
    // cout<<r.length<<endl;
    // cout<<r.bredth<<endl;

    // //  using pointer
    // Rectangle *p=&r;
    // cout<<p->length<<endl;
    // cout<<p->bredth<<endl;

    // p->length = 5;
    // p->bredth = 6;
    // cout<<p->length<<endl;
    // cout<<p->bredth<<endl;

    // create an object of rectangle in heap

    // firstly we need a pointer
    // Rectangle *p;  // in c++
    struct Rectangle *p;  // in c

    // p = new Rectangle;  // in c++ - create a rectangle object in heap

    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));  // dynamic allocartion of rectangle structure in c lang.
    p->length = 15;
    p->bredth = 8;

    cout<<p->length<<endl;
    cout<<p->bredth<<endl;

    return 0;
}
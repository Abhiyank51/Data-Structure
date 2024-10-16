#include<iostream>
using namespace std;

//  program usinf functions also known as modular or procedural programming.

int area(int length, int bredth){
    return length*bredth;
}

int perimeter(int length, int bredth){
    int p;
    p = 2*(length+bredth);
    return p;
}

int main()
{
    int length = 0, bredth = 0;

    printf("Enter length and bredth ");
    cin>>length>>bredth;

    int a  = area(length, bredth);
    int b = perimeter(length, bredth);

    printf("Area = %d\nPerimeter = %d\n", a,b);

    return 0;
}


//  using structure we can write the upper code like this
struct Rectangle{
    int length;
    int bredth;
};

void initialize(struct Rectangle *r, int l, int b){
    r->length=l;
    r->bredth=b;
}

int area(Rectangle r){         //does not need to write struct in c++ but mandatory in c this is mix program.
    return r.length*r.bredth;
}

int perimeter(struct Rectangle r){
    int p;
    p = 2*(r.length+r.bredth);
    return p;
}

int main()
{
    Rectangle r = {0,0};

    int l,b;
    printf("Enter length and bredth ");
    // cin>>r.length>>r.bredth;
    cin>>l>>b;

    initialize(&r, l, b);

    int a  = area(r);
    int b = perimeter(r);

    printf("Area = %d\nPerimeter = %d\n", a,b);

    return 0;
}
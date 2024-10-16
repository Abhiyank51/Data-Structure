#include<iostream>
using namespace std;

class Rectangle{
    public:
    int length;
    int bredth;

    void initialize(int l, int b){
        length=l;
        bredth=b;
    }

    int area(){  
        return length*bredth;
    }

    int perimeter(){
        int p;
        p = 2*(length+bredth);
        return p;
    }
};

int main()
{
    Rectangle r = {0,0};

    int l,b;
    printf("Enter length and bredth ");
    // cin>>r.length>>r.bredth;
    cin>>l>>b;

    r.initialize(l, b);

    int a = r.area();
    int p = r.perimeter();

    printf("Area = %d\nPerimeter = %d\n", a,p);

    return 0;
}


// in structure every member or data type is by default public but in class all are private by default.
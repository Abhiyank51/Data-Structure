#include<iostream>
using namespace std;


//  reference does not consume any memory, it is not a pointer

int main()
{
    int a = 10;
    int &r = a;
    r=45;  //or a=35;  both are same

    int b = 30;
    r=b;// value of b assigned to r so values of a and r bothe are 30
     
    cout<<a<<endl;
    cout<<r<<endl;
    return 0;
}
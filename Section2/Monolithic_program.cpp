#include<iostream>
using namespace std;

//  all program inside the main function only not outside it this is called as monolithic programming.
int main()
{
    int length = 0, bredth = 0;
    printf("Enter length and bredth ");
    cin>>length>>bredth;

    int area = length * bredth;

    int peri = 2*(length+bredth);

    printf("Area = %d\nPerimeter = %d\n", area,peri);
    return 0;
}
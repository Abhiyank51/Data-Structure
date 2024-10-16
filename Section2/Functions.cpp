#include<iostream>
using namespace std;

int add(int a, int b){
    int c;
    c = a+b;
    return c;
}

int main()
{
    int num1=10, num2=5, sum;
    sum = add(num1,num2);
    printf("The sum of %d and %d is %d", num1, num2, sum);
    return 0;
}
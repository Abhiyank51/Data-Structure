#include<iostream>
using namespace std;


//  using recursion
int fact(int n){
    if(n==0){
        return 1;
    }
    else{
        return fact(n-1) * n;
    }
}

// using loop

int Mfact(int n){
    int m = 1;
    for (int i = 1; i<=n; i++)
    {
        m = m*i;
    }
    return m;
}

int main()
{
    int r;
    r = fact(5);
    printf("%d\n", r);

    int s;
    s = Mfact(4);
    printf("%d", s);
    return 0;
}


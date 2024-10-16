#include<iostream>
using namespace std;

int pow(int m, int n){
    if(n==0){
        return 1;
    }
    else{
        return pow(m,n-1)*m;
    }
}

// reduced miltiplication function
int pow1(int m, int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return pow1(m*m, n/2);
    }
    else{
        return m* pow1(m*m, (n-1)/2);
    }

}

int main()
{
    int r;
    r = pow(2,9);
    printf("%d\n",r);

    int s;
    s = pow1(2,9);
    printf("%d",s);
    return 0;
}
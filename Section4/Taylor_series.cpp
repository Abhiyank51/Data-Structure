// #include<iostream>
// using namespace std;

// double e(int x, int n){
//     static double p=1, f=1;
//     double r;
//     if(n==0){
//         return 1;
//     }
//     else{
//         r = e(x,n-1);
//         p=p*x;
//         f=f*n;
//         return r+p/f;
//     }
// }
// int main()
// {
//     printf("%lf \n", e(4,10));
//     return 0;
// }


// Taylor series solution using horners rule to reduce multiplication and time complexity to linear from quadratic

// #include<iostream>
// using namespace std;

// double e(int x, int n){
//     static double s;

//     if(n==0){
//         return s;
//     }
//     else{
//         s = 1+x*s/n;
//         return e(x,n-1);
//     }
// }
// int main()
// {
//     printf("%lf \n", e(1,10));
//     return 0;
// }


// by using loop

#include<iostream>
using namespace std;

double e(int x, int n){
    double s=1;
    double num = 1;
    double den = 1;

    for(int i = 1; i <=n; i++)
    {
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}

int main()
{
    printf("%lf \n", e(1,10));
    return 0;
} 
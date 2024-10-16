#include<iostream>
using namespace std;

// iterative function
int fib(int n){
    int t0=0, t1=1, s=0;
    if(n<=1){
        return n;
    }
    else{
        for (int i = 2; i <=n; i++)
        {
            s = t0+t1;
            t0=t1;
            t1=s;
        }
        return s;
        
    }
    return 0;
}

// recursive function

int rfib(int n){
    if(n<=1){
        return n;
    }
    else{
        return rfib(n-2) + rfib(n-1);
    }
}

// memorization - to reduce no. of calls
int F[10];
int mfib(int n){
    if(n<=1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2]==-1){
            F[n-2] = mfib(n-2);
        }
        if(F[n-1]==-1){
            F[n-1]=mfib(n-1);
        }
        F[n] = F[n-2]+F[n-1];
        return F[n-2]+F[n-1];
    }
}

int main()
{
    // initialize array with -1 suggest a signal that array is empty
    int i;
    for(i = 0; i<10; i++){
        F[i] = -1;
    }
    printf("%d\n", fib(10));   // 10th term is 55.
    printf("%d\n", rfib(10));
    printf("%d\n", mfib(10));

    return 0;
}



#include<iostream>
using namespace std;

// int sum(int n){
//     if(n==0){
//         return 0;
//     }
//     else{
//         return sum(n-1)+n;
//     }
// }
// int main()
// {
//     int r = sum(5);
//     printf("%d", r);
//     return 0;
// }


// using iterations through loop

int sum(int n){
    int i;
    int s = 0;
    for ( i = 1; i <=n; i++)
    {
        s = s+i;
    }
    return s;
}

int main(){
    int r;
    r = sum(5);
    printf("%d ",r);
    return 0;
}
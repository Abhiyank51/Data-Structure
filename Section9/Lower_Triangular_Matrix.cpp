#include<iostream>
using namespace std;

struct Matrix{
    int *A;
    int n;
};


// // set function for row wise 
// void set(struct Matrix *m, int i, int j, int x){
//     if(i>=j){
//         m->A[i*(i-1)/2+j-1] = x;
//     }
// }

// set function for column wise 
void set(struct Matrix *m, int i, int j, int x){
    if(i>=j){
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x;
    }
}

// get function for row major 
// int get(struct Matrix m, int i, int j){
//     if(i>=j){
//         return m.A[i*(i-1)/2+j-1];
//     }
//     else{
//         return 0;
//     }
// }

// get function for column major 
int get(struct Matrix m, int i, int j){
    if(i>=j){
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    }
    else{
        return 0;
    }
}




void Display(struct Matrix m){
    int i, j;
    for(i = 1; i <=m.n; i++){
        for(j = 1; j<=m.n; j++){
            if(i>=j){
                // printf("%d", m.A[i*(i-1)/2+j-1]);
                printf("%d",m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]);
            }
            else{
                printf("0");
            }
        }
        printf("\n");
    }
    
}


int main()
{
    struct Matrix m;
    int i, j, x;
    printf("Enter Dimension ");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n*(m.n+1)/2*sizeof(int));  // made an array and use formula to get size of array that we have to made to store non zero elements 
    // n(n+1)/2  where n is dimension represented by m.n here 
    printf("Enter all elements ");
    for(i=1; i<=m.n; i++){
        for(j=1;j<=m.n;j++){
            scanf("%d",&x);
            set(&m,i,j,x);
        }
    }
    printf("\n\n");
    Display(m);

    return 0;
}
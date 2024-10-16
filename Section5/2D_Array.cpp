#include<iostream>
using namespace std;
int main()
{
    // 1st method
    int A[3][4] = {{1,2,3,4},{2,4,6,8},{3,5,7,9}};  

    // 2nd method
    int *B[3]; // created inside stack 
    int **C; //for 3rd method 

    int i,j;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    

    B[0] = (int *)malloc(4*sizeof(int));
    B[1] = (int *)malloc(4*sizeof(int));
    B[2] = (int *)malloc(4*sizeof(int));

    // it will give garbage value as no value is yet assigned to them.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }

    

    // 3rd method
    C = (int **)malloc(3*sizeof(int *));
    C[0] = (int *)malloc(4*sizeof(int)); 
    C[1] = (int *)malloc(4*sizeof(int)); 
    C[2] = (int *)malloc(4*sizeof(int)); 

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMax(int A[], int n)
{
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max);
        max = A[i];
    }
    return max;
}

void CountSort(int A[], int n)
{
    int i, j, max, *C;

    max = findMax(A, n);
    C = (int *)malloc(sizeof(int) * (max + 1));

    for (i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[A[i]]++;
    }

    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (C[j] > 0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
            j++;
    }
}
int main()
{
    int A[] = {0, 9, 4, 1, 8, 11, 3, 4, 5, 7};
    int n = sizeof(A) / sizeof(A[0]);
    CountSort(A, n);
    for(int i=0; i<10; i++){
        printf("%d ",A[i]);
    }
    return 0;
}
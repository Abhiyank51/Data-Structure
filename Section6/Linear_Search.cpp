#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};


void Display(struct Array arr){
    printf("Elements are\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linearsearch(struct Array arr, int key){
    for (int i = 0; i < arr.length; i++)
    {
        if(arr.A[i] == key){
            return i;
        }
    }
    return -1;
}

int improved_linearsearch(struct Array *arr, int key){
    for (int i = 0; i < arr->length; i++)
    {
        if(arr->A[i] == key){
            // method1 (transposition)
            // swap(&arr->A[i],&arr->A[i-1]);

            // method2 (move to front/head)
            swap(&arr->A[i],&arr->A[0]);

            return i;
        }
    }
}

int main()
{
    struct Array arr = {{2,3,4,5,6}, 10,5};
    // int find = linearsearch(arr, 2);
    Display(arr);
    int find = improved_linearsearch(&arr, 5);
    printf("\nKey is at index %d\n", find);

    Display(arr);  // elements swapped after search 
    return 0;
}
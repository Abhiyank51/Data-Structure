#include<iostream>
#include<stdlib.h>
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

int Delete(struct Array *arr, int index){
    int x = 0;

    // firstly check if index is vaild or not  
    if(index>=0 && index<=arr->length-1){
        x = arr->A[index];
        for (int i = index; i < arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int main(){
    struct Array arr = {{2,3,4,5,6}, 10,5};
    // Append(&arr, 10);
    printf("%d\n", Delete(&arr,4));
    Display(arr);
    return 0;
}
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

void Append(struct Array *arr, int x){
    if(arr->length<arr->size){
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x){
    if(index>=0 && index <= arr->length){
        for (int i = arr->length; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;        
    }
}



// get() function
int Get(struct Array arr, int index){
    if(index>=0 && index<=arr.length){
        return arr.A[index];
    }
    return -1;
}

// set() function
int Set(struct Array *arr, int index, int x){
    if(index>=0 && index<=arr->length){
        arr->A[index] = x;
    }
}

//max() function
int Max(struct Array arr){
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    return max; 
}

// min() function
int Min(struct Array arr){
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if(arr.A[i]<min){
            min = arr.A[i];
        }
    }
    return min;
}

// sum() function
int Sum(struct Array arr){
    int s = 0;
    for (int i = 0; i < arr.length; i++)
    {
        s += arr.A[i];
    }
    return s;
}

// Average()
float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}

// Reverse() array
void Reverse(struct Array *arr){
    int *B;
    int i,j;

    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
    arr->A[i]=B[i];

}

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Reverse2(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}


// Linear search 
int linearsearch(struct Array arr, int key){
    for (int i = 0; i < arr.length; i++)
    {
        if(arr.A[i] == key){
            return i;
        }
    }
    return -1;
}


// Insert an element in sorting position in sorted array 

int insertSort(struct Array *arr, int x){
    int i = arr->length-1;
    if(arr->length==arr->size){
        return 0;
    }
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

// check if an array is sorted or not 
int isSorted(struct Array arr){
    for (int i = 0; i < arr.length-1; i++)
    {
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
        else{
            return 1;
        }
    }
}

void Rearrange_positive_negative(struct Array *arr){
    int i = 0;
    int j = arr->length-1;
    while (i<j){
        while (arr->A[i]<0)
        {
            i++;
        }
        while (arr->A[j]>=0)
        {
            j--;
        }
        if(i<j){
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}


struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j <arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else{
            arr3->A[k++] = arr2->A[j++];
        }
    }

    // copying the remaining leftover elements
    for ( ; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for ( ; j < arr1->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

// UNION
struct Array* Union(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j <arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i]){
            arr3->A[k++] = arr2->A[j++];
        }
        // copy any one equal element anf increment both 
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    // copying the remaining leftover elements
    for ( ; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for ( ; j < arr1->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


// INTERSECTION
struct Array* Intersection(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j <arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            i++;
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        // copy only same elements in array k from i and j 
        else if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// DIFFERENCE 
struct Array* Difference(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j <arr2->length){

        // only elements of first array are copied 
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        // copy any one equal element anf increment both 
        else{
            i++;
            j++;
        }
    }

    // copying the remaining leftover elements
    for ( ; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


// int main(){
//     // struct Array arr = {{12,3,4,5,6}, 10,5};
//     struct Array arr = {{-3,2,-4,8,9,-1,-5,6,7}, 10,5};

//     // for merging arrray 
//     struct Array arr1 = {{2,6,10,15,25},10,5};
//     // struct Array arr2 = {{3,4,7,18,20},10,5};
//     struct Array *arr3;

//     // array for union 
//     struct Array arr4 = {{3,6,7,15,20},10,5};

//     // Merge 
//     // arr3 = Merge(&arr1, &arr2);

//     // Union
//     // No duplicates come in merging
//     // arr3 = Union(&arr1, &arr4);

//     // intersection
//     // arr3 = Intersection(&arr1, &arr4);

//     // Difference 
//     arr3 = Difference(&arr1, &arr4);


//     Display(*arr3);


//     // Display(arr);

//     // printf("\n");
//     // printf("%d\n", Get(arr,2));

//     // Set(&arr,0,15);
//     // Display(arr);
//     // printf("\n");

//     // printf("%d\n",Max(arr));
//     // printf("%d\n",Min(arr));
//     // printf("%d\n",Sum(arr));
//     // printf("%f\n",Avg(arr));
//     // Reverse(&arr);
//     // Display(arr);

//     // printf("\n");


//     // Reverse2(&arr);

//     // insertSort(&arr,1);

//     // printf("%d \n",isSorted(arr));

//     // Rearrange_positive_negative(&arr);
//     // Display(arr);
//     return 0;
// }




// Menu driven program 


int main()
{
    struct Array arr1;
    int ch;
    int x, index;

    printf("Enter Size of Array");
    scanf("%d",&arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length=0;

    do{
    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");


    printf("Enter your choice ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        printf("Enter an element and index ");
        scanf("%d%d",&x,&index);
        Insert(&arr1,index,x);
        break;
    case 2:
        printf("Enter index ");
        scanf("%d", &index);
        printf("Deleted Element is %d\n",x);
        break;
    case 3:
        printf("Enter element to search ");
        scanf("%d", &x);
        index = linearsearch(&arr1,x);
        printf("Element index %d", index);
        break;
    case 4:
        printf("Sum is %d\n", Sum(arr1));
        break;

    case5:
        Display(arr1);
    }
    }
    while(ch<6);
    return 0;
}
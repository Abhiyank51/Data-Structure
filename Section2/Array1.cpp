#include <iostream>

using namespace std;

int main(){
    cout<<"Hello World"<<endl;

    int A[5];  //array declaration of size 5 
    A[0] = 4;
    A[1] = 6;
    A[2] = 3;
    A[3] = 7;
    A[4] = 4;

    cout<<sizeof(A)<<endl;

    for (int i = 0; i < 5; i++)
    {
        cout<<A[i]<<endl;
    }

    printf("%d\n", A[2]);   // for c language we print like this.
    

    // Initialize an array directly
    int B[5] = {2,5,6,4,3};

    printf("%d\n", B[2]);

    // If we initialize an array with a size but have not full
    // elements in it then the rest of empty places already initializes to zero.


    cout<<("Array C")<<endl;
    int C[10]= {1,2,4,5,3,2};

    // for (int i = 0; i < (sizeof(C)/sizeof(A[0])); i++)
    // {
    //     cout<<C[i]<<endl;
    // }

    // access elements by for each loop
    for(int x: C){
        cout<<x<<endl;
    }


    // Take size of array as input from the user 
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the elements: ";
        cin>>arr[i];
    }

    // Print the array elements
    cout << "The array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    return 0;
}
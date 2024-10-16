#include<iostream>
using namespace std;

// The below code follows call by value mechanism
// Any change done in formal parameters does not reflect in actual parameters.

// int add(int a, int b){      // <--- values of num1 and num2 are passed here.
//     // int c;
//     // c = a+b;
//     // return c;

//     // proof of checking
//     a++;
//     cout<<a;  // output is 11
//     return 0;
// }

// int main()
// {
//     int num1=10, num2=5, sum;
//     sum = add(num1,num2);
//     // printf("The sum of %d and %d is %d", num1, num2, sum);
//     // return 0;

//     cout<<endl<<num1;  // output is 10, no change in actual parameter
// }




// Call by address
// void swap(int *x, int*y){   //<--- paramters should be of type pointers
//     int temp;
//     temp = *x;    //dereferncing 
//     *x = *y;      //dereferncing 
//     *y = temp;    //dereferncing 
// }

// int main(){
//     int num1= 10, num2= 25;

//     cout<<"Before swap"<<endl;
//     cout<<"First Number "<<num1<<endl;
//     cout<<"Second Number "<<num2<<endl;

//     swap(&num1, &num2);

//     cout<<"After swap"<<endl;
//     cout<<"First Number "<<num1<<endl;
//     cout<<"Second Number "<<num2<<endl;
// }


// Call by reference 

void swap(int &x, int &y){   //<--- paramters should be of type pointers
    int temp;
    temp = x;    //dereferncing 
    x = y;      //dereferncing 
    y = temp;    //dereferncing 
}

int main(){
    int num1= 10, num2= 25;

    cout<<"Before swap"<<endl;
    cout<<"First Number "<<num1<<endl;
    cout<<"Second Number "<<num2<<endl;

    swap(num1, num2);

    cout<<"After swap"<<endl;
    cout<<"First Number "<<num1<<endl;
    cout<<"Second Number "<<num2<<endl;
}

// Compiler can make two choices in call by reference either make the swap function as inline function
// or make the parameter as pointers 
 
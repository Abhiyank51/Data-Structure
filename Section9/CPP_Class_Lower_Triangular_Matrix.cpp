#include<iostream>
using namespace std;

class Lower_Triangular_Matrix{
    private:
        int *A;
        int n;
    public:
        Lower_Triangular_Matrix(){
            n=2;
            A=new int[2*(2+1)/2];
        }
        Lower_Triangular_Matrix(int n){
            this->n=n;
            A = new int[n*(n+1)/2];
        }
        ~Lower_Triangular_Matrix(){
            delete []A;
        }
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display(); 
        int GetDimension() {return n;}
};

void Lower_Triangular_Matrix::Set(int i, int j, int x){
    if(i>=j){
        A[i*(i-1)/2+j-1] = x;   // formula for row major representation
        // A[n*(j-1)*(j-2)*(j-1)/2+i-j] = x;   // formula for column major representation
    }
}

int Lower_Triangular_Matrix::Get(int i, int j){
    if(i>=j){
        return A[i*(i-1)/2+j-1];
        // return A[n*(j-1)*(j-2)*(j-1)/2+i-j];   // formula for column major representation

    }
    return 0;
}

void Lower_Triangular_Matrix::Display(){
    for (int i = 1; i <=n; i++){
        for (int j = 1; j <=n; j++){
            if(i>=j)
                cout<<A[i*(i-1)/2+j-1]<<" ";  // row major formula 
                // cout<<A[n*(j-1)*(j-2)*(j-1)/2+i-j]<<" ";   // formula for column major representation

            else
                cout<<"0"<<" ";
        }
        cout<<endl;
    }
}
 
int main()
{
    int d;
    cout<<"Enter Dimension ";
    cin>>d;

    Lower_Triangular_Matrix ltm(d);

    int x;
    cout<<"Enter all elements ";
    for(int i=1; i<=d;i++){
        for(int j=1; j<=d; j++){
            cin>>x;
            ltm.Set(i,j,x);
        }
    }
    ltm.Display();

    return 0;
}
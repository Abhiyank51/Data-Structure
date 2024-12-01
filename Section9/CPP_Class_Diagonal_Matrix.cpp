#include<iostream>
using namespace std;

class Diagonal{
    private:
        int *A;
        int n;
    public:
        Diagonal(){
            n=2;
            A=new int[2];
        }
        Diagonal(int n){
            this->n=n;
        }
        ~Diagonal(){
            delete []A;
        }
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
};

void Diagonal::Set(int i, int j, int x){
    if(i==j){
        A[i-1] = x;
    }
}

int Diagonal::Get(int i, int j){
    if(i==j){
        cout<<A[i-1]<<endl;
    }
    cout<<"0"<<endl;
}

void Diagonal::Display(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i==j)
                cout<<A[i];
            else
                cout<<"0";
        }
        cout<<endl;
    }
}

int main()
{
    Diagonal d(4);
    d.Set(1,1,5);
    d.Set(2,2,6);
    d.Set(3,3,7);
    d.Set(4,4,8);

    d.Get(2,1);

    d.Display();
    return 0;
}
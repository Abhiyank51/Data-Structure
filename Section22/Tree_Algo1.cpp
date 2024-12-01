#include <iostream>
#define I INT32_MAX

using namespace std;

int cost[][8]=
       {{I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I}};

int near[8] = {I,I,I,I,I,I,I,I};
int t[2][6];

int main(){
    int i,j,k,u,v,n=7,min=I;

    // by this for loop we get the min cost edge 
    // j = i to achieve upper triangular 
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            if(cost[i][j] < min){
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    // update and initialize near array
    for(i=1; i<=n;i++){
        if(near[i]!=0){
            if(cost[i][u]<cost[i][v]){
                near[i] = u;
            }
            else{
                near[i] = v;
            }
        }
    }

    // repeated process to add rest of the edges 
    for(i=1;i<n-1;i++){
        //scan near array to get which one's code is minimum by taking it's index and the element in index
        min = I;
        for(j=1;j<=n;j++){
            if(near[j]!=0 && cost[j][near[j]]<min){
                k=j;
                min = cost[j][near[j]];
            }
        }

        // got answer
        t[0][i]=k;
        t[1][i]=near[k];
        near[k] = 0;

        // modify near array
        for(j=1; j<=n ;j++){
            if(near[j] !=0 && cost[j][k]<cost[j][near[j]]){
                near[j] = k;
            }
        }
        // print solution
        for(i=0; i<n-1; i++){
            cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
        }
    }

}
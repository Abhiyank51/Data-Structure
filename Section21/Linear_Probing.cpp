#include<iostream>
using namespace std;
#define SIZE 10   // define constant size 10

int customHash(int key){
    return key%SIZE;
}

// function that linearly check and find out next free space -- Linear Probing
int probe(int H[], int key){
    int index = customHash(key);
    int i=0 ;  // increment until free space found 
    while(H[(index+i)%SIZE] !=0){
        i++;
    }
    return (index+i)%SIZE; // this is the free space found 
}


void Insert(int H[], int key){
    int index = customHash(key);

    // check if index is occupied or not then we need another index
    if(H[index]!=0){
        index = probe(H,key);
    }
    H[index]= key;  // insert when free space found 
}

int Search(int H[], int key){
    int index= customHash(key);
    int i = 0;
    while(H[(index+i)%SIZE] != key){
        i++;
    }
    return (index+i)%SIZE;
}

int main()
{
    int HT[10] = {0};  // array of size 10
    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);

    printf("Keu found at index %d\n", Search(HT,35));

    return 0;
}
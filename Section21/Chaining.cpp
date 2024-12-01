#include<iostream>
#include "LinkedList.h"

using namespace std;

// Generate hash code(hash function) needed by Inser function
// we could not name our function as hash because custom libraries also use their function hash internally that can cause issue.
int customHash(int key){
    return key%10;
}

// Insert in hash table 
void Insert(struct Node *H[], int key){
    int index = customHash(key);
    SortedInsert(&H[index],key);
}

int main()
{
    struct Node *HT[10];   // hashtable of size 10
    struct Node *temp;  // for search
    int i;

    // initialize hash table with null
    for ( i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }
    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,42);   // see on debugging 

    temp = Search(HT[customHash(22)],22);

    printf("%d ", temp->data);
    
    return 0;
}
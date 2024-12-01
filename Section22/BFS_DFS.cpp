#include <iostream>
#include "Queue.h"
using namespace std;

// BFS
/*
G - matrix
start = starting vertex
n = dimension of metrix
*/
void BFS(int G[][7], int start, int n)
{
    int i = start, j;

    int visited[7] = {0};

    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

// DFS
void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    int j;

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;

        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}

int main()
{
    // Adjacency Matrix of the graph for which we find DFS, BFS
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    /*
        GRAPH LOOKS LIKE THIS
                        |1|
                      /     \
                     /       \
                    |2|      |3|
                     \        /
                      \      /
                         |4|
                        /   \
                       /     \
                     |5|     |6|
    */

    BFS(G, 4, 7);
    printf("\n");
    DFS(G, 4, 7);
    return 0;
}
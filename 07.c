// bfs program with comments

#include<stdio.h>
#define max 10
#include"queue.h"   // include queue functions (initqueue, enqueue, dequeue, IsQueueEmpty)


// BFS function
void bfs(int a[max][max], int n){
    
    int visited[max] = {0};   // visited array → 0 = not visited, 1 = visited
    int u, v;                 // u = current vertex, v = neighbour vertex

    initqueue();              // reset queue before starting BFS

    u = 0;                    // start BFS from vertex 0 (which means V1)
    visited[u] = 1;           // mark starting vertex as visited
    enqueue(u);               // push starting vertex into queue

    // BFS main loop
    while(!IsQueueEmpty()) {

        u = dequeue();        // remove the front element from queue
        printf("\tV%d", u + 1);  // print it (+1 because indexing starts from 0)

        // scan all possible neighbours of u
        for(v = 0; v < n; v++) {

            // If an edge exists AND neighbour is not yet visited
            if(a[u][v] == 1 && visited[v] == 0) {

                enqueue(v);   // add neighbour to queue for future processing
                visited[v] = 1;  // mark neighbour as visited
            }
        }
    }
}



int main(){
    int a[max][max], i, j, n;

    printf("\nEnter the no. of vertices: ");
    scanf("%d", &n);

    if(n > max || n <= 0){
        printf("Invalid no. of vertices! Max %d vertices are allowed.", max);
        return 0;
    }

    printf("\nEnter graph (Adjacency Matrix Input):\n");

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){

            a[i][j] = 0;   // initialize: assume no edge

            if(i == j){
                // ignore self-loop like V1 → V1
                continue;
            }

            // ask user about edge between vertex (i+1) and (j+1)
            printf("Is there an edge between V%d and V%d? (1 = Yes, 0 = No): ",
                   i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    // print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++){
        printf("\n");
        for(j = 0; j < n; j++){
            printf("\t%d", a[i][j]);
        }
    }

    // BFS Traversal
    printf("\n\nBFS Traversal:\n");
    bfs(a, n);

    return 0;
}

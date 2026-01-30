// bfs program with no comments

#include<stdio.h>
#define max 10
#include"queue.h"

void bfs(int a[max][max], int n,int u){
    int visited[max] = {0};
    int v;
    initqueue();
    visited[u] = 1;
    enqueue(u);
    while(!IsQueueEmpty()){
        u = dequeue(); 
        printf("\tV%d",u+1);
        for(v=0; v<n; v++){
            if(a[u][v] == 1 && visited[v] == 0){ // a[u][v] == 1 this condition is to check is there is any edge between u = current vertex and v = neigbour vertex and visited[v] == 0 this condition is to check is neighbour vertex is visitied or not ) means not.
                enqueue(v);
                visited[v] = 1;
            }
        }
    }
}
int main(){
    int a[max][max], i, j, n, index;

    printf("\nEnter the no. of vertices :");
    scanf("%d",&n);

    if(n>max || n<=0){
        printf("Ivalid no. of vertices! max %d vertices are allowed.",max);
        return 1;
    }
    printf("\nEnter a graph :\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            a[i][j] = 0;
            if(i == j){
                continue; 
            }
            else{
                printf("Is there is an edge between V%d and V%d (1=Yes and 0=No)\n",i+1,j+1);
                scanf("%d",&a[i][j]);
            }
        }
    }
    printf("Adjacency Matrix :\n");
    for(i=0; i<n; i++){
        printf("\n");
        for(j=0; j<n; j++){
            printf("\t%d",a[i][j]);
        }
    }
    printf("\n\nEnter starting vertex index (0 to %d): ", n-1);
    scanf("%d", &index);

    if (index < 0 || index >= n) {
        printf("Invalid start index!\n");
        return 1;
    }

    printf("\nBfs traversal :\n");
    bfs(a,n,index);
    return 0;
}



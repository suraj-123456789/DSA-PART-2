// topological sort

#include<stdio.h>
#define max 10


int main(){
    int a[max][max],indegree[max];
    int queue[max], front = 0, rear = -1;
    int n, i, j, count = 0;

    printf("Enter the no. of vertices :");
    scanf("%d",&n);

    if(n>10 || n<=0){
        printf("\nInvalid no. vertices you can take vertices upto %d ",max);
        return -1;
    }

    printf("\nEnter graph :");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            a[i][j] = 0;
            if(i==j){
                continue;
            }else{
                printf("Is there is an edge between v%d and v%d (1=Yes & 0=No) :",i+1,j+1);
                scanf("%d",&a[i][j]);
            }
        }
    }
    for(i=0; i<n; i++){ // this for loop is to find indegrees of vertices
        indegree[i] = 0;
        for(j=0; j<n; j++){
            if(a[j][i] == 1){
                indegree[i]++;
            }
        }
    }
    for(i=0; i<n; i++){ // Insert all indegree-0 vertices into queue
        if(indegree[i]==0){
            queue[++rear] = i;
        }
    }
    while(front<=rear){
        int u = queue[front++];
        printf("v%d",u+1);
        count++;

        for(j=0; j<n; j++){ // this for is to reduse the indgree of vertex
            if(a[u][j] == 1){
                indegree[j]--;
                if(indegree[j]==0){
                    queue[++rear] = j;
                }
            }
        }
    }
    if(count != n){
        printf("graph contains a cycle , so topological sort is not possible");
        return -1;
    }
    return 0;
}
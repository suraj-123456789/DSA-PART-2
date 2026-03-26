#include<stdio.h>
#define max 10

int main(){
    int a[max][max], indegree[max],
    queue[max], front=0, rear=-1;
    int i, j, n, count=0;

    printf("Enter the no. of vertices:\n");
    scanf("%d",&n);

    if(n>10 || n<=0){
        printf("Invalid No. Of vertices you can only enter vertices upto %d",max);
        return 0;
    }

    printf("Enter Graph :\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            a[i][j]=0;
            printf("Is there is any edge between v%d and v%d (1=yes or 0=no): ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<n; i++){
        indegree[i]=0;
        for(j=0; j<n; j++){
            if(a[j][i]==1){
                indegree[i]++;
            }
        }
    }
    for(i=0; i<n; i++){
        if(indegree[i]==0){
            queue[++rear] = i;
        }
    }
    while(front <= rear){
        int u = queue[front++];
        printf("v%d ",u+1);
        count++;

        for(j=0; j<n; j++){
            if(a[u][j]==1){
                indegree[j]--;
                if(indegree[j]==0){
                    queue[++rear] = j;
                }
            }
        }
    }
    if(count != n){
        printf("Graphs Contains Cycle, So Topological Sort is not possible.");
        return 0;
    }
    return 0;
}

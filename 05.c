// // accepet vertices and edges in Graph stores as an adjecency matrix and count Indegree and Outdegree of vertex
// // done by me

#include<stdio.h>
#define max 10

void countdegrees(int a[max][max], int n){
    int i, j, indegree = 0, outdegree = 0;
    for(i=0; i<n; i++){
        indegree = 0;
        outdegree = 0;
        for(j=0; j<n; j++){
            indegree += a[j][i];
            outdegree += a[i][j];
        }
        printf("\nVertex %d has indegree : %d and outdegree : %d", i+1, indegree, outdegree);
    }
}
int main(){
    int a[max][max], i, j, n;

    printf("Enter the no. of vertices :");
    scanf("%d",&n);

    if(n>10 || n<=0){
        printf("\nInvalid no. vertices you can take vertices upto %d ",max);
        return 0;
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
    printf("Adjacency marix :\n");
    for(i=0; i<n; i++){
        printf("\n");
        for(j=0; j<n; j++){
            printf("\t%d",a[i][j]);
        }
    }
    countdegrees(a, n);
}


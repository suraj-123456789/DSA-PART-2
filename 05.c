// // accepet vertices and edges in Graph stores as an adjecency matrix and count Indegree and Outdegree of vertex
// // done by me

#include<stdio.h>
#define max 10

void countdegrees(int m[max][max], int n){
    int i, j, indegree = 0, outdegree = 0;
    for(i=0; i<n; i++){
        indegree = 0;
        outdegree = 0;
        for(j=0; j<n; j++){
            indegree += m[j][i];
            outdegree += m[i][j];
        }
        printf("\nVertex %d has indegree : %d and outdegree : %d", i+1, indegree, outdegree);
    }
}

int main(){
    int m[max][max], i, j, n;

    printf("\nHow many nodes are there in graph :");
    scanf("%d",&n);

    if(n > max || n <= 0){
        printf("\nInvalid number of node, max allow %d no. of nodes\n",max);
        return 0;
    }

    printf("\nEnter Graph :\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            m[i][j] = 0;
            if(i != j){
                printf("Is there is an egdge between v%d and v%d, (1 = yes) and (0 = no) :",i+1, j+1);
                scanf("%d", &m[i][j]);
            }
        }
    }
    printf("Adjacency marix :\n");
    for(i=0; i<n; i++){
        printf("\n");
        for(j=0; j<n; j++){
            printf("\t%d",m[i][j]);
        }
    }
    countdegrees(m, n);
}


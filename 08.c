#include<stdio.h>
#define max 10
int visited[max] = {0};

void Dfs(int a[max][max], int n,int v){ // v means current vertex
    int w; // w means neigbour vertex
    visited[v] = 1;
    printf("\tv%d",v+1);

    for(w=0; w<n; w++){
        if(a[v][w] == 1 && visited[w] == 0){
            Dfs(a,n,w);
        }
    }
}

int main(){
    int a[max][max],n;
    int i, j, index;
    printf("\nEnter the no. of vertices :");
    scanf("%d",&n);
    
    if(n>max || n<=0){
        printf("Invalid no. of vertices ! max %d no. of vertices are allowed.",max);
        return 1;
    }
    printf("\nEnter a graph:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            a[i][j] = 0;
            if(i==j){
                continue;
            }
            else{
                printf("Is there is an edge between v%d and v%d (1 = Yes and 0 = No) :",i+1,j+1);
                scanf("%d",&a[i][j]);
            }
        }
    }
    printf("\nAdjacency Matrix\n");
    for(i=0; i<n; i++){
        printf("\n");
        for(j=0; j<n; j++){
            printf("\t%d",a[i][j]);
        }
    }
    printf("\n\nEnter starting vertex index (0 to %d): ", n - 1);
    scanf("%d", &index);

    if (index < 0 || index >= n) {
        printf("Invalid start index!\n");
        return 1;
    }

    printf("\nDfs Traversal :\n");
    Dfs(a,n,index);
    return 0;
}







#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* CreateNode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode; 
}
struct node* insert(struct node* root,int value){
    if(root == NULL){
        return CreateNode(value);
    }
    if(value < root->data){
        root->left = insert(root->left,value);
    }
    else if(value > root->data){
        root->right = insert(root->right,value);
    }
    else{
        printf("Duplicate value %d not allowed\n", value);
    }
    return root;
}
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf(" %d",root->data);
        inorder(root->right);
    }
}
int main(){
    int n, value;
    struct node* root = NULL;
    while(1){
        int choice;
        printf("\n------Menue Driven------\n");
        printf("1.Insert.\n");
        printf("2.Display\n");
        printf("3.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter No. Of Nodes: \n");
            scanf("%d",&n);
            printf("Enter Values:\n");
            for(int i=0; i<n; i++){
                scanf("%d",&value);
                root = insert(root,value);
            }
            printf("\nValues Inserted Sucssesfully.\n");
            break;

            case 2:
            if(root == NULL){
                printf("Tree is empty!");
            }
            else{
                printf("Inorder Traversal: \n");
                inorder(root);
            }
            break;

            case 3:
            printf("Exiting Program...\n");
            return 0;

            default:
            printf("Invali Choice! Try Again.");
        }
    }
    return 0;
}
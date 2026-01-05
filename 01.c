// binary tree with menu driven program

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
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
    else if (value > root->data){
        root->right = insert(root->right,value);
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
void preorder(struct node* root){
    if(root != NULL){
        printf(" %d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d",root->data);
    }
}
int main(){
    int n, i, value;
    struct node* root = NULL;
    while(1){
        int choice;
        printf("\n-----MENU-----\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("\nEnter Your Choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the no. node : ");
                scanf("%d",&n);

                printf("Enter the values to insert:\n");
                for(i=0; i<n; i++){
                scanf("%d",&value);
                root = insert(root,value);
            }
            printf("Elements are entered successfully.\n");
            break;

            case 2:
            if(root != NULL){
                printf("Preorder Traversal Of BST:");
                preorder(root);
                printf("\nInorder Traversal Of BST:");
                inorder(root);

                printf("\nPostorder Traversal Of BST:");
                postorder(root);
            }
            else{
                printf("Tree is empty.\n");
            }
            break;

            case 3:
            printf("Exiting the program.....\n");
            return 0;

            default:
                printf("Invalid Choice Try Again!\n");
                break;
        }
    }
    return 0;
}
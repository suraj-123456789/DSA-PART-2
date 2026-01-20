// implemantation of singly linked list 

#include<stdio.h>
#include<stdlib.h>
struct node { // struct means userdefine data type banavto.(struct node he ek data type ahe as like int, float...etc)
    int data;
    struct node *next;
};
int main(){
    struct node *head=0, *newnode, *temp; // declaration of all pointers.
    int choice = 1; 
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node)); // here we creating nodes and malloc return the address of 1st node and that is stored in new node.
        printf("enter data :");
        scanf("%d",&newnode->data);
        newnode->next = 0; // means : newnode chya next madhi 0 takun de.
        if(head == 0){
            head = temp = newnode;
        }
        else{
            temp->next = newnode; // means : temp chya next madhi newnode takun de. itha nodes list madhi convert hoto.
            temp = newnode; // (note : head, newnode, temp he sagle pointer ahe he address store kertat)
        }
        printf("do you want to contineou, if yes(press 1) OR if no(press 0) :");
        scanf("%d",&choice);
    }
    printf("Linked list elements :\n");
    temp = head;
    while(temp != 0){
        printf("%d\n",temp->data);
        temp = temp->next; // temp madhi temp ch next takun de.
    }
    return 0;
}
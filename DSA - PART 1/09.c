// stack implimentation using static memory and performing operation on that stack i.e : push(), pop(), peeK(), display(), isfull(), isempty().

#include<stdio.h>
#define N 10

int stack[N];
int top = -1;

void push()
{
    int data;
    if(top == N-1){
        printf("stack is overflow.(FULL)\n");
    }
    else{
        printf("Enter element to push :");
        scanf("%d",&data);
        top++;
        stack[top] = data;
        printf("%d element pushed into the stack.\n",stack[top]);
    }
}
void pop()
{
    int item = stack[top];
    if(top == -1){
        printf("stack is underflow (EMPTY).\n");
    }
    else{
        printf("pop element is : %d\n",item);
        top--;
    }
}
void peek()
{
    if(top == -1){
        printf("stack is empty.\n");
    }
    else{
        printf("top is :%d\n",stack[top]);
    }
}
void display()
{
    if(top == -1){
        printf("stack is empty.\n");
    }
    else{
        printf("Stack elements from top to bottom:\n");
        for(int i=top; i>=0; i--){
            printf(" %d",stack[i]);;
        }
    }
}
int main()
{
    int choice;
    while(1){
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("exiting program.\n");
                return 0;
            default :
                printf("invalid choice");
        }
    }
    return 0;
}
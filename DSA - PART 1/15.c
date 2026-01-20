// static implementation of queue. 

#include <stdio.h>
#define N 5

int queue[N];
int front = -1, rear = -1;

// Function to insert element
void enqueue(int x) {
    if (rear == N - 1) {
        printf("Queue is Full!\n");
    } 
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } 
    else {
        rear++;
        queue[rear] = x;
    }
}

// Function to delete element
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty!\n");
    } else if (front == rear) {
        printf("Deleted element: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

// Function to see front element
void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Function to display queue
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

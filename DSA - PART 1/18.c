#include <stdio.h>
#define N 5

int deque[N];
int front = -1, rear = -1;

void insertRear(int x) {
    if ((rear + 1) % N == front) {
        printf("Queue is Full!\n");
    }
    else if (front == -1 && rear == -1) { 
        front = rear = 0;
        deque[rear] = x;
    } 
    else {
        rear = (rear + 1) % N;
        deque[rear] = x;
    }
}

void insertFront(int x) {
    if ((front - 1 + N) % N == rear) {
        printf("Queue is Full!\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[front] = x;
    } 
    else {
        front = (front - 1 + N) % N;
        deque[front] = x;
    }
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);




    return 0;
}

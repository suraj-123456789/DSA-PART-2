#include<stdio.h>
#define N 10
int queue[N];
int front = -1;
int rear = -1;

void initqueue(){
    front = rear = -1;
}
int IsQueueEmpty(){
    return (front==-1 || front > rear);
}
int IsQueueFull(){
    return (rear == N-1);
}
void enqueue(int x){
    if(IsQueueFull()){
        printf("Queue is full\n");
        return;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;   
    }
    else{
        queue[++rear] = x;
    }
}
int dequeue(){
    if(IsQueueEmpty()){
        printf("Queue is empty\n");
        return-1;
    }
    else{
        return queue[front++];
    }
}
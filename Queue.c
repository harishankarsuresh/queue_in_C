/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Queue{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue){
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item){
    if(isFull(queue))
    return;
    
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue* queue){
    if(isEmpty(queue))
    return INT_MIN;
    
    int item = queue->array[queue->front];
    queue->front = (queue->front +1)%queue->capacity;
    queue->size = queue->size-1;
    return item;
}

int front(struct Queue* queue){
    if(isEmpty(queue))
    return INT_MIN;
    
    return queue->array[queue->front];
}

int rear(struct Queue* queue){
    if(isEmpty(queue))
    return INT_MIN;
    
    return queue->array[queue->rear];
}

int main()
{
    printf("Hello World");
struct Queue* queue = createQueue(1000);
  
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
  
    printf("%d dequeued from queue\n\n",
           dequeue(queue));
  
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
    return 0;
}

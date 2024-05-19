#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct
{
  int data[MAX_SIZE];
  int front;
  int rear;
} Queue;

// create a new empty queue
Queue *createQueue()
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

// Check if empty
int is_empty(Queue* queue)
{
  return (queue->front == -1 && queue->rear == -1);
}

// Check if full
int is_full(Queue* queue)
{
  return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// enqueue a new data
int enqueue(Queue* queue, int data)
{
  // check if queue is already full... 
  if (is_full(queue))
  {
    return -1;
  }
  // If queue is empty, set front and rear to 0 and add the data
  if (is_empty(queue))
  {
    queue->front = queue->rear = 0;
  }else
  {
    queue->rear = (queue->rear + 1) % MAX_SIZE;
  }
  // actually add the data to the queue
  queue->data[queue->rear] = data;
  return 0;
}

// dequeue
int dequeue(Queue* queue) {
  // removes the front element of the queue and returns it, if the stack is empty then return -1
  if (is_empty(queue))
  {
    return -1;
  }
  int temp = queue->data[queue->front];
  if (queue->front == queue->rear) // if the queue becomes empty after this operation
  {
    queue->front = queue->rear = -1;
  }
  else
  {
    queue->front = (queue->front + 1) % MAX_SIZE;
  }
  return temp;
}

int main()
{
  Queue *myQueue = createQueue();
  // ... Use the queue ...
  enqueue(myQueue, 1234);
  dequeue(myQueue);
  free(myQueue); // Don't forget to free the memory later!
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

// implement from task1.2a but with singly linked lists
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

typedef struct Stack
{
    Queue* q1;
    Queue* q2;
} Stack;

Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Queue* createQueue() 
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
} 
Stack* createStacks() 
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->q1 = createQueue();
    s->q2 = createQueue();
    return s;
}

void enqueue(Queue *q, int data)
{
    
}

// brain
int main() 
{
    Stack* s = createStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s)); //check what happens when its already empty, since it should return NULL or -1 in this case
    return 0;
}
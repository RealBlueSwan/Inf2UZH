#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//The goal of this task is to implement queues in C, using arrays and linked lists.


//create a new global queue

struct Stack{    int data;   struct Stack *next;  };
struct Queue{   struct Stack *top;   };
struct Queue* new() {
    struct Queue *s = (struct Queue*)malloc(sizeof(struct Queue));
    s->top = NULL;
    return s;
};
//check if Stack is empty
bool is_empty(struct Queue *s){
    return s->top == NULL;  
}   

/*enqueue something on the stack, call for Stack *s and some kind of data, int x*/
void enqueue(struct Queue *s, int x){
    struct Stack *newStack = (struct Stack*)malloc(sizeof(struct Stack));
    newStack->data = x;
    newStack->next = s->top;
    s->top = newStack;
}

int dequeue(struct Queue *s)    {
    if is_empty(s) {return -1;}
    struct Stack *temp = s->top;
    int result = temp->data;
    s->top = s->top->next
    return;
}


/*dequue something from the queue*/
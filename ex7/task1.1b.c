#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*NodeConstructor for the exercise, maybe a little confusing at first*/
struct Node {   int data;   struct Node *next; };
struct Stack {  struct Node *top;   };
struct Stack* new() {
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = NULL;
    return s;   };
/*check if the stack is already empty*/
bool is_empty(struct Stack *s){
    return s->top == NULL;  
}
/*tries to push something onto the stack*/
void push(struct Stack *s, int x){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = s->top;
    s->top = new_node;
}

/*tries to pop the top element, if the element is full return -1, else return the element*/
int pop(struct Stack *s){
    if (is_empty(s)){    return -1;  }
    struct Node *temp = s->top;
    int result = temp->data;
    s->top = s->top->next;
    free(temp);
    return result;  
}
/*basic main function with constructor and tests*/
int main() {
    struct Stack *s = new();
    /*add two stacks on top of node*/
    push(s, 10);

    push(s, 5);
    /*empty stacks*/
    while (!is_empty(s)) {
        printf("%d ", pop(s)); 
    } // Output: 5 10 (LIFO order)

    return 0;
}
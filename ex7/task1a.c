#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

/*initialize Stack*/
void new() {
    top = -1;
}

/*check if stack is empty*/
int isEmpty() {
    return top == -1;
}

/*check if stack is full*/
int isFull() {
    return top == MAX_SIZE - 1;
}

/*pushes the int data on top of a stack*/
void push(int data) {
    if (isFull()){
        printf("All Stacks lead to Stack overflow");
        return;
    }
    stack[++top] = data;
}

/*"pop" the topmost element of the stack and return it. If is_empthy == 1 return -1*/
int pop() {
    /* check if stack is empty*/
    if (isEmpty()){  printf("stack overflow"); return -1;  }
    return stack[top--];
}


int main(){
    /*test for a*/
    new();
    push(1);
    push(2);
    printf("%d\n", pop());  // Should print 2
    printf("%d\n", pop());  // Should print 1
    printf("%d\n", pop());  // Should print -1
    return 0;
}
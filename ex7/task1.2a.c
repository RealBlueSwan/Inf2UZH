#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max_Queue_Size = 1000

int Q[Max_Queue_Size];
int head, tail;

void new()  {
    head = tail = 0;
}
//bool empty


//bool enquue returns 1 if op was successful, if queue is full return 0, check if tail->next == head

//int dequeue, check if empty otherwise return data

//int 


// Demo code starting here.
void print_queue() {
    if (is_empty()) {
        printf("The queue is empty.\n");
        return;
    }

    printf("The queue is (from head to tail): ");
    int i;
    for (i = head; i != tail; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", Q[i]);
    }
    printf("\n");
}
//main function with all the sinanigans...
int main() {
    new();
    printf("The initial queue is empty: %d\n", is_empty());
    printf("I now enqueue the values 3, 4 and 2\n");
    enqueue(3);
    enqueue(4);
    enqueue(2);
    print_queue();
    printf("I now dequeue (remove from the head)\n");
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Enqueued value: 10\n");
    enqueue(10);
    print_queue();
    printf("Enqueued value: 20\n");
    enqueue(20);
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    return 0;
}
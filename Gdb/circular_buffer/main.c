/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *buffer;
    int head;
    int tail;
    int max; // Maximum number of elements in the buffer
    int count; // Current number of elements in the buffer
} CircularBuffer;

void cb_init(CircularBuffer *cb, int size) {
    cb->buffer = (int *)malloc(size * sizeof(int));
    cb->max = size;
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

void cb_push(CircularBuffer *cb, int item) {
    if (cb_is_full(cb)) {
        printf("Buffer is full. Cannot add item: %d\n", item);
        return;
    }
    cb->buffer[cb->head] = item;
    cb->head = (cb->head + 1) % cb->max;
    cb->count++;
}

int cb_pop(CircularBuffer *cb) {
    if (cb_is_empty(cb)) {
        printf("Buffer is empty. Cannot remove item.\n");
        return -1; // Or some error code
    }
    int item = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % cb->max;
    cb->count--;
    return item;
}

int cb_is_empty(CircularBuffer *cb) {
    return cb->count == 0;
}

int cb_is_full(CircularBuffer *cb) {
    return cb->count == cb->max;
}

void cb_free(CircularBuffer *cb) {
    free(cb->buffer);
}

int main() {
    CircularBuffer cb;
    cb_init(&cb, 5);

    cb_push(&cb, 1);
    cb_push(&cb, 2);
    cb_push(&cb, 3);
    printf("Popped: %d\n", cb_pop(&cb));
    printf("Popped: %d\n", cb_pop(&cb));

    cb_push(&cb, 4);
    cb_push(&cb, 5);
    cb_push(&cb, 6);
    cb_push(&cb, 7); 
   // cb_push(&cb, 8); // This should fail as the buffer is full

    while (!cb_is_empty(&cb)) {
        printf("Popped: %d\n", cb_pop(&cb));
    }

    cb_free(&cb);
    return 0;
}

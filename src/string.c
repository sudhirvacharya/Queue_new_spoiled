#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 5   // fixed capacity.

typedef struct {
    int buffer[BUFFER_SIZE];
    int head;   // index to write (enqueue)
    int tail;   // index to read (dequeue)
    int count;  // number of elements
} CircularBuffer;

// Initialize buffer
void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Check if full
bool isFull(CircularBuffer *cb) {
    return cb->count == BUFFER_SIZE;
}

// Check if empty
bool isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// Enqueue (add element)
bool enqueue(CircularBuffer *cb, int item) {
    if (isFull(cb)) {
        printf("Buffer full, cannot enqueue %d\n", item);
        return false;
    }
    cb->buffer[cb->head] = item;
    cb->head = (cb->head + 1) % BUFFER_SIZE;  // wrap around
    cb->count++;
    return true;
}

// Dequeue (remove element)
bool dequeue(CircularBuffer *cb, int *item) {
    if (isEmpty(cb)) {
        printf("Buffer empty, cannot dequeue\n");
        return false;
    }
    *item = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;  // wrap around
    cb->count--;
    return true;
}

// Print buffer contents
void printBuffer(CircularBuffer *cb) {
    printf("Buffer contents: ");
    for (int i = 0; i < cb->count; i++) {
        int index = (cb->tail + i) % BUFFER_SIZE;
        printf("%d ", cb->buffer[index]);
    }
    printf("\n");
}

// Demo
int main() {
    CircularBuffer cb;
    initBuffer(&cb);

    enqueue(&cb, 1);
    enqueue(&cb, 2);
    enqueue(&cb, 3);
    printBuffer(&cb);

    int item;
    if (dequeue(&cb, &item)) printf("Dequeued: %d\n", item);
    printBuffer(&cb);

    enqueue(&cb, 4);
    enqueue(&cb, 5);
    enqueue(&cb, 6);
    printBuffer(&cb);

    if (!enqueue(&cb, 7)) {
        printf("Buffer is full, cannot enqueue 7\n");
    }

    while (dequeue(&cb, &item)) {
        printf("Dequeued: %d\n", item);
    }

    if (!dequeue(&cb, &item)) {
        printf("Buffer is empty, cannot dequeue\n");
    }

    return 0;
}

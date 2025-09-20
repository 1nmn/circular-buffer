#include <stdio.h>
#include <assert.h>
#include "circular_buffer.h"

int main(void)
{
    printf("\nCircular Buffer Test\n");

    // Initialize a circular buffer with capacity of 5
    circular_buffer *cb = cb_init(5);
    assert(cb != NULL);
    printf("\nBuffer initialized with capacity: %zu\n", cb->capacity);

    // Push 1 to 5 into the buffer
    printf("\nPushing values 1 to 5 into the buffer\n");
    for (int i = 1; i <= 5; i++)
        if (cb_push(cb, i) != 0)
            printf("Failed to push %d\n", i);

    // Peek at the oldest value
    int val;
    cb_peek(cb, &val);
    printf("\nPeeking at oldest value: %d\n", val);

    // Buffer should be full now
    assert(cb_is_full(cb));
    printf("\nBuffer is full: %s\n", cb_is_full(cb) ? "true" : "false");

    // Push another element, which should overwrite the oldest
    cb_push(cb, 6);
    printf("\nPushed 6, overwriting oldest element\n");

    // Peek at the oldest value
    cb_peek(cb, &val);
    printf("\nPeeking at oldest value: %d\n", val);

    // Pop all elements and print them
    printf("\nPopping elements:\n");
    while (!cb_is_empty(cb))
        if (cb_pop(cb, &val) != 0)
            printf("Failed to pop element\n");
        else
            printf("%d\n", val);

    // Buffer should be empty now
    assert(cb_is_empty(cb));
    printf("\nBuffer is empty: %s\n", cb_is_empty(cb) ? "true" : "false");

    // Peek into empty buffer
    printf("\nFailed to peek: %s\n", cb_peek(cb, &val) == -1 ? "true" : "false");

    // Free the buffer
    cb_free(cb);
    return 0;
}
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
    {
        assert(cb_push(cb, i) == 0);
        printf("Pushed: %d\n", i);
    }

    // Peek at the oldest value
    int val;
    assert(cb_peek(cb, &val) == 0);
    printf("\nPeeking at oldest value: %d\n", val);

    // Buffer should be full now
    assert(cb_is_full(cb));
    printf("\nBuffer is full: %s\n", cb_is_full(cb) ? "true" : "false");

    // Push another element, which should overwrite the oldest
    assert(cb_push(cb, 6) == 0);
    printf("\nPushed 6, overwriting oldest element\n");

    // Peek at the oldest value
    assert(cb_peek(cb, &val) == 0 && val == 2);
    printf("\nPeeking at oldest value: %d\n", val);

    // Pop all elements and print them
    printf("\nPopping elements:\n");
    int expected[] = {2, 3, 4, 5, 6};
    for (int i = 0; i < 5; i++)
    {
        assert(cb_pop(cb, &val) == 0);
        assert(val == expected[i]);
        printf("Popped: %d\n", val);
    }

    // Buffer should be empty now
    assert(cb_is_empty(cb));
    printf("\nBuffer is empty: %s\n", cb_is_empty(cb) ? "true" : "false");

    // Peek into empty buffer
    int peek = cb_peek(cb, &val);
    assert(peek == -1);
    printf("Peek into empty buffer returned: %d\n", peek);

    // Pop from empty buffer
    int pop = cb_pop(cb, &val);
    assert(pop == -1);
    printf("Pop from empty buffer returned: %d\n", pop);



    // Free the buffer
    cb_free(cb);

    printf("\nAll tests passed!\n");
    
    return 0;
}
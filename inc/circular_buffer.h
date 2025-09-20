#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    int *buffer;    // data buffer
    size_t capacity; // max number of elements
    size_t head;     // head index
    size_t tail;     // tail index
    bool full;       // is buffer full

} circular_buffer;

/*
 * Creates and initializes a circular buffer
 * Returns a pointer to the circular buffer structure
 */
circular_buffer *cb_init(size_t capacity);

/*
 * Frees the buffer
 */
void cb_free(circular_buffer *cb);

/*
 * Add an element to the circular buffer
 * If the buffer is full, the oldest element will be overwritten
 * Returns 0 on success, -1 if the buffer is empty
 */
int cb_push(circular_buffer *cb, int val);

/*
 * Remove oldest value into *out
 * Returns 0 on success, -1 if the buffer is empty
 */
int cb_pop(circular_buffer *cb, int *out);

/*
 * Peek at the oldest value without removing it
 * Returns 0 on success, -1 if the buffer is empty
 */
int cb_peek(circular_buffer *cb, int *out);

/*
 * Check if the circular buffer is full/empty
 */
bool cb_is_empty(circular_buffer *cb);
bool cb_is_full(circular_buffer *cb);

#endif